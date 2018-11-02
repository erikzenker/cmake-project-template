# C++ Cmake Project Template
[![Build Status](https://travis-ci.org/erikzenker/cmake-project-template.svg?branch=master)](https://travis-ci.org/erikzenker/cmake-project-template)
=
This is a template for c++ cmake projects. You can clone or copy it as a foundation for your new 
c++ cmake project. 

* The [master](https://github.com/erikzenker/cmake-project-template/tree/master) branch contains the foundation for all other branches. 
* The [conan](https://github.com/erikzenker/cmake-project-template/tree/conan) branch extends the master by introducing the conan package manager. 

The template is based on the [talk from Mateusz Pusz at the CppCon 2018](https://www.youtube.com/watch?v=S4QSKLXdTtA). It is organized in the following directory tree:
``` 
├── CMakeLists.txt (1)
├── LICENSE (2)
├── README.md (3)
├── src (4)
│   ├── CMakeLists.txt (5)
│   ├── include (6)
│   │   └── MyLibrary (7)
│   │       └── lib_header.h (8)
│   ├── lib_source.cpp (9)
│   └── lib_source.h (10)
└── test (11)
    ├── CMakeLists.txt (12)
    └── tests_source.cpp (13)
```
1. Simple project wrapper and entry point for developement e.g.: CLion project
2. License file (here MIT)
3. Readme file describing the project(currently this file)
4. Contains all source code files of your library
5. Standalone library definition and installation
6. Contains public headers
7. Library namespace
8. Public header file
9. Private source file
10. Private header file
11. Contains all test source code
12. Standalone unit tests defintion
13. Test file

## Create and Install the Package
``` bash
mkdir src/build
cd src/build
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/tmp/
cmake --build . --target install
```

## Compile and Run the Tests Using the Installed Library
``` bash
mkdir test/build/
cd test/build/
cmake .. -DCMAkE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/tmp/
cmake --build . --target MyLibraryTests
ctest -VV
```

## Author
* erikzenker(at)hotmail.com