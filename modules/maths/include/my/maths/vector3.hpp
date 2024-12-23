/*
** EPITECH PROJECT, 2024
** libmy++ - maths
** File description:
** vector3
*/

#ifndef VECTOR3_HPP_
    #define VECTOR3_HPP_

///////////////////////////////////////////////////////////////////////////////
/// \brief Namespace my
///////////////////////////////////////////////////////////////////////////////
namespace my
{

///////////////////////////////////////////////////////////////////////////////
/// \brief Representation of a 3D vector or point.
///////////////////////////////////////////////////////////////////////////////
template <typename T>
class Vector3
{
public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief Properties of the vector
    ///////////////////////////////////////////////////////////////////////////
    union
    {
        struct
        {
            T x;    //<! X component of the vector
            T y;    //<! Y component of the vector
            T z;    //<! Z component of the vector
        };
        T xyz[3];   //<! XYZ component array pointer
    };

public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief Vector3 constant variant
    ///////////////////////////////////////////////////////////////////////////
    static const Vector3<T> zeroVector;     //<! alias for ( 0,  0,  0)
    static const Vector3<T> oneVector;      //<! alias for ( 1,  1,  1)
    static const Vector3<T> upVector;       //<! alias for ( 0,  1,  0)
    static const Vector3<T> downVector;     //<! alias for ( 0, -1,  0)
    static const Vector3<T> forwardVector;  //<! alias for ( 0,  0,  1)
    static const Vector3<T> backwardVector; //<! alias for ( 0,  0, -1)
    static const Vector3<T> leftVector;     //<! alias for (-1,  0,  0)
    static const Vector3<T> rightVector;    //<! alias for ( 1,  0,  0)
    static const Vector3<T> xAxisVector;    //<! alias for ( 1,  0,  0)
    static const Vector3<T> yAxisVector;    //<! alias for ( 0,  1,  0)
    static const Vector3<T> zAxisVector;    //<! alias for ( 0,  0,  1)

public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///////////////////////////////////////////////////////////////////////////
    Vector3(void);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Initialize all the components of the vector to the same value
    ///
    /// \param value The value of the components
    ///////////////////////////////////////////////////////////////////////////
    Vector3(const T value);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Initialize all the components to their respective values
    ///
    /// \param x The component x value
    /// \param y The component y value
    /// \param z The component z value
    ///////////////////////////////////////////////////////////////////////////
    Vector3(const T x, const T y, const T z);
};

} // !my

///////////////////////////////////////////////////////////////////////////////
/// \brief Implementation of the vector3 class
///////////////////////////////////////////////////////////////////////////////
#include <my/maths/vector3.inl>

#endif /* !VECTOR3_HPP_ */
