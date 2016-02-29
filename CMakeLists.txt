cmake_minimum_required (VERSION 2.6)
project (CGLM)
include_directories (include/)
add_library (cglm 
    code/cglm.c
    include/cglm.h)
