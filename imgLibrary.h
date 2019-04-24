//
// Created by Aviral Gupta on 2019-04-21.
//

#ifndef COMS4995_PROJECT_IMGLIBRARY_H
#define COMS4995_PROJECT_IMGLIBRARY_H

#include "jpeg.h"
using namespace std;
#include <iostream>
#include <map>
#include <string>
using namespace marengo::jpeg;

class ImgLibrary {
	Image output;
	size_t height;
	size_t width;

public:
	ImgLibrary(){}

	~ImgLibrary(){}

	ImgLibrary(char *filename);
	ImgLibrary& save(const std::string& fileName);

	ImgLibrary& grayScale();

	//Need to check error with setPixel which is commented out;
	ImgLibrary& flipHorizontal();

	ImgLibrary& flipVertical();

	ImgLibrary& blur();

	ImgLibrary& resize(int newWidth);

	//Check Output
	ImgLibrary& edgeDetection();

	ImgLibrary& luminanceScaling(int factor);

	ImgLibrary& cropImage(int xOffset, int yOffset, size_t widthCrop, size_t heightCrop);

	ImgLibrary& masking(int xOffset, int yOffset, int xWidth, int yWidth);

	ImgLibrary& brightnessMod(double beta);

	ImgLibrary& contrastMod(double alpha);

	ImgLibrary& rotateAntiClockwise();

	ImgLibrary& rotateClockwise();

	ImgLibrary& rotate180();

	ImgLibrary& padding(int pad);

	ImgLibrary& invert();

};

#endif //COMS4995_PROJECT_IMGLIBRARY_H
