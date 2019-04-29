#ifndef COMS4995_PROJECT_IMGLIBRARY_H
#define COMS4995_PROJECT_IMGLIBRARY_H

#include "jpeg.h"
#include <iostream>
#include <string>
#include <stdexcept>

#include <pybind11/pybind11.h>

namespace py = pybind11;

using namespace marengo::jpeg;

namespace imglib {

	static int const MAX_LUMINANCE = 10;
	static int const MIN_LUMINANCE = 0;

	static int const MAX_CONTRAST = 100;
	static int const MIN_CONTRAST = 0;

	static int const MAX_BRIGHTNESS = 100;
	static int const MIN_BRIGHTNESS = 0;

	class ImgLibrary {
		Image output;

	public:
		ImgLibrary(){}

		~ImgLibrary(){}

		ImgLibrary(char *filename);
		ImgLibrary& save(const std::string& fileName, int quality = 95);

		ImgLibrary& grayScale();

		//Need to check error with setPixel which is commented out;
		ImgLibrary& flipHorizontal();

		ImgLibrary& flipVertical();

		ImgLibrary& blur();

		ImgLibrary& resize(int newWidth);

		//Check Output
		ImgLibrary& edgeDetection();

		ImgLibrary& luminanceScaling(int factor);

		ImgLibrary& cropImage(size_t xOffset, size_t yOffset, size_t widthCrop, size_t heightCrop);

		ImgLibrary& masking(size_t xOffset, size_t yOffset, size_t xWidth, size_t yWidth);

		ImgLibrary& brightnessMod(double beta);

		ImgLibrary& contrastMod(double alpha);

		ImgLibrary& rotateAntiClockwise();

		ImgLibrary& rotateClockwise();

		ImgLibrary& rotate180();

		ImgLibrary& padding(int pad);

		ImgLibrary& invert();

	};
}


PYBIND11_MODULE(ImgLibrary, m) {
	m.doc() = "Image Manipulation library written in C++";

	py::class_<imglib::ImgLibrary>(m, "ImgLibrary")
		.def(py::init<>())
		.def(py::init<char *>())
		.def("save", &imglib::ImgLibrary::save,
			py::arg("fileName"), py::arg("quality") = 95)
		.def("grayScale", &imglib::ImgLibrary::grayScale)
		.def("flipHorizontal", &imglib::ImgLibrary::flipHorizontal)
		.def("flipVertical", &imglib::ImgLibrary::flipVertical)
		.def("blur", &imglib::ImgLibrary::blur)
		.def("resize", &imglib::ImgLibrary::resize)
		.def("edgeDetection", &imglib::ImgLibrary::edgeDetection)
		.def("luminanceScaling", &imglib::ImgLibrary::luminanceScaling)
		.def("cropImage", &imglib::ImgLibrary::cropImage)
		.def("masking", &imglib::ImgLibrary::masking)
		.def("brightnessMod", &imglib::ImgLibrary::brightnessMod)
		.def("contrastMod", &imglib::ImgLibrary::contrastMod)
		.def("rotateAntiClockwise", &imglib::ImgLibrary::rotateAntiClockwise)
		.def("rotateClockwise", &imglib::ImgLibrary::rotateClockwise)
		.def("rotate180", &imglib::ImgLibrary::rotate180)
		.def("padding", &imglib::ImgLibrary::padding)
		.def("invert", &imglib::ImgLibrary::invert);

};

#endif //COMS4995_PROJECT_IMGLIBRARY_H
