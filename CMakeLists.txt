cmake_minimum_required (VERSION 2.6)
project (CGLM)
set (CGLM_VERSION_MAJOR 0)
set (CGLM_VERSION_MINOR 1)

add_library (cglm 
    code/cglm.c
    include/cglm.h)

include_directories (include/)

#
# Tests
#

add_executable (test_cglm
  code/tests/test_cglm.c
  code/cglm.c
  include/cglm.h)
target_link_libraries (test_cglm
    cglm
    -lm)

enable_testing()
add_test (NAME test_perspective   COMMAND test_cglm perspective)
add_test (NAME test_mat4          COMMAND test_cglm mat4)
add_test (NAME test_normalizeVec3 COMMAND test_cglm normalizeVec3)
add_test (NAME test_crossVec3     COMMAND test_cglm crossVec3)
add_test (NAME test_minusVec3     COMMAND test_cglm minusVec3)
add_test (NAME test_addVec3       COMMAND test_cglm addVec3)
add_test (NAME test_dotVec3       COMMAND test_cglm dotVec3)
add_test (NAME test_lookAt        COMMAND test_cglm lookAt)
add_test (NAME test_multMat4      COMMAND test_cglm multMat4)
