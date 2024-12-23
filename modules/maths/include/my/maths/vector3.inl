/*
** EPITECH PROJECT, 2024
** libmy++ - maths
** File description:
** vector3
*/

///////////////////////////////////////////////////////////////////////////////
/// \brief Dependencies
///////////////////////////////////////////////////////////////////////////////
#include <my/maths/vector3.hpp>

///////////////////////////////////////////////////////////////////////////////
/// \brief Namespace my
///////////////////////////////////////////////////////////////////////////////
namespace my
{

///////////////////////////////////////////////////////////////////////////////
template <typename T> const Vector3<T> Vector3<T>::zeroVector    ( 0,  0,  0);
template <typename T> const Vector3<T> Vector3<T>::oneVector     ( 1,  1,  1);
template <typename T> const Vector3<T> Vector3<T>::upVector      ( 0,  1,  0);
template <typename T> const Vector3<T> Vector3<T>::downVector    ( 0, -1,  0);
template <typename T> const Vector3<T> Vector3<T>::forwardVector ( 0,  0,  1);
template <typename T> const Vector3<T> Vector3<T>::backwardVector( 0,  0, -1);
template <typename T> const Vector3<T> Vector3<T>::leftVector    (-1,  0,  0);
template <typename T> const Vector3<T> Vector3<T>::rightVector   ( 1,  0,  0);
template <typename T> const Vector3<T> Vector3<T>::xAxisVector   ( 1,  0,  0);
template <typename T> const Vector3<T> Vector3<T>::yAxisVector   ( 0,  1,  0);
template <typename T> const Vector3<T> Vector3<T>::zAxisVector   ( 0,  0,  1);

///////////////////////////////////////////////////////////////////////////////
template <typename T>
Vector3<T>::Vector3(void) :
    x(0),
    y(0),
    z(0)
    {};

///////////////////////////////////////////////////////////////////////////////
template <typename T>
Vector3<T>::Vector3(const T value) :
    x(value),
    y(value),
    z(value),
    {};

///////////////////////////////////////////////////////////////////////////////
template <typename T>
Vector3<T>::Vector3(const T x, const T y, const T z) :
    x(x),
    y(y),
    z(z),
    {};

} // !my
