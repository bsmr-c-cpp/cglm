CGLM
====

[![Build Status](https://travis-ci.org/ssbx/cglm.svg?branch=master)](https://travis-ci.org/ssbx/cglm)
[![Appveyor Build Status](https://ci.appveyor.com/api/projects/status/github/ssbx/cglm?branch=master&svg=true)](https://ci.appveyor.com/project/ssbx/cglm)

Basic linear math library written in C.

Most of CGLM code and documentation is a COPY/PASTE C version of the C++ GLM library (http://glm.g-truc.net).

Build
-----
```sh
$ ./configure
$ cd build && make all && make test
```
or use bare CMake on windows/*nix to include it in your project.

Doc
---
Depends on Doxygen:
```sh
 && make cglm_doc
```
