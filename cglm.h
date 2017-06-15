/*
 * MIT License
 *
 * CGLM Copyright (c) 2016 Sebastien Serre <ssbx@sysmo.io>.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * @mainpage
 * All CGLM documentation is included ini the main cglm.h file.
 */

/**
 * @file cglm.h
 * @brief Cglm
 */
#ifndef CGLM_H
#define CGLM_H

#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    /**
     * @brief represent a 4x4 matrix.
     */
    typedef struct { float v[4][4]; } CGLMmat4;

    /**
     * @brief represent a 3 dimention vertex.
     */
    typedef struct {
        GLfloat x, y, z;
    } CGLMvec3;

    /**
     * @brief create a 4x4 matrix
     * @return CLGMmat4
     */
    void
    cglmInitMat4(GLfloat num, CGLMmat4* mat) {
        int i, j;
        for (i=0; i<4; i++) {
            for (j=0; j<4; j++) {
                mat->v[i][j] = 0.0f;
            }
        }
        for (i=0; i<4; i++) {
            mat->v[i][i] = num;
        }
    }

    /**
     * @brief Normalize a vector.
     * @return normalized GLMvec3
     */
    static CGLMvec3
    cglmNormalize(CGLMvec3 vector) {
        GLfloat x = vector.x * vector.x;
        GLfloat y = vector.y * vector.y;
        GLfloat z = vector.z * vector.z;
        GLfloat all = (GLfloat) sqrt(x + y + z);

        CGLMvec3 result;
        result.x = vector.x / all;
        result.y = vector.y / all;
        result.z = vector.z / all;

        return result;
    }

    /**
     * @brief subsctract vector b from vector a.
     * @return the resulting vector
     */
    static CGLMvec3
    cglmSubsVec3(
            CGLMvec3 a,
            CGLMvec3 b) {
        CGLMvec3 result;
        result.x = a.x + (-b.x);
        result.y = a.y + (-b.y);
        result.z = a.z + (-b.z);

        return result;
    }

    /**
     * @brief Cross two vectors
     * @return the resulting vector
     */
    static CGLMvec3
    cglmCross(
            CGLMvec3 x,
            CGLMvec3 y) {
        CGLMvec3 result;
        result.x = x.y * y.z - y.y * x.z;
        result.y = x.z * y.x - y.z * x.x;
        result.z = x.x * y.y - y.x * x.y;

        return result;
    }

    /**
     * @brief compute the dot value of two vectors.
     * @return the dot value
     */
    static GLfloat
    cglmDot(CGLMvec3 a, CGLMvec3 b) {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    /**
     * @brief Creates a matrix for a symetric perspective-view frustum based on
     *        the default handedness.
     * @param fovy Specifies the field of view angle in the y direction.
     *             Expressed in radians.
     * @param aspect Specifies the aspect ratio that determines the field of view
     *               in the x direction. The aspect ratio is the ratio of
     *               x (width) to y (height).
     * @param near Specifies the distance from the viewer to the near clipping
     *             plane (always positive).
     * @param far Specifies the distance from the viewer to the far clipping
     *            plane (always positive).
     * @param mat the matrix
     */
    static void
    cglmPerspective(
            GLfloat fovy,
            GLfloat aspect,
            GLfloat zNear,
            GLfloat zFar,
            CGLMmat4* mat) {
        GLfloat tanHalfFovy = (GLfloat) tan(fovy / (GLfloat) 2);

        cglmInitMat4(0.0f, mat);
        mat->v[0][0] = (GLfloat) 1 / (aspect * tanHalfFovy);
        mat->v[1][1] = (GLfloat) 1 / (tanHalfFovy);
        mat->v[2][2] = -(zFar + zNear) / (zFar - zNear);
        mat->v[2][3] = -(GLfloat) 1;
        mat->v[3][2] = -((GLfloat) 2 * zFar * zNear) / (zFar - zNear);
    }


    /**
     * @brief Creates a matrix for an orthographic parallel viewing volume.
     * @param left
     * @param right
     * @param bottom
     * @param top
     * @param zNear
     * @param zFar
     * @param mat
     */
    static void
    cglmOrtho(
            GLfloat left,
            GLfloat right,
            GLfloat bottom,
            GLfloat top,
            GLfloat zNear,
            GLfloat zFar,
            CGLMmat4* mat) {
        cglmInitMat4(1.0f, mat);
        mat->v[0][0] = (GLfloat) 2 / (right - left);
        mat->v[1][1] = (GLfloat) 2 / (top - bottom);
        mat->v[2][2] = -(GLfloat) 2 / (zFar - zNear);
        mat->v[3][0] = -(right + left) / (right - left);
        mat->v[3][1] = -(top + bottom) / (top - bottom);
        mat->v[3][2] = -(zFar + zNear) / (zFar - zNear);
    }


    /**
     * @brief Creates a frustum matrix.
     * @param left
     * @param right
     * @param bottom
     * @param top
     * @param near
     * @param far
     */
    static void
    cglmFrustum(
            GLfloat left,
            GLfloat right,
            GLfloat bottom,
            GLfloat top,
            GLfloat zNear,
            GLfloat zFar,
            CGLMmat4* mat) {
        cglmInitMat4(0.0f, mat);
        mat->v[0][0] = ((GLfloat) 2 * zNear) / (right - left);
        mat->v[1][1] = ((GLfloat) 2 * zNear) / (top - bottom);
        mat->v[2][0] = (right + left) / (right - left);
        mat->v[2][1] = (top + bottom) / (top - bottom);
        mat->v[2][2] = -(zFar + zNear) / (zFar - zNear);
        mat->v[2][3] = -(GLfloat) 1;
        mat->v[3][2] = -((GLfloat) 2 * zFar * zNear) / (zFar - zNear);
    }


    /**
     * @brief Build a look at view matrix based on the default handedness.
     * @param eye Position of the camera
     * @param center Position where the camera is looking at
     * @param up Normalized up vector, how the camera is oriented.
     *           Typically (0, 0, 1)
     */
    static void
    cglmLookAt(
            CGLMvec3 eye,
            CGLMvec3 center,
            CGLMvec3 up,
            CGLMmat4* mat) {
        const CGLMvec3 f = cglmNormalize(cglmSubsVec3(center, eye));
        const CGLMvec3 s = cglmNormalize(cglmCross(f, up));
        const CGLMvec3 u = cglmCross(s, f);

        cglmInitMat4(1.0f, mat);
        mat->v[0][0] = s.x;
        mat->v[1][0] = s.y;
        mat->v[2][0] = s.z;
        mat->v[0][1] = u.x;
        mat->v[1][1] = u.y;
        mat->v[2][1] = u.z;
        mat->v[0][2] = -f.x;
        mat->v[1][2] = -f.y;
        mat->v[2][2] = -f.z;
        mat->v[3][0] = -cglmDot(s, eye);
        mat->v[3][1] = -cglmDot(u, eye);
        mat->v[3][2] = cglmDot(f, eye);
    }

    /**
     * @brief multiply vector by a scalar
     * @return a vector
     */
    static CGLMvec3
    cglmScalarMultVec3(
            CGLMvec3 v,
            float s) {
        CGLMvec3 result;
        result.x = v.x * s;
        result.y = v.y * s;
        result.z = v.z * s;

        return result;
    }

    /**
     * @brief multiply matrice by a scalar
     * @return a vector
     */
    void
    cglmScalarMultMat4(
            CGLMmat4* __restrict__ mat,
            float s,
            CGLMmat4* __restrict__ res) {
        int i, j;
        for (i=0; i<4; i++) {
            for (j=0; j<4; j++) {
                res->v[i][j] = mat->v[i][j] * s;
            }
        }
    }

    /**
     * @brief add vectors
     * @return a vector
     */
    static CGLMvec3
    cglmAddVec3(
            CGLMvec3 a,
            CGLMvec3 b) {
        CGLMvec3 result;
        result.x = a.x + b.x;
        result.y = a.y + b.y;
        result.z = a.z + b.z;

        return result;
    }

    /**
     * @brief multiply matrix m1 by matrix M2
     * @return a matrix
     */
    void inline
    cglmMultMat4(
            CGLMmat4* __restrict__ m1,
            CGLMmat4* __restrict__ m2,
            CGLMmat4* __restrict__ m3) {
        int i, j, k;

        for (i=0; i<4; i++) {
            for (j=0; j<4; j++) {
                m3->v[i][j] = 0;
                for (k=0; k<4; k++) {
                    m3->v[i][j] += m1->v[k][j] * m2->v[i][k];
                }
            }
        }
    }

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // CGLM_H

