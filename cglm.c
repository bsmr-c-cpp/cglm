/*
 * CGLM Copyright (c) 2016 Sebastien Serre <ssbx@sysmo.io>.
 * 
 * This file is provided to you under the Apache License,
 * Version 2.0 (the "License"); you may not use this file
 * except in compliance with the License.  You may obtain
 * a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
#include "cglm.h"
#include <stdio.h>
#include <stdarg.h>
#include <math.h>


CGLMvec3 cglmNormalize(CGLMvec3 vector)
{

    float x = vector.x * vector.x;
    float y = vector.y * vector.y;
    float z = vector.z * vector.z;
    float all = (float) sqrt(x + y + z);

    CGLMvec3 result;
    result.x = vector.x / all;
    result.y = vector.y / all;
    result.z = vector.z / all;

    return result;

}


CGLMvec3 cglmCross(
    CGLMvec3 x,
    CGLMvec3 y)
{

    CGLMvec3 result;
    result.x = x.y * y.z - y.y * x.z;
    result.y = x.z * y.x - y.z * x.x;
    result.z = x.x * y.y - y.x * x.y;

    return result;

}


CGLMvec3 cglmSubsVec3(
    CGLMvec3 a,
    CGLMvec3 b)
{

    CGLMvec3 result;
    result.x = a.x + (-b.x);
    result.y = a.y + (-b.y);
    result.z = a.z + (-b.z);

    return result;

}


CGLMvec3 cglmAddVec3(
    CGLMvec3 a,
    CGLMvec3 b)
{

    CGLMvec3 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;

    return result;

}


float cglmDot(
    CGLMvec3 a,
    CGLMvec3 b)
{

    return a.x * b.x + a.y * b.y + a.z * b.z;

}


CGLMmat4 cglmLookAt(
    CGLMvec3 eye,
    CGLMvec3 center,
    CGLMvec3 up)
{

    const CGLMvec3 f = cglmNormalize(cglmSubsVec3(center, eye));
    const CGLMvec3 s = cglmNormalize(cglmCross(f, up));
    const CGLMvec3 u = cglmCross(s, f);

    CGLMmat4 result = cglmMat4(1);
    result.a0 = s.x;
    result.b0 = s.y;
    result.c0 = s.z;
                    result.a1 = u.x;
                    result.b1 = u.y;
                    result.c1 = u.z;
                                    result.a2 = -f.x;
                                    result.b2 = -f.y;
                                    result.c2 = -f.z;
    result.d0 = -cglmDot(s, eye);
                    result.d1 = -cglmDot(u, eye);
                                    result.d2 = cglmDot(f, eye);

    return result;

}


CGLMmat4 cglmMultMat4(
    CGLMmat4 m1,
    CGLMmat4 m2)
{

    CGLMmat4 result = {
        m2.a0*m1.a0 + m2.a1*m1.b0 + m2.a2*m1.c0 + m2.a3*m1.d0, // = a0
        m2.a0*m1.a1 + m2.a1*m1.b1 + m2.a2*m1.c1 + m2.a3*m1.d1, // = a1
        m2.a0*m1.a2 + m2.a1*m1.b2 + m2.a2*m1.c2 + m2.a3*m1.d2, // = a2
        m2.a0*m1.a3 + m2.a1*m1.b3 + m2.a2*m1.c3 + m2.a3*m1.d3, // = a3

        m2.b0*m1.a0 + m2.b1*m1.b0 + m2.b2*m1.c0 + m2.b3*m1.d0, // = b0
        m2.b0*m1.a1 + m2.b1*m1.b1 + m2.b2*m1.c1 + m2.b3*m1.d1, // = b1
        m2.b0*m1.a2 + m2.b1*m1.b2 + m2.b2*m1.c2 + m2.b3*m1.d2, // = b2
        m2.b0*m1.a3 + m2.b1*m1.b3 + m2.b2*m1.c3 + m2.b3*m1.d3, // = b3

        m2.c0*m1.a0 + m2.c1*m1.b0 + m2.c2*m1.c0 + m2.c3*m1.d0, // = c0
        m2.c0*m1.a1 + m2.c1*m1.b1 + m2.c2*m1.c1 + m2.c3*m1.d1, // = c1
        m2.c0*m1.a2 + m2.c1*m1.b2 + m2.c2*m1.c2 + m2.c3*m1.d2, // = c2
        m2.c0*m1.a3 + m2.c1*m1.b3 + m2.c2*m1.c3 + m2.c3*m1.d3, // = c3

        m2.d0*m1.a0 + m2.d1*m1.b0 + m2.d2*m1.c0 + m2.d3*m1.d0, // = d0
        m2.d0*m1.a1 + m2.d1*m1.b1 + m2.d2*m1.c1 + m2.d3*m1.d1, // = d1
        m2.d0*m1.a2 + m2.d1*m1.b2 + m2.d2*m1.c2 + m2.d3*m1.d2, // = d2
        m2.d0*m1.a3 + m2.d1*m1.b3 + m2.d2*m1.c3 + m2.d3*m1.d3, // = d3
    };

    return result;

}


static const CGLMmat4 empty_matrix_4 = {
    0,0,0,0,
    0,0,0,0,
    0,0,0,0,
    0,0,0,0
};
CGLMmat4 cglmMat4(float num)
{

    CGLMmat4 result = empty_matrix_4;

    result.a0 = num;
                    result.b1 = num;
                                    result.c2 = num;
                                                    result.d3 = num;

    return result;

}


CGLMmat4 cglmPerspective(
    float fovy,
    float aspect,
    float zNear,
    float zFar)
{

    float tanHalfFovy = (float) tan(fovy / (float) 2);

    CGLMmat4 result = cglmMat4(0);
    result.a0 =   (float) 1 / (aspect * tanHalfFovy);
    result.b1 =   (float) 1 / (tanHalfFovy);
    result.c2 = - (zFar + zNear) / (zFar - zNear);
    result.c3 = - (float) 1;
    result.d2 = - ((float) 2 * zFar * zNear) / (zFar - zNear);

    return result;

}


CGLMmat4 cglmOrtho(
    float left,
    float right,
    float bottom,
    float top,
    float zNear,
    float zFar)
{

    CGLMmat4 result = cglmMat4(1);
    result.a0 =   (float) 2 / (right - left);
    result.b1 =   (float) 2 / (top - bottom);
    result.c2 = - (float) 2 / (zFar - zNear);
    result.d0 = - (right + left) / (right - left);
    result.d1 = - (top + bottom) / (top - bottom);
    result.d2 = - (zFar + zNear) / (zFar - zNear);

    return result;

}

CGLMmat4 cglmFrustum(
    float left,
    float right,
    float bottom,
    float top,
    float zNear,
    float zFar)
{

    CGLMmat4 result = cglmMat4(0);
    result.a0 =   ((float) 2 * zNear) / (right - left);
    result.b1 =   ((float) 2 * zNear)  / (top - bottom);
    result.c0 =   (right + left) / (right - left);
    result.c1 =   (top + bottom) / (top - bottom);
    result.c2 = - (zFar + zNear) / (zFar - zNear);
    result.c3 = - (float) 1;
    result.d2 = - ((float) 2 * zFar * zNear) / (zFar - zNear);

    return result;

}


void debugmat4(
    CGLMmat4  matrix,
    char* info)
{

    printf("%s: %f %f %f %f\n", info, matrix.a0, matrix.a1, matrix.a2, matrix.a3);
    printf("%s: %f %f %f %f\n", info, matrix.b0, matrix.b1, matrix.b2, matrix.b3);
    printf("%s: %f %f %f %f\n", info, matrix.c0, matrix.c1, matrix.c2, matrix.c3);
    printf("%s: %f %f %f %f\n", info, matrix.d0, matrix.d1, matrix.d2, matrix.d3);

}


void debugvec3(CGLMvec3 vec)
{
    printf("%f %f %f\n", vec.x, vec.y, vec.z);
}

