cmake_minimum_required (VERSION 2.6)
project (CGLM)

include_directories (include/)
add_library (cglm code/cglm.c include/cglm.h)


# Tests
add_executable (test_cglm
  code/tests/test_cglm.c
  code/cglm.c
  include/cglm.h)

target_link_libraries (test_cglm cglm)

if ("${CMAKE_SYSTEM}" MATCHES "Linux")
    target_link_libraries (test_cglm -lm)
endif()

enable_testing()
add_test (NAME test_perspective   COMMAND test_cglm perspective)
add_test (NAME test_mat4          COMMAND test_cglm mat4)
add_test (NAME test_normalize     COMMAND test_cglm normalize)
add_test (NAME test_cross         COMMAND test_cglm cross)
add_test (NAME test_subsVec3      COMMAND test_cglm subsVec3)
add_test (NAME test_addVec3       COMMAND test_cglm addVec3)
add_test (NAME test_dot           COMMAND test_cglm dot)
add_test (NAME test_lookAt        COMMAND test_cglm lookAt)
add_test (NAME test_multMat4      COMMAND test_cglm multMat4)
add_test (NAME test_ortho         COMMAND test_cglm ortho)
