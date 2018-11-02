cmake_minimum_required(VERSION 3.5)
project(MyLibrary VERSION 0.0.1)

# dependencies
find_package(Boost 1.65 REQUIRED)

# library definition
add_library(MyLibrary lib_source.cpp lib_source.h include/MyLibrary/lib_header.h)

install(TARGETS MyLibrary EXPORT MyLibraryTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include)
install(EXPORT MyLibraryTargets
        DESTINATION lib/cmake/MyLibrary
        FILE MyLibraryTargets.cmake
        NAMESPACE MyCompany::)
install(DIRECTORY include/MyLibrary
        DESTINATION include)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(MyLibraryConfigVersion.cmake
        COMPATIBILITY SameMajorVersion)
install(FILES MyLibraryConfig.cmake ${CMAKE_CURRENT_BINARY_DIR}/MyLibraryConfigVersion.cmake
        DESTINATION lib/cmake/MyLibrary)

target_compile_features(MyLibrary PUBLIC cxx_std_17)
target_include_directories(MyLibrary PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)
target_link_libraries(MyLibrary
        PRIVATE Boost::boost)
add_library(MyCompany::MyLibrary ALIAS MyLibrary)
