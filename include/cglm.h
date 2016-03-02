#ifndef CGLM_H
#define CGLM_H

/**
 * @struct CGLMmat4
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
typedef struct t_mat4 {
    float a0, a1, a2, a3,
          b0 ,b1, b2, b3,
          c0, c1, c2, c3,
          d0, d1, d2, d3;
} CGLMmat4;


/**
 * @typedef CGLMvec3 struct CGLMvec3
 * @brief represent a 3 dimention vertex.
 */
typedef struct t_vec3 {
    float x, y, z;
} CGLMvec3;


CGLMmat4 cglmPerspective(
    float fovy,
    float aspect,
    float zNear,
    float zFar);
CGLMmat4 cglmOrtho(
    float left,
    float right,
    float bottom,
    float top,
    float zNear,
    float zFar);
CGLMmat4 cglmFrustum(
    float left,
    float right,
    float bottom,
    float top,
    float zNear,
    float zFar);

CGLMmat4 cglmMat4(float num);

CGLMvec3 cglmNormalize(CGLMvec3 vector);

CGLMvec3 cglmCross(
    CGLMvec3 x,
    CGLMvec3 y);

float cglmDot(
    CGLMvec3 a,
    CGLMvec3 b);

CGLMvec3 cglmSubsVec3(
    CGLMvec3 a,
    CGLMvec3 b);

CGLMvec3 cglmAddVec3(
    CGLMvec3 a,
    CGLMvec3 b);

CGLMmat4 cglmMultMat4(
    CGLMmat4 m1,
    CGLMmat4 m2);

CGLMmat4 cglmLookAt(
    CGLMvec3 eye,
    CGLMvec3 center,
    CGLMvec3 up);


float f_sqrt(float number);

/**
 * @fn debugCGLMmat4(CGLMmat4 matrix, char* info)
 * @brief for debugging purpose
 */
void debugmat4(
    CGLMmat4 matrix,
    char* info);

/**
 * @fn debugCGLMvec3(CGLMvec3 v)
 * @brief for debugging purpose
 */

void debugvec3(CGLMvec3 vec);


#endif
