cmake_minimum_required(VERSION 3.5)
project(MyLibrary)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(TARGETS)
endif()

# add project code
add_subdirectory(src)

# add unit tests
enable_testing()
add_subdirectory(test)