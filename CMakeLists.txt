cmake_minimum_required(VERSION 2.8.12)
project(ImgLib)
# Set source directory
set(SOURCE_DIR "ImgLib")
# Tell CMake that headers are also in SOURCE_DIR
include_directories(${SOURCE_DIR})
set(SOURCES "${SOURCE_DIR}/ImgLibrary.cpp")

include_directories(lib)

add_subdirectory(lib/pybind11)
pybind11_add_module(imgLib ${SOURCES} "${SOURCE_DIR}/bindings.cpp")

