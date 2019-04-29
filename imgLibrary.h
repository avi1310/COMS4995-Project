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

	PYBIND11_MODULE(ImgLibrary, m) {
	m.doc() = "Image Manipulation library written in C++";

	py::class_<ImgLibrary>(m, "ImgLibrary")
		.def(py::init<>())
		.def(py::init<char *>())
		.def("save", &ImgLibrary::save,
			py::arg("fileName"), py::arg("quality") = 95)
		.def("grayScale", &ImgLibrary::grayScale)
		.def("flipHorizontal", &ImgLibrary::flipHorizontal)
		.def("flipVertical", &ImgLibrary::flipVertical)
		.def("blur", &ImgLibrary::blur)
		.def("resize", &ImgLibrary::resize)
		.def("edgeDetection", &ImgLibrary::edgeDetection)
		.def("luminanceScaling", &ImgLibrary::luminanceScaling)
		.def("cropImage", &ImgLibrary::cropImage)
		.def("masking", &ImgLibrary::masking)
		.def("brightnessMod", &ImgLibrary::brightnessMod)
		.def("contrastMod", &ImgLibrary::contrastMod)
		.def("rotateAntiClockwise", &ImgLibrary::rotateAntiClockwise)
		.def("rotateClockwise", &ImgLibrary::rotateClockwise)
		.def("rotate180", &ImgLibrary::rotate180)
		.def("padding", &ImgLibrary::padding)
		.def("invert", &ImgLibrary::invert);

};
}


#endif //COMS4995_PROJECT_IMGLIBRARY_H
