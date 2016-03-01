#include "cglm.h"
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

#ifdef CGLM_FAST
#define SQRT f_sqrt
#else
#define SQRT sqrt
#endif


Vec3 normalize(Vec3 vector)
{

    float x = vector.x * vector.x;
    float y = vector.y * vector.y;
    float z = vector.z * vector.z;
    float all = (float) SQRT(x + y + z);

    Vec3 result;
    result.x = vector.x / all;
    result.y = vector.y / all;
    result.z = vector.z / all;

    return result;

}


Vec3 cross(
    Vec3 x,
    Vec3 y)
{

    Vec3 result;
    result.x = x.y * y.z - y.y * x.z;
    result.y = x.z * y.x - y.z * x.x;
    result.z = x.x * y.y - y.x * x.y;

    return result;

}


Vec3 subsVec3(
    Vec3 a,
    Vec3 b)
{

    Vec3 result;
    result.x = a.x + (-b.x);
    result.y = a.y + (-b.y);
    result.z = a.z + (-b.z);

    return result;

}


Vec3 addVec3(
    Vec3 a,
    Vec3 b)
{

    Vec3 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;

    return result;

}


float dot(
    Vec3 a,
    Vec3 b)
{

    return a.x * b.x + a.y * b.y + a.z * b.z;

}


Mat4 lookAt(
    Vec3 eye,
    Vec3 center,
    Vec3 up)
{

    const Vec3 f = normalize(subsVec3(center, eye));
    const Vec3 s = normalize(cross(f, up));
    const Vec3 u = cross(s, f);

    Mat4 result = mat4(1);
    result.a0 = s.x;
    result.b0 = s.y;
    result.c0 = s.z;
                    result.a1 = u.x;
                    result.b1 = u.y;
                    result.c1 = u.z;
                                    result.a2 = -f.x;
                                    result.b2 = -f.y;
                                    result.c2 = -f.z;
    result.d0 = -dot(s, eye);
                    result.d1 = -dot(u, eye);
                                    result.d2 = dot(f, eye);

    return result;

}


Mat4 multMat4(
    Mat4 m2,
    Mat4 m1)
{

    Mat4 result = {
        m1.a0*m2.a0 + m1.a1*m2.b0 + m1.a2*m2.c0 + m1.a3*m2.d0, // = a0
        m1.a0*m2.a1 + m1.a1*m2.b1 + m1.a2*m2.c1 + m1.a3*m2.d1, // = a1
        m1.a0*m2.a2 + m1.a1*m2.b2 + m1.a2*m2.c2 + m1.a3*m2.d2, // = a2
        m1.a0*m2.a3 + m1.a1*m2.b3 + m1.a2*m2.c3 + m1.a3*m2.d3, // = a3

        m1.b0*m2.a0 + m1.b1*m2.b0 + m1.b2*m2.c0 + m1.b3*m2.d0, // = b0
        m1.b0*m2.a1 + m1.b1*m2.b1 + m1.b2*m2.c1 + m1.b3*m2.d1, // = b1
        m1.b0*m2.a2 + m1.b1*m2.b2 + m1.b2*m2.c2 + m1.b3*m2.d2, // = b2
        m1.b0*m2.a3 + m1.b1*m2.b3 + m1.b2*m2.c3 + m1.b3*m2.d3, // = b3

        m1.c0*m2.a0 + m1.c1*m2.b0 + m1.c2*m2.c0 + m1.c3*m2.d0, // = c0
        m1.c0*m2.a1 + m1.c1*m2.b1 + m1.c2*m2.c1 + m1.c3*m2.d1, // = c1
        m1.c0*m2.a2 + m1.c1*m2.b2 + m1.c2*m2.c2 + m1.c3*m2.d2, // = c2
        m1.c0*m2.a3 + m1.c1*m2.b3 + m1.c2*m2.c3 + m1.c3*m2.d3, // = c3

        m1.d0*m2.a0 + m1.d1*m2.b0 + m1.d2*m2.c0 + m1.d3*m2.d0, // = d0
        m1.d0*m2.a1 + m1.d1*m2.b1 + m1.d2*m2.c1 + m1.d3*m2.d1, // = d1
        m1.d0*m2.a2 + m1.d1*m2.b2 + m1.d2*m2.c2 + m1.d3*m2.d2, // = d2
        m1.d0*m2.a3 + m1.d1*m2.b3 + m1.d2*m2.c3 + m1.d3*m2.d3, // = d3
    };

    return result;

}


static const Mat4 empty_matrix_4 = {
    0,0,0,0,
    0,0,0,0,
    0,0,0,0,
    0,0,0,0
};
Mat4 mat4(float num)
{

    Mat4 result = empty_matrix_4;

    result.a0 = num;
                    result.b1 = num;
                                    result.c2 = num;
                                                    result.d3 = num;

    return result;

}


Mat4 perspective(
    float fovy,
    float aspect,
    float zNear,
    float zFar)
{

    float tanHalfFovy = (float) tan(fovy / (float) 2);

    Mat4 result = mat4(0);
    result.a0 =   (float) 1 / (aspect * tanHalfFovy);
    result.b1 =   (float) 1 / (tanHalfFovy);
    result.c2 = - (zFar + zNear) / (zFar - zNear);
    result.c3 = - (float) 1;
    result.d2 = - ((float) 2 * zFar * zNear) / (zFar - zNear);

    return result;

}


Mat4 ortho(
    float left,
    float right,
    float bottom,
    float top,
    float zNear,
    float zFar)
{

    Mat4 result = mat4(1);
    result.a0 =   (float) 2 / (right - left);
    result.b1 =   (float) 2 / (top - bottom);
    result.c2 = - (float) 2 / (zFar - zNear);
    result.d0 = - (right + left) / (right - left);
    result.d1 = - (top + bottom) / (top - bottom);
    result.d2 = - (zFar + zNear) / (zFar - zNear);

    return result;

}

Mat4 frustum(
    float left,
    float right,
    float bottom,
    float top,
    float zNear,
    float zFar)
{

    Mat4 result = mat4(0);
    result.a0 = ((float) 2 * zNear) / (right - left);
    result.b1 = ((float) 2 * zNear)  / (top - bottom);
    result.c0 = (right + left) / (right - left);
    result.c1 = (top + bottom) / (top - bottom);
    result.c2 = - (zFar + zNear) / (zFar - zNear);
    result.c3 = (float) -1;
    result.d2 = - ((float) 2 * zFar * zNear) / (zFar - zNear);

    return result;

}

float f_sqrt(float number)
{

    /*
     * Copyed from https://en.wikipedia.org/wiki/Fast_inverse_square_root
     */

    long  i;
    float x2;
    float y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;

    // evil floating point bit level hacking
    i  = *(long*) &y;

    // what the fuck?
    i  = 0x5f3759df - (i >> 1);

    y  = * (float*) &i;

    // 1st iteration
    y  = y * (threehalfs - (x2 * y * y));

    // 2nd iteration, this can be removed
    // y  = y * (threehalfs - (x2 * y * y));

    return y;

}


void debugMat4(
    Mat4  matrix,
    char* info)
{

    printf("%s: %f %f %f %f\n", info, matrix.a0, matrix.a1, matrix.a2, matrix.a3);
    printf("%s: %f %f %f %f\n", info, matrix.b0, matrix.b1, matrix.b2, matrix.b3);
    printf("%s: %f %f %f %f\n", info, matrix.c0, matrix.c1, matrix.c2, matrix.c3);
    printf("%s: %f %f %f %f\n", info, matrix.d0, matrix.d1, matrix.d2, matrix.d3);

}


void debugVec3(Vec3 vec)
{
    printf("%f %f %f\n", vec.x, vec.y, vec.z);
}

