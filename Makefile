###############################################################################
#
#        ███    ███  █████  ██   ██ ███████ ███████ ██ ██      ███████
#        ████  ████ ██   ██ ██  ██  ██      ██      ██ ██      ██
#        ██ ████ ██ ███████ █████   █████   █████   ██ ██      █████
#        ██  ██  ██ ██   ██ ██  ██  ██      ██      ██ ██      ██
#        ██      ██ ██   ██ ██   ██ ███████ ██      ██ ███████ ███████  v1.0.5
#                           by mallory-scotton
#
###############################################################################

###############################################################################
#                                 CONFIG                                      #
###############################################################################

# Target configuration
TARGET                 := libmy++
TARGET_DIRECTORY       := build/

# Test target configuration
TESTS_TARGET           := unit_tests
TESTS_DETAILS          := details

# The type of target wanted
#     - binary: Generate a binary of the sources
#     - shared: Generated a "shared object" library (.so or .dll)
#     - archive: Generated a static library (.a)
TARGET_TYPE            := shared

# Directory configuration for automatic detection
SOURCES_DIRECTORY      := source/
TESTS_DIRECTORY        := tests/

# Shell used by Make
SHELL                  := /bin/bash

# The compiler to use
GCC                    := g++

# The flags to apply to the compiler
CFLAGS                 := -std=c++17 -Wall -Wextra -Iinclude
DFLAGS                 := -MMD -MF

# The extension of the file (e.g: .cpp, .c)
SOURCE_FILE_EXTENSION  := .cpp

# Metadata of the project such as the version and author
VERSION                := 1.0.0
AUTHOR                 := mallory-scotton
DATE                   :=
HASH                   :=

# Allow the usage of visual effects for the compilation
USE_VISUAL_COMPILER    := 1

###############################################################################
#                                 SOURCES                                     #
###############################################################################

# The source of the project (AUTO can be used to automatically detect files)
SOURCES                := AUTO

# The tests of the project (AUTO can be used to automatically detect files)
TESTS_SOURCES          := AUTO

###############################################################################
#                             MAKEFILE OBJECTS                                #
###############################################################################

# Merge the flags togethers
FLAGS                  := $(CFLAGS) $(DFLAGS)

# Create an utility CC with the compiler + the flags
CC                      = $(GCC) $(FLAGS)

# If the auto option is passed to the sources, automatically find the files
ifeq ($(SOURCES), AUTO)
    SOURCES            := $(shell find '$(SOURCES_DIRECTORY)' \
        -iname '*$(SOURCE_FILE_EXTENSION)' 2> /dev/null)
endif

# If the auto option is passed to the tests, automatically find the files
ifeq ($(TESTS_SOURCES), AUTO)
    TESTS_SOURCES      := $(shell find '$(TESTS_DIRECTORY)' \
        -iname '*.test$(SOURCE_FILE_EXTENSION)' 2> /dev/null)
endif

# Create the objects used later by the compiler
OBJECTS                 = $(SOURCES:$(SOURCE_FILE_EXTENSION)=.o)
TESTS_OBJECTS           = $(TESTS_SOURCES:$(SOURCE_FILE_EXTENSION)=.o)
DEPENDENCIES            = $(SOURCES:$(SOURCE_FILE_EXTENSION)=.d)

# Create an utility alias for library (shared/archive)
STATIC_LIB_EXTENSION    = a
DLL_LIB_EXTENSION       = so

# Specific case for windows, shared object (so) are named dynamic link library
ifeq ($(OS), Windows_NT)
    DLL_LIB_EXTENSION   = dll
endif

###############################################################################
#                            MAKEFILE LOGIC                                   #
###############################################################################

# Color utility
COLOR_RESET             = \033[0m
COLOR_RED               = \033[31m
COLOR_GREEN             = \033[32m
COLOR_YELLOW            = \033[33m
COLOR_BLUE              = \033[34m
COLOR_MAGENTA           = \033[35m
COLOR_CYAN              = \033[36m
COLOR_LIGHT_GRAY        = \033[37m
COLOR_DARK_GRAY         = \033[90m
COLOR_LIGHT_RED         = \033[91m
COLOR_LIGHT_GREEN       = \033[92m
COLOR_LIGHT_YELLOW      = \033[93m
COLOR_LIGHT_BLUE        = \033[94m
COLOR_LIGHT_MAGENTA     = \033[95m
COLOR_LIGHT_CYAN        = \033[96m
COLOR_WHITE             = \033[97m

# Progress bar configuration
PROGRESS_BLANK          = $(COLOR_WHITE)─$(COLOR_RESET)
PROGRESS_FILLED         = $(COLOR_GREEN)─$(COLOR_RESET)

define renderProgressBar
if [ $(USE_VISUAL_COMPILER) -eq 0 ]; then \
	exit; \
else \
	cols=`tput cols`; \
	cols=`echo "scale=2; $$cols - 5" | bc`; \
	completedSteps=`echo "scale=2; $(1)/100*($$cols - 5)" | bc`; \
	completedSteps=`echo $${completedSteps%%.*}`; \
	completedSteps=$${completedSteps:-0}; \
	stepsDone=0; \
	progressBuffer=""; \
	while [ $$stepsDone -lt $$cols ]; do \
		if [ $$stepsDone -lt $$completedSteps ]; then \
			progressBuffer+="$(PROGRESS_FILLED)"; \
		else \
			progressBuffer+="$(PROGRESS_BLANK)"; \
		fi; \
		((stepsDone=$$stepsDone+1)); \
	done; \
	progressBuffer+=" $(1)%%"; \
	printf "$$progressBuffer\r"; \
fi;
endef

###############################################################################
#                              MAKEFILE RULES                                 #
###############################################################################

-include $(DEPENDENCIES)

test:
	@$(call renderProgressBar, 50)
	@printf "\n"

.PHONY: build clean fclean tests tests_run
