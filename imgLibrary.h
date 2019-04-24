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
	void save(const std::string& fileName);

	void grayScale();

	//Need to check error with setPixel which is commented out;
	void flipHorizontal();

	void flipVertical();

	void blur();

	void resize(int newWidth);

	//Check Output
	void edgeDetection();

	void luminanceScaling(int factor);

	void cropImage(int xOffset, int yOffset, size_t widthCrop, size_t heightCrop);

	void masking(int xOffset, int yOffset, int xWidth, int yWidth);

	void brightnessMod(double beta);

	void contrastMod(double alpha);

	void rotateAntiClockwise();

	void rotateClockwise();

	void rotate180();

	void padding(int pad);

	void invert();

};

#endif //COMS4995_PROJECT_IMGLIBRARY_H
