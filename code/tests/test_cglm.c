#include "minunit.h"

#include <stdlib.h>
#include <stdio.h>
#include <cglm.h>
#include <math.h>

int tests_run = 0;

static Vec3 roundVec3(Vec3 a)
{
    Vec3 ret;
    ret.x = round(a.x * 1000) / 1000;
    ret.y = round(a.y * 1000) / 1000;
    ret.z = round(a.z * 1000) / 1000;
    return ret;
}

static Mat4 roundMat4(Mat4 mat)
{
    Mat4 ret;
    ret.a0 = round(mat.a0 * 1000) / 1000;
    ret.a1 = round(mat.a1 * 1000) / 1000;
    ret.a2 = round(mat.a2 * 1000) / 1000;
    ret.a3 = round(mat.a3 * 1000) / 1000;

    ret.b0 = round(mat.b0 * 1000) / 1000;
    ret.b1 = round(mat.b1 * 1000) / 1000;
    ret.b2 = round(mat.b2 * 1000) / 1000;
    ret.b3 = round(mat.b3 * 1000) / 1000;

    ret.c0 = round(mat.c0 * 1000) / 1000;
    ret.c1 = round(mat.c1 * 1000) / 1000;
    ret.c2 = round(mat.c2 * 1000) / 1000;
    ret.c3 = round(mat.c3 * 1000) / 1000;

    ret.d0 = round(mat.d0 * 1000) / 1000;
    ret.d1 = round(mat.d1 * 1000) / 1000;
    ret.d2 = round(mat.d2 * 1000) / 1000;
    ret.d3 = round(mat.d3 * 1000) / 1000;
    return ret;
}


Vec3 vcompare;
Vec3 vresult;
static char* compare_vec3()
{
    Vec3 vc = roundVec3(vcompare);
    mu_assert("x not match", vc.x == vresult.x);
    mu_assert("y not match", vc.y == vresult.y);
    mu_assert("z not match", vc.z == vresult.z);
    return NULL;
}

Mat4 mcompare;
Mat4 mresult;
static char* compare_matrix()
{
    Mat4 mc = roundMat4(mcompare);
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
    mu_assert("no tests", 0 == 1);
    return NULL;
}

static char* test_mat4() {

    float diag;
    diag = (float) 1;
    mresult = (Mat4) {
        diag,0,0,0,
        0,diag,0,0,
        0,0,diag,0,
        0,0,0,diag
    };

    mcompare = mat4(diag);
    mu_run_test(compare_matrix);

    diag = (float) 0;
    mresult = (Mat4) {
        diag,0,0,0,
        0,diag,0,0,
        0,0,diag,0,
        0,0,0,diag
    };

    mcompare = mat4(diag);
    mu_run_test(compare_matrix);

    diag = (float) 0.4;
    mresult = (Mat4) {
        diag,0,0,0,
        0,diag,0,0,
        0,0,diag,0,
        0,0,0,diag
    };

    mcompare = mat4(diag);
    mu_run_test(compare_matrix);

    return NULL;
}

static char* test_normalize() {
    Vec3 a;

    // 
    vresult = (Vec3) {1,0,0};
    a = (Vec3) {1,0,0};
    vcompare = normalize(a);
    mu_run_test(compare_vec3);

    //
    vresult = (Vec3) {0,0,1};

    a = (Vec3) {0,0,2};
    vcompare = normalize(a);
    mu_run_test(compare_vec3);


    //
    vresult = (Vec3) {0,0,-1};

    a = (Vec3) {0,0,-2};
    vcompare = normalize(a);
    mu_run_test(compare_vec3);
    /*
    */

    return NULL;
}


static char* test_cross() {
    Vec3 a;
    Vec3 b;


    // 
    vresult = (Vec3) {0,0,0};
    a = (Vec3) {1,1,1};
    b = (Vec3) {1,1,1};
    vcompare = cross(a,b);
    mu_run_test(compare_vec3);

    //
    vresult = (Vec3) {0,0,0};
    a = (Vec3) {0,0,0};
    b = (Vec3) {1,1,1};
    vcompare = cross(a,b);
    mu_run_test(compare_vec3);

    //
    vresult = (Vec3) {0,0,0};
    a = (Vec3) {0,0,0};
    b = (Vec3) {1,1,1};
    vcompare = cross(a,b);
    mu_run_test(compare_vec3);

    //
    vresult = (Vec3) {-2.5,-3,-3.5};
    a = (Vec3) {-1,2,-1};
    b = (Vec3) {1,1.5,-2};
    vcompare = cross(a,b);
    mu_run_test(compare_vec3);

    return NULL;
}

static char* test_subsVec3() {
    Vec3 a;
    Vec3 b;

    // 
    vresult = (Vec3) {0,0,0};
    a = (Vec3) {1,1,1};
    b = (Vec3) {1,1,1};
    vcompare = subsVec3(a,b);
    mu_run_test(compare_vec3);

    //
    vresult = (Vec3) {-1,-1,-1};
    a = (Vec3) {0,0,0};
    b = (Vec3) {1,1,1};
    vcompare = subsVec3(a,b);
    mu_run_test(compare_vec3);

    //
    vresult = (Vec3) {1,1,1};
    a = (Vec3) {1,1,1};
    b = (Vec3) {0,0,0};
    vcompare = subsVec3(a,b);
    mu_run_test(compare_vec3);

    //
    vresult = (Vec3) {-2,0.5,1};
    a = (Vec3) {-1,2,-1};
    b = (Vec3) {1,1.5,-2};
    vcompare = subsVec3(a,b);
    mu_run_test(compare_vec3);

    return NULL;
}

static char* test_addVec3() {
    mu_assert("no tests", 0 == 1);
    return NULL;
}

static char* test_dot() {
    mu_assert("no tests", 0 == 1);
    return NULL;
}

static char* test_lookAt() {
    mu_assert("no tests", 0 == 1);
    return NULL;
}


static char* test_multMat4() {
    mu_assert("no tests", 0 == 1);
    return NULL;
}

static char* cglm_test(char* test_name) {

    if (!test_name) return NULL;


    if (strcmp(test_name, "perspective") == 0)
        mu_run_test(test_lookAt);
    else if (strcmp(test_name, "mat4") == 0)
        mu_run_test(test_mat4);
    else if (strcmp(test_name, "normalizeVec3") == 0)
        mu_run_test(test_normalize);
    else if (strcmp(test_name, "crossVec3") == 0)
        mu_run_test(test_cross);
    else if (strcmp(test_name, "minusVec3") == 0)
        mu_run_test(test_subsVec3);
    else if (strcmp(test_name, "addVec3") == 0)
        mu_run_test(test_addVec3);
    else if (strcmp(test_name, "dotVec3") == 0)
        mu_run_test(test_dot);
    else if (strcmp(test_name, "lookAt") == 0)
        mu_run_test(test_lookAt);
    else if (strcmp(test_name, "multMat4") == 0)
        mu_run_test(test_multMat4);

    return NULL;

}

int main(int argc, char* argv[])
{

    char* result = cglm_test(argv[1]);

    if (result != 0)
        printf("%s\n", result);

    return result != NULL;

}
