CGLM
====
[![Build Status](https://travis-ci.org/libgame/cglm.svg?branch=master)](https://travis-ci.org/libgame/cglm)
[![Build status](https://ci.appveyor.com/api/projects/status/0f3gkua2ayap568m/branch/master?svg=true)](https://ci.appveyor.com/project/ssbx/cglm-ff0tb/branch/master)

Basic linear math library written in C.

Most of CGLM code and documentation is a COPY/PASTE C version of the C++ GLM library (http://glm.g-truc.net).

Build
-----
CGLM is build with CMake for all platforms.

You can also use the fake configure script provided to set it up on unix:
```sh
./configure
make
```

Doc
---
Depends on Doxygen:
```sh
make cglm_doc
```
