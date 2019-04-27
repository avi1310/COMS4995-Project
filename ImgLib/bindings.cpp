//
// Created by Aviral Gupta on 2019-04-27.
//
#include <pybind11/pybind11.h>
#include "ImgLibrary.h"

using namespace ImgLib;

namespace py = pybind11;

PYBIND11_PLUGIN(ImgLib) {
        py::module m("ImgLib", "Image Library Plugin");
        py::class_<ImgLibrary>(m, "ImgLibrary")
            .def (py::init<char *>())
            .def("grayScale", &ImgLib::ImgLibrary::grayScale);
        return m.ptr();
}

