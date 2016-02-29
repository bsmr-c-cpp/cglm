#include "minunit.h"

#include <stdlib.h>
#include <stdio.h>
#include <cglm.h>

int tests_run = 0;

static char* compare_matrix(Mat4 a, Mat4 b)
{
    mu_assert("compare error on a0", a.a0 == b.a0);
    mu_assert("compare error on a1", a.a1 == b.a1);
    mu_assert("compare error on a2", a.a2 == b.a2);
    mu_assert("compare error on a3", a.a3 == b.a3);
    mu_assert("compare error on b0", a.b0 == b.b0);
    mu_assert("compare error on b1", a.b1 == b.b1);
    mu_assert("compare error on b2", a.b2 == b.b2);
    mu_assert("compare error on b3", a.b3 == b.b3);
    mu_assert("compare error on c0", a.c0 == b.c0);
    mu_assert("compare error on c1", a.c1 == b.c1);
    mu_assert("compare error on c2", a.c2 == b.c2);
    mu_assert("compare error on c3", a.c3 == b.c3);
    mu_assert("compare error on d0", a.d0 == b.d0);
    mu_assert("compare error on d1", a.d1 == b.d1);
    mu_assert("compare error on d2", a.d2 == b.d2);
    mu_assert("compare error on d3", a.d3 == b.d3);
    return NULL;
}

static char* test_perspective() {
    mu_assert("no tests", 0 == 1);
    return NULL;
}

static char* test_mat4() {
    Mat4 mat_test1;
    Mat4 mat_test2;

    float diag;
    diag = (float) 1;
    mat_test1 = (Mat4) {
        diag,0,0,0,
        0,diag,0,0,
        0,0,diag,0,
        0,0,0,diag
    };

    mat_test2 = mat4(diag);
    compare_matrix(mat_test1, mat_test2);

    diag = (float) 0;
    mat_test1 = (Mat4) {
        diag,0,0,0,
        0,diag,0,0,
        0,0,diag,0,
        0,0,0,diag
    };

    mat_test2 = mat4(diag);
    compare_matrix(mat_test1, mat_test2);

    diag = (float) 0.4;
    mat_test1 = (Mat4) {
        diag,0,0,0,
        0,diag,0,0,
        0,0,diag,0,
        0,0,0,diag
    };

    mat_test2 = mat4(diag);
    compare_matrix(mat_test1, mat_test2);

    return NULL;
}

static char* test_normalizeVec3() {
    mu_assert("no tests", 0 == 1);
    return NULL;
}


static char* test_crossVec3() {
    mu_assert("no tests", 0 == 1);
    return NULL;
}

static char* test_minusVec3() {
    mu_assert("no tests", 0 == 1);
    return NULL;
}

static char* test_addVec3() {
    mu_assert("no tests", 0 == 1);
    return NULL;
}

static char* test_dotVec3() {
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
        mu_run_test(test_normalizeVec3);
    else if (strcmp(test_name, "crossVec3") == 0)
        mu_run_test(test_crossVec3);
    else if (strcmp(test_name, "minusVec3") == 0)
        mu_run_test(test_minusVec3);
    else if (strcmp(test_name, "addVec3") == 0)
        mu_run_test(test_addVec3);
    else if (strcmp(test_name, "dotVec3") == 0)
        mu_run_test(test_dotVec3);
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
