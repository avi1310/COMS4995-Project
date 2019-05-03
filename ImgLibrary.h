#ifndef COMS4995_PROJECT_IMGLIBRARY_H
#define COMS4995_PROJECT_IMGLIBRARY_H

#include "jpeg.h"
#include <iostream>
#include <string>
#include <stdexcept>

#ifdef pywrapper
#include <pybind11/pybind11.h>

namespace py = pybind11;
#endif

using namespace marengo::jpeg;

namespace imglib {

	static int const MAX_LUMINANCE = 10;
	static int const MIN_LUMINANCE = 0;

	static int const MAX_CONTRAST = 100;
	static int const MIN_CONTRAST = 0;

	static int const MAX_BRIGHTNESS = 100;
	static int const MIN_BRIGHTNESS = 0;

	class ImgLibrary {
		// Provided by the jpeg.h file. Representation of an decompressed image file.
		Image output;

	public:
		// Default Constructor.
		ImgLibrary(){}

		~ImgLibrary(){}

		// Load an image file. Currently only accepts RGB colorspace images.
		ImgLibrary(char *filename);

		// Save current version of image into a file specified, with the default/specified quality (0-100)
		ImgLibrary& save(const std::string& fileName, int quality = 95);

		// Converts an image into grayScale
		ImgLibrary& grayScale();

		// Flip along the y-axis
		ImgLibrary& flipHorizontal();

		// Flip along the x-axis
		ImgLibrary& flipVertical();

		// Blur the image
		ImgLibrary& blur();

		// Resize the image - expand or shrink based on current width
		ImgLibrary& resize(int newWidth);

		// TODO - Check output. Too coarse
		ImgLibrary& edgeDetection();

		// Scales the luminance value for the entire image
		ImgLibrary& luminanceScaling(int factor);

		// Crop an image starting at the xOffset, yOffset, with a box of size widthCrop*heightCrop
		ImgLibrary& cropImage(int xOffset, int yOffset, int widthCrop, int heightCrop);

		// Adds a black mask layer starting at the xOffset, yOffset, with a box of size widthCrop*heightCrop
		ImgLibrary& masking(int xOffset, int yOffset, int xWidth, int yWidth);

		// Modifies the brightness of the image
		ImgLibrary& brightnessMod(double beta);

		// Modifies the contrast of the image
		ImgLibrary& contrastMod(double alpha);

		// Rotate 90 degrees anti clockwise
		ImgLibrary& rotateAntiClockwise();

		// Rotate 90 degrees clockwise
		ImgLibrary& rotateClockwise();

		// Rotate an image by 180 degrees
		ImgLibrary& rotate180();

		// Adds a black padding around the image of width $pad$
		ImgLibrary& padding(int pad);

		// Inverts the colors in the image
		ImgLibrary& invert();

		size_t getHeight()    const { return output.getHeight(); }
		size_t getWidth()     const { return output.getWidth();  }

	};

#ifdef pywrapper
	//Python wrapper for library. Requires pybind11 to be installed.
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
		.def("invert", &ImgLibrary::invert)
		.def("getHeight", &ImgLibrary::getHeight)
		.def("getWidth", &ImgLibrary::getWidth);

	};
#endif //pywrapper
}


#endif //COMS4995_PROJECT_IMGLIBRARY_H
