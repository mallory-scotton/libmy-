///////////////////////////////////////////////////////////////////////////////
/// \brief Dependencies
///////////////////////////////////////////////////////////////////////////////
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my/maths/vector3.hpp>

///////////////////////////////////////////////////////////////////////////////
/// \brief Use the my namespace for easier tests
///////////////////////////////////////////////////////////////////////////////
using namespace my;

Test(vector3_constructors, empty_constructor)
{
    Vector3<float> fv;
    Vector3<int> iv;

    cr_assert_eq(fv.x, 0.f);
    cr_assert_eq(fv.y, 0.f);
    cr_assert_eq(fv.z, 0.f);

    cr_assert_eq(iv.x, 0);
    cr_assert_eq(iv.y, 0);
    cr_assert_eq(iv.z, 0);
}

Test(vector3_constructors, initialize_all_components_together)
{
    Vector3<float> fv(5.f);
    Vector3<int> iv(5);

    cr_assert_eq(fv.x, 5.f);
    cr_assert_eq(fv.y, 5.f);
    cr_assert_eq(fv.z, 5.f);

    cr_assert_eq(iv.x, 5);
    cr_assert_eq(iv.y, 5);
    cr_assert_eq(iv.z, 5);
}

Test(vector3_constructors, initialize_each_component_individually)
{
    Vector3<float> fv(1.f, 2.f, 3.f);
    Vector3<int> iv(1, 2, 3);

    cr_assert_eq(fv.x, 1.f);
    cr_assert_eq(fv.y, 2.f);
    cr_assert_eq(fv.z, 3.f);

    cr_assert_eq(iv.x, 1);
    cr_assert_eq(iv.y, 2);
    cr_assert_eq(iv.z, 3);
}
