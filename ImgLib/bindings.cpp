//
// Created by Aviral Gupta on 2019-04-27.
//
#include <pybind11/embed.h>
#include "ImgLibrary.h"

using namespace ImgLib;

namespace py = pybind11;

PYBIND11_MODULE(ImgLib, m) {
    py::class_<ImgLibrary>(m, "ImgLibrary")
        .def(py::init<char *>())
        .def("setName", &ImgLib::ImgLibrary::grayScale)
        ;
}