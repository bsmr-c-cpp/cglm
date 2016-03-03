cmake_minimum_required (VERSION 2.6)
project (CGLM)

include_directories (.)
add_library (cglm cglm.c cglm.h)


# Tests
add_executable (cglm_tests
  cglm_tests.c
  cglm.c
  cglm.h)

target_link_libraries (cglm_tests cglm)

if ("${CMAKE_SYSTEM}" MATCHES "Linux")
    target_link_libraries (cglm_tests -lm)
endif()

enable_testing()
add_test (NAME Mat4          COMMAND cglm_tests Mat4)
add_test (NAME Cross         COMMAND cglm_tests Cross)
add_test (NAME Dot           COMMAND cglm_tests Dot)
add_test (NAME Normalize     COMMAND cglm_tests Normalize)
add_test (NAME SubsVec3      COMMAND cglm_tests SubsVec3)
add_test (NAME AddVec3       COMMAND cglm_tests AddVec3)
add_test (NAME MultMat4      COMMAND cglm_tests MultMat4)
add_test (NAME LookAt        COMMAND cglm_tests LookAt)
add_test (NAME Ortho         COMMAND cglm_tests Ortho)
add_test (NAME Perspective   COMMAND cglm_tests Perspective)
add_test (NAME Frustum       COMMAND cglm_tests Frustum)

# doc
find_package (Doxygen)

if (DOXYGEN_FOUND)

  configure_file (
    ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
    ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)

  add_custom_target (cglm_doc
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen" VERBATIM)

endif (DOXYGEN_FOUND)
