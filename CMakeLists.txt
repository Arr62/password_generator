cmake_minimum_required(VERSION 3.15)

project(PasswordGenerator VERSION 1.0)

include(${CMAKE_BINARY_DIR}/Release/generators/conan_toolchain.cmake)

# scr
set(SOURCES
    passwd_generator/passwd_generator.cpp
)
add_library(lib ${SOURCES})

# inc
target_include_directories(lib PUBLIC passwd_generator)

find_package(GTest REQUIRED)
add_executable(tests tests/test.cpp)

target_link_libraries(tests gtest::gtest lib)
