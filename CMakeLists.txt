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
add_test (NAME Perspective   COMMAND test_cglm perspective)
add_test (NAME Mat4          COMMAND test_cglm mat4)
add_test (NAME Normalize     COMMAND test_cglm normalize)
add_test (NAME Cross         COMMAND test_cglm cross)
add_test (NAME SubsVec3      COMMAND test_cglm subsVec3)
add_test (NAME AddVec3       COMMAND test_cglm addVec3)
add_test (NAME Dot           COMMAND test_cglm dot)
add_test (NAME LookAt        COMMAND test_cglm lookAt)
add_test (NAME MultMat4      COMMAND test_cglm multMat4)
add_test (NAME Ortho         COMMAND test_cglm ortho)
add_test (NAME Frustum       COMMAND test_cglm frustum)

# doc
find_package (Doxygen)

if (DOXYGEN_FOUND)

  configure_file (
    ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
    ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)

  add_custom_target (doc
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen" VERBATIM)

endif (DOXYGEN_FOUND)
