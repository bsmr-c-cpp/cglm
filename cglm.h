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

/**
 * @file cglm.h
 * @brief Cglm header
 */
#ifndef CGLM_H
#define CGLM_H

/**
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
 * @brief represent a 3 dimention vertex.
 */
typedef struct t_vec3 {
    float x, y, z;
} CGLMvec3;

/**
 * @brief Creates a matrix for a symetric perspective-view frustum based on the default handedness.
 * @param fovy Specifies the field of view angle in the y direction. Expressed in radians.
 * @param aspect Specifies the aspect ratio that determines the field of view in the x direction. The aspect ratio is the ratio of x (width) to y (height).
 * @param near Specifies the distance from the viewer to the near clipping plane (always positive).
 * @param far Specifies the distance from the viewer to the far clipping plane (always positive).
 */
CGLMmat4 cglmPerspective(
    float fovy,
    float aspect,
    float zNear,
    float zFar);

/**
 * @brief Creates a matrix for an orthographic parallel viewing volume.
 * @param left 
 * @param right 
 * @param bottom 
 * @param top 
 * @param zNear 
 * @param zFar 
 * @return GCLMmat4
 */
CGLMmat4 cglmOrtho(
    float left,
    float right,
    float bottom,
    float top,
    float zNear,
    float zFar);

/**
 * @brief Creates a frustum matrix.
 * @param left 
 * @param right 
 * @param bottom 
 * @param top 
 * @param near 
 * @param far 
 */
CGLMmat4 cglmFrustum(
    float left,
    float right,
    float bottom,
    float top,
    float zNear,
    float zFar);

/**
 * @brief Build a look at view matrix based on the default handedness.
 * @param eye Position of the camera
 * @param center Position where the camera is looking at
 * @param up Normalized up vector, how the camera is oriented. Typically (0, 0, 1)
 */
CGLMmat4 cglmLookAt(
    CGLMvec3 eye,
    CGLMvec3 center,
    CGLMvec3 up);

/**
 * @brief create a 4x4 matrix
 * @return CLGMmat4
 */
CGLMmat4 cglmMat4(float num);

/**
 * @brief Normalize a vector.
 * @return normalized GLMvec3
 */
CGLMvec3 cglmNormalize(CGLMvec3 vector);

/**
 * @brief Cross two vectors
 * @return the resulting vector
 */
CGLMvec3 cglmCross(
    CGLMvec3 x,
    CGLMvec3 y);

/**
 * @brief compute the dot value of two vectors.
 * @return the dot value
 */
float cglmDot(
    CGLMvec3 a,
    CGLMvec3 b);

/**
 * @brief subsctract vector b from vector a.
 * @return the resulting vector
 */
CGLMvec3 cglmSubsVec3(
    CGLMvec3 a,
    CGLMvec3 b);

/**
 * @brief add vectors
 * @return a vector
 */
CGLMvec3 cglmAddVec3(
    CGLMvec3 a,
    CGLMvec3 b);

/**
 * @brief multiply matrix m1 by matrix M2
 * @return a matrix
 */
CGLMmat4 cglmMultMat4(
    CGLMmat4 m1,
    CGLMmat4 m2);


/**
 * @brief for debugging purpose
 */
void debugmat4(CGLMmat4 matrix);

/**
 * @brief for debugging purpose
 */

void debugvec3(CGLMvec3 vec);


#endif
