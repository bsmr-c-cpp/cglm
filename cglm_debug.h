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
 * @file cglm_debug.h
 * @brief Used to debug cglm
 */
#ifndef CGLM_DEBUG_H
#define CGLM_DEBUG_H

#include <stdio.h>
#include <cglm.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    /**
     * @brief Print a GLMmat4 matrix to stdout.
     */
    static void
    debugmat4(CGLMmat4* matrix) {
        int i, j;
        for (i=0; i<4; i++) {
            printf("%f %f %f %f\n", matrix->v[i][0], matrix->v[i][1], matrix->v[i][2], matrix->v[i][3]);
        }
    }

    /**
     * @brief Print a GLMvec3 vector to stdout.
     */
    static void
    debugvec3(CGLMvec3 vec) {
        printf("%f %f %f\n", vec.x, vec.y, vec.z);
    }

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // CGLM_DEBUG_H

