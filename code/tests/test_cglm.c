#include "minunit.h"

#include <stdlib.h>
#include <stdio.h>
#include <cglm.h>
#include <math.h>

// vesult, mresult and fresult values have been computed the C++ glm library.
int tests_run = 0;

static const int ROUND = 10000;
float roundFloat(float f)
{
    return round(f * ROUND) / ROUND;
}

static CGLMvec3 roundVec3(CGLMvec3 a)
{
    CGLMvec3 ret;
    ret.x = roundFloat(a.x);
    ret.y = roundFloat(a.y);
    ret.z = roundFloat(a.z);
    return ret;
}

static CGLMmat4 roundMat4(CGLMmat4 mat)
{
    CGLMmat4 ret;
    ret.a0 = roundFloat(mat.a0);
    ret.a1 = roundFloat(mat.a1);
    ret.a2 = roundFloat(mat.a2);
    ret.a3 = roundFloat(mat.a3);

    ret.b0 = roundFloat(mat.b0);
    ret.b1 = roundFloat(mat.b1);
    ret.b2 = roundFloat(mat.b2);
    ret.b3 = roundFloat(mat.b3);

    ret.c0 = roundFloat(mat.c0);
    ret.c1 = roundFloat(mat.c1);
    ret.c2 = roundFloat(mat.c2);
    ret.c3 = roundFloat(mat.c3);

    ret.d0 = roundFloat(mat.d0);
    ret.d1 = roundFloat(mat.d1);
    ret.d2 = roundFloat(mat.d2);
    ret.d3 = roundFloat(mat.d3);
    return ret;
}


CGLMvec3 vcompare;
CGLMvec3 vresult;
static char* compare_vec3()
{
    CGLMvec3 vc = roundVec3(vcompare);
    mu_assert("x not match", vc.x == vresult.x);
    mu_assert("y not match", vc.y == vresult.y);
    mu_assert("z not match", vc.z == vresult.z);
    return NULL;
}

CGLMmat4 mcompare;
CGLMmat4 mresult;
static char* compare_matrix()
{
    CGLMmat4 mc = roundMat4(mcompare);
    mu_assert("compare error on a0", mc.a0 == mresult.a0);
    mu_assert("compare error on a1", mc.a1 == mresult.a1);
    mu_assert("compare error on a2", mc.a2 == mresult.a2);
    mu_assert("compare error on a3", mc.a3 == mresult.a3);
    mu_assert("compare error on b0", mc.b0 == mresult.b0);
    mu_assert("compare error on b1", mc.b1 == mresult.b1);
    mu_assert("compare error on b2", mc.b2 == mresult.b2);
    mu_assert("compare error on b3", mc.b3 == mresult.b3);
    mu_assert("compare error on c0", mc.c0 == mresult.c0);
    mu_assert("compare error on c1", mc.c1 == mresult.c1);
    mu_assert("compare error on c2", mc.c2 == mresult.c2);
    mu_assert("compare error on c3", mc.c3 == mresult.c3);
    mu_assert("compare error on d0", mc.d0 == mresult.d0);
    mu_assert("compare error on d1", mc.d1 == mresult.d1);
    mu_assert("compare error on d2", mc.d2 == mresult.d2);
    mu_assert("compare error on d3", mc.d3 == mresult.d3);
    return NULL;
}


static char* test_perspective() {
    mresult = (CGLMmat4) {
        1.344400, 0.000000,  0.000000,  0.000000,
        0.000000, 1.792600,  0.000000,  0.000000,
        0.000000, 0.000000, -1.002000, -1.000000,
        0.000000, 0.000000, -0.200200,  0.000000
    };
    mcompare = cglmPerspective(45, (float) 4/3, 0.1, 100);
    mu_run_test(compare_matrix);

    return NULL;
}

static char* test_ortho() {
    mresult = (CGLMmat4) {
        0.100000,  0.000000,  0.000000, 0.000000,
        0.000000,  0.100000,  0.000000, 0.000000,
        0.000000,  0.000000, -0.020000, 0.000000,
       -0.000000, -0.000000, -1.000000, 1.000000
    };
    mcompare = cglmOrtho(-10,10,-10,10,0,100);
    mu_run_test(compare_matrix);

    return NULL;
}

static char* test_frustum() {
    mresult = (CGLMmat4) {
        0.000000,  0.000000,  0.000000,  0.000000,
        0.000000,  0.000000,  0.000000,  0.000000,
        0.000000,  0.000000, -1.000000, -1.000000,
        0.000000,  0.000000, -0.000000,  0.000000
    };
    mcompare = cglmFrustum(-10,10,-10,10,0,100);
    mu_run_test(compare_matrix);

    return NULL;
}

static char* test_mat4() {

    float diag;
    diag = (float) 1;
    mresult = (CGLMmat4) {
        diag,0,0,0,
        0,diag,0,0,
        0,0,diag,0,
        0,0,0,diag
    };

    mcompare = cglmCGLMmat4(diag);
    mu_run_test(compare_matrix);

    diag = (float) 0;
    mresult = (CGLMmat4) {
        diag,0,0,0,
        0,diag,0,0,
        0,0,diag,0,
        0,0,0,diag
    };

    mcompare = cglmCGLMmat4(diag);
    mu_run_test(compare_matrix);

    diag = (float) 0.4;
    mresult = (CGLMmat4) {
        diag,0,0,0,
        0,diag,0,0,
        0,0,diag,0,
        0,0,0,diag
    };

    mcompare = cglmCGLMmat4(diag);
    mu_run_test(compare_matrix);

    return NULL;
}

static char* test_normalize() {
    CGLMvec3 a;

    // 
    vresult = (CGLMvec3) {1,0,0};
    a = (CGLMvec3) {1,0,0};
    vcompare = cglmNormalize(a);
    mu_run_test(compare_vec3);

    //
    vresult = (CGLMvec3) {0,0,1};

    a = (CGLMvec3) {0,0,2};
    vcompare = cglmNormalize(a);
    mu_run_test(compare_vec3);


    //
    vresult = (CGLMvec3) {0,0,-1};

    a = (CGLMvec3) {0,0,-2};
    vcompare = cglmNormalize(a);
    mu_run_test(compare_vec3);

    return NULL;
}


static char* test_cross() {
    CGLMvec3 a;
    CGLMvec3 b;


    // 
    vresult = (CGLMvec3) {0,0,0};
    a = (CGLMvec3) {1,1,1};
    b = (CGLMvec3) {1,1,1};
    vcompare = cglmCross(a,b);
    mu_run_test(compare_vec3);

    //
    vresult = (CGLMvec3) {0,0,0};
    a = (CGLMvec3) {0,0,0};
    b = (CGLMvec3) {1,1,1};
    vcompare = cglmCross(a,b);
    mu_run_test(compare_vec3);

    //
    vresult = (CGLMvec3) {0,0,0};
    a = (CGLMvec3) {0,0,0};
    b = (CGLMvec3) {1,1,1};
    vcompare = cglmCross(a,b);
    mu_run_test(compare_vec3);

    //
    vresult = (CGLMvec3) {-2.5,-3,-3.5};
    a = (CGLMvec3) {-1,2,-1};
    b = (CGLMvec3) {1,1.5,-2};
    vcompare = cglmCross(a,b);
    mu_run_test(compare_vec3);

    return NULL;
}

static char* test_subsVec3() {
    CGLMvec3 a;
    CGLMvec3 b;

    // 
    vresult = (CGLMvec3) {0,0,0};
    a = (CGLMvec3) {1,1,1};
    b = (CGLMvec3) {1,1,1};
    vcompare = cglmSubsCGLMvec3(a,b);
    mu_run_test(compare_vec3);

    //
    vresult = (CGLMvec3) {-1,-1,-1};
    a = (CGLMvec3) {0,0,0};
    b = (CGLMvec3) {1,1,1};
    vcompare = cglmSubsCGLMvec3(a,b);
    mu_run_test(compare_vec3);

    //
    vresult = (CGLMvec3) {1,1,1};
    a = (CGLMvec3) {1,1,1};
    b = (CGLMvec3) {0,0,0};
    vcompare = cglmSubsCGLMvec3(a,b);
    mu_run_test(compare_vec3);

    //
    vresult = (CGLMvec3) {-2,0.5,1};
    a = (CGLMvec3) {-1,2,-1};
    b = (CGLMvec3) {1,1.5,-2};
    vcompare = cglmSubsCGLMvec3(a,b);
    mu_run_test(compare_vec3);

    return NULL;
}

static char* test_addVec3() {
    CGLMvec3 a;
    CGLMvec3 b;

    //
    vresult = (CGLMvec3) {0,0,0};
    a = (CGLMvec3) {0,0,0};
    b = (CGLMvec3) {0,0,0};
    vcompare = cglmAddCGLMvec3(a,b);
    mu_run_test(compare_vec3);


    //
    vresult = (CGLMvec3) {0,0,0};
    a = (CGLMvec3) {1,1,1};
    b = (CGLMvec3) {-1,-1,-1};
    vcompare = cglmAddCGLMvec3(a,b);
    mu_run_test(compare_vec3);

    //
    vresult = (CGLMvec3) {0.5,-0.82,0.12};
    a = (CGLMvec3) {1.5,-1.32,1.32};
    b = (CGLMvec3) {-1,0.5,-1.2};
    vcompare = cglmAddCGLMvec3(a,b);
    mu_run_test(compare_vec3);

    return NULL;
}

static char* test_dot() {
    CGLMvec3 a;
    CGLMvec3 b;
    float fresult;
    float fcompare;

    //
    fresult = -3.744;
    a = (CGLMvec3) {1.5,-1.32,1.32};
    b = (CGLMvec3) {-1,0.5,-1.2};
    fcompare = roundFloat(cglmDot(a,b));
    mu_assert("compare on dot float", fcompare == fresult);

    //
    fresult = 3;
    a = (CGLMvec3) {1,1,1};
    b = (CGLMvec3) {1,1,1};
    fcompare = roundFloat(cglmDot(a,b));
    mu_assert("compare on dot float", fcompare == fresult);


    //
    fresult = 0;
    a = (CGLMvec3) {0,0,0};
    b = (CGLMvec3) {1,1,1};
    fcompare = roundFloat(cglmDot(a,b));
    mu_assert("compare on dot float", fcompare == fresult);


    //
    fresult = -0.5;
    a = (CGLMvec3) {-1,1.5,-1};
    b = (CGLMvec3) {1,1,1};
    fcompare = roundFloat(cglmDot(a,b));
    mu_assert("compare on dot float", fcompare == fresult);

    //
    fresult = -3.2;
    a = (CGLMvec3) {-1,1.5,-1};
    b = (CGLMvec3) {1,-0.8,1};
    fcompare = roundFloat(cglmDot(a,b));
    mu_assert("compare on dot float", fcompare == fresult);

    return NULL;
}

static char* test_multMat4() {
    mresult = (CGLMmat4) {
        1.446000, -0.991900, -0.924100, -0.922300,
        0.000000, 2.755500, -0.924100, -0.922300,
        1.436900, 0.554500, -5.125900, -5.315500,
        0.287100, 0.110800, 0.103200, 0.103000
    };

    CGLMmat4 mult1 = (CGLMmat4) {
        1.792600, 0.000000,  0.000000,  0.000000,
        0.000000, 1.792600,  0.000000,  0.000000,
        0.000000, 0.000000, -1.002000, -1.000000,
        0.000000, 0.000000, -0.200200,  0.000000};
    CGLMmat4 mult2 = (CGLMmat4) {
        0.600000, -0.411600,  0.686000, 0.000000,
        0.000000,  0.857500,  0.514500, 0.000000,
       -0.800000, -0.308700,  0.514500, 0.000000,
       -0.000000, -0.000000, -5.831000, 1.000000};
    CGLMmat4 mult3 = (CGLMmat4) {
        1.344400, 0.000000,  0.000000,  0.000000,
        0.000000, 1.792600,  0.000000,  0.000000,
        0.000000, 0.000000, -1.002000, -1.000000,
        0.000000, 0.000000, -0.200200,  0.000000};


    mcompare = cglmMultCGLMmat4(cglmMultCGLMmat4(mult1, mult2), mult3);
    mu_run_test(compare_matrix);

    return NULL;
}

static char* test_lookAt() {
    CGLMvec3 a;
    CGLMvec3 b;
    CGLMvec3 c;

    mresult = (CGLMmat4) {
        0.600000, -0.411600,  0.686000, 0.000000,
        0.000000,  0.857500,  0.514500, 0.000000,
       -0.800000, -0.308700,  0.514500, 0.000000,
       -0.000000, -0.000000, -5.831000, 1.000000
    };
    a = (CGLMvec3) {4,3,3};
    b = (CGLMvec3) {0,0,0};
    c = (CGLMvec3) {0,1,0};
    mcompare = cglmLookAt(a,b,c);
    mu_run_test(compare_matrix);
    
    return NULL;
}

static char* cglm_test(char* test_name) {

    if (!test_name) return NULL;


    if (strcmp(test_name, "Perspective") == 0)
        mu_run_test(test_perspective);
    else if (strcmp(test_name, "Mat4") == 0)
        mu_run_test(test_mat4);
    else if (strcmp(test_name, "Normalize") == 0)
        mu_run_test(test_normalize);
    else if (strcmp(test_name, "Cross") == 0)
        mu_run_test(test_cross);
    else if (strcmp(test_name, "SubsVec3") == 0)
        mu_run_test(test_subsVec3);
    else if (strcmp(test_name, "AddVec3") == 0)
        mu_run_test(test_addVec3);
    else if (strcmp(test_name, "Dot") == 0)
        mu_run_test(test_dot);
    else if (strcmp(test_name, "LookAt") == 0)
        mu_run_test(test_lookAt);
    else if (strcmp(test_name, "MultMat4") == 0)
        mu_run_test(test_multMat4);
    else if (strcmp(test_name, "Ortho") == 0)
        mu_run_test(test_ortho);
    else if (strcmp(test_name, "Frustum") == 0)
        mu_run_test(test_frustum);
    return NULL;

}

int main(int argc, char* argv[])
{

    char* result = cglm_test(argv[1]);

    if (result != 0)
        printf("%s\n", result);

    return result != NULL;

}
