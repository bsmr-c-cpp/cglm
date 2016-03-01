#ifndef CGLM_H
#define CGLM_H

/**
 * @struct Mat4
 * @brief represent a 4x4 matrix.
 *
 *       a0   a1  a2   a3 <br>
 *
 *       b0   b1  b2   b3 <br>
 *
 *       c0   c1  c2   c3 <br>
 *
 *       d0   d1  d2   d3 <br>
 *
 */
typedef struct Mat4 {
    float a0, a1, a2, a3,
          b0 ,b1, b2, b3,
          c0, c1, c2, c3,
          d0, d1, d2, d3;
} Mat4;


/**
 * @typedef Vec3 struct Vec3
 * @brief represent a 3 dimention vertex.
 */
typedef struct Vec3 {
    float x, y, z;
} Vec3;


Mat4 perspective(
    float fovy,
    float aspect,
    float zNear,
    float zFar);
Mat4 ortho(
    float left,
    float right,
    float bottom,
    float top,
    float zNear,
    float zFar);

Mat4 mat4(float num);

Vec3 normalize(Vec3 vector);

Vec3 cross(
    Vec3 x,
    Vec3 y);

float dot(
    Vec3 a,
    Vec3 b);

Vec3 subsVec3(
    Vec3 a,
    Vec3 b);

Vec3 addVec3(
    Vec3 a,
    Vec3 b);

Mat4 multMat4(
    Mat4 m1,
    Mat4 m2);

Mat4 lookAt(
    Vec3 eye,
    Vec3 center,
    Vec3 up);


float f_sqrt(float number);

/**
 * @fn debugMat4(Mat4 matrix, char* info)
 * @brief for debugging purpose
 */
void debugMat4(
    Mat4 matrix,
    char* info);

/**
 * @fn debugVec3(Vec3 v)
 * @brief for debugging purpose
 */

void debugVec3(Vec3 vec);


#endif
