#include "ImgLibrary.h"

ImgLibrary::ImgLibrary(char *filename) {
	Image imgOriginal(filename);
	this->output = imgOriginal;
	this->height = output.getHeight();
	this->width  = output.getWidth();
}

ImgLibrary& ImgLibrary::save(const std::string& fileName) {
	output.save(fileName, 100);

	return *this;
}

ImgLibrary& ImgLibrary::grayScale() {
	for ( size_t y = 0; y < output.getHeight(); ++y ) {
		for ( size_t x = 0; x < output.getWidth(); ++x ) {
			uint8_t luminance = output.getLuminance(x, y);
			output.setPixel(x,y,{luminance, luminance, luminance});
		}
	}

	return *this;
}

ImgLibrary& ImgLibrary::flipHorizontal() {
	for(size_t y = 0; y < output.getHeight(); ++y) {
		for(size_t x = 0; x < output.getWidth()/2; ++x) {
			std::vector<uint8_t> pixels_l = output.getPixel(x, y);
			std::vector<uint8_t> pixels_r = output.getPixel(output.getWidth() - x - 1, y);

			output.setPixel(x, y, pixels_r);
			output.setPixel(output.getWidth()-x-1, y, pixels_l);
		}
	}

	return *this;
}

ImgLibrary& ImgLibrary::flipVertical() {
	for(size_t y = 0; y < output.getHeight()/2; ++y) {
		for(size_t x = 0; x < output.getWidth(); ++x) {
			std::vector<uint8_t> pixels_u = output.getPixel(x, y);
			std::vector<uint8_t> pixels_d = output.getPixel(x, output.getHeight() - y - 1);

			output.setPixel(x,y,pixels_d);
			output.setPixel(x,output.getHeight()-y-1,pixels_u);
		}
	}

	return *this;
}

ImgLibrary& ImgLibrary::blur() {
	Image img = output;
	float kernel[3][3] = {
		{1/9.0, 1/9.0, 1/9.0},
		{1/9.0, 1/9.0, 1/9.0},
		{1/9.0, 1/9.0, 1/9.0},
	};
//         float kernel[3][3] = {
//             {0, 1, 0},
//             {1, -4, 1},
//             {0, 1, 0},
//         };

	for(size_t y=1; y < output.getHeight()-1; y++) {
		for(size_t x = 1; x < output.getWidth()-1; x++) {
			float sum[3] = {0.0, 0.0, 0.0};
			for(int k = -1; k <= 1; k++) {
				for(int j = -1; j <= 1; j++) {
					std::vector<uint8_t> pixels = img.getPixel(x - k, y - j);
					int i=0;
					for(uint8_t &p: pixels) {
						sum[i] = sum[i] + kernel[j+1][k+1]*p;
						i++;
					}
				}
			}
			output.setPixel(x,y,{uint8_t(sum[0]), uint8_t(sum[1]), uint8_t(sum[2])});
		}
	}

	return *this;
}

ImgLibrary& ImgLibrary::resize(int newWidth) {
	output.resize(newWidth);

	return *this;
}

ImgLibrary& ImgLibrary::edgeDetection() {
	// Edge detection
	Image img = output;

//         float kernel[3][3] = {
//             {-1, -1, -1},
//             {-1, 8, -1},
//             {-1, -1, -1},
//         };
//         float kernel[3][3] = {
//             {-1, -1, -1},
//             {2, 2, 2},
//             {-1, -1, -1},
//         };
//
//         float kernel[3][3] = {
//             {-1, 2, -1},
//             {-1, 2, -1},
//             {-1, 2, -1},
//         };

	float kernel[3][3] = {
		{-1, -1, 2},
		{-1, 2, -1},
		{2, -1, -1},
	};

	for(size_t y = 0; y < output.getHeight(); y++) {
		for(size_t x = 0; x < output.getWidth(); x++) {
			output.setPixel(x,y,{0,0,0});
		}
	}

	for(size_t y = 1; y < output.getHeight()-1; y++) {
		for(size_t x = 1; x < output.getWidth()-1; x++) {
			float sum = 0.0;
			for(int k = -1; k <= 1; k++) {
				for(int j = -1; j <= 1; j++) {
					std::vector<uint8_t> pixels = img.getPixel(x - k, y - j);

					for(uint8_t &p: pixels) {
						sum = sum + kernel[j+1][k+1]*p;
					}
				}
			}

			output.setPixel(x, y, {uint8_t(sum), uint8_t(sum), uint8_t(sum)});
		}
	}

	return *this;
}

ImgLibrary& ImgLibrary::luminanceScaling(int factor) {
	// Luminance Modification

	for(size_t y = 0; y < output.getHeight(); y++) {
		for(size_t x = 0; x < output.getWidth(); x++) {
			std::vector<uint8_t> pixels = output.getPixel(x, y);

			output.setPixel(x,y,{
				uint8_t((pixels[0] * 2)*factor/6),
				uint8_t((pixels[1] * 3)*factor/6),
				uint8_t((pixels[2])*factor/6)}
			);
		}
	}

	return *this;
}

ImgLibrary& ImgLibrary::cropImage(size_t xOffset, size_t yOffset, size_t widthCrop, size_t heightCrop) {
	Image temp(widthCrop, heightCrop);
	for(size_t i=xOffset, i1=0; i<xOffset+widthCrop; i++, i1++){
		for(size_t j=yOffset, j1=0; j<yOffset+heightCrop; j++, j1++){
			temp.setPixel(i1, j1, output.getPixel(i,j));
		}
	}
	output = temp;

	return *this;
}

ImgLibrary& ImgLibrary::masking(size_t xOffset, size_t yOffset, size_t xWidth, size_t yWidth) {
	// Masking

	for(size_t y = yOffset-1; y < yOffset+yWidth-1 && y < output.getHeight(); y++) {
		for(size_t x = xOffset-1; x < xOffset+xWidth-1 && x < output.getWidth(); x++) {
				output.setPixel(x,y, {0,0,0});
		}
	}

	return *this;
}

ImgLibrary& ImgLibrary::brightnessMod(double beta) {
	Image img = output;
	for(size_t y = 0; y < output.getHeight(); y++) {
		for(size_t x = 0; x < output.getWidth(); x++) {
			std::vector<uint8_t> currPixel = output.getPixel(x,y);

			for(uint8_t &p: currPixel){
				int val = int(p+beta);
				if(val > 255){
					val = 255;
				}
				p = uint8_t(val);
			}

			output.setPixel(x,y,currPixel);
		}
	}

	return *this;
}

ImgLibrary& ImgLibrary::contrastMod(double alpha) {
	Image img = output;
	for(size_t y = 0; y < output.getHeight(); y++) {
		for(size_t x = 0; x < output.getWidth(); x++) {
			std::vector<uint8_t> currPixel = output.getPixel(x,y);

			for(uint8_t &p: currPixel){
				int val = int(p*alpha);
				if(val > 255){
					val = 255;
				}
				p = uint8_t(val);
			}

			output.setPixel(x,y,currPixel);
		}
	}

	return *this;
}

ImgLibrary& ImgLibrary::rotateAntiClockwise() {
	// Rotate CCW
	Image img(output.getHeight(), output.getWidth());

	for(size_t y = 0; y < output.getHeight(); y++) {
		for(size_t x = 0; x < output.getWidth(); x++) {
			img.setPixel(y, x, output.getPixel(output.getWidth() - 1 - x, y));
		}
	}

	output = img;

	return *this;
}

ImgLibrary& ImgLibrary::rotateClockwise() {
	// Rotate CW
	Image img(output.getHeight(), output.getWidth());

	//Use int here, cause size_t is unsigned and that's a pain to deal with when comparing with 0.
	for(int y = int(output.getHeight() - 1); y >= 0 ; y--) {
		for(size_t x = 0; x < output.getWidth(); x++) {
			img.setPixel(y, x, output.getPixel(x, output.getHeight() - 1 - y));
		}
	}

	output = img;

	return *this;
}

ImgLibrary& ImgLibrary::rotate180() {
	Image img(output.getWidth(), output.getHeight());

	for(size_t y = 0; y < output.getHeight() ; y++) {
		for(size_t x = 0; x < output.getWidth(); x++) {
			img.setPixel(output.getWidth() - 1 - x, output.getHeight() - 1 - y, output.getPixel(x, y));
		}
	}

	output = img;

	return *this;
}

ImgLibrary& ImgLibrary::padding(int pad) {
	for(size_t x = 0; x < output.getWidth(); x++) {
		for(int k = 0; k < 3*pad; k++) {
			output.m_bitmapData[x].insert(output.m_bitmapData[x].begin(), 0);
			output.m_bitmapData[x].push_back(0);
		}
	}
	output.m_width += 2*pad;
	for(int k = 0; k < pad; k++) {
		std::vector<uint8_t> v;
		for(int i = 0; i < (int)output.getWidth()*3; i++) {
			v.push_back(0);
		}
		output.m_bitmapData.insert(output.m_bitmapData.begin(), v);
		output.m_bitmapData.push_back(v);
	}

	output.m_height += 2*pad;
	height = output.getHeight();
	width = output.getWidth();

	return *this;
}

ImgLibrary& ImgLibrary::invert() {
	// Invert image
	for(size_t y = 0; y < output.getHeight(); y++) {
		for(size_t x = 0; x < output.getWidth(); x++) {
			std::vector<uint8_t> pixels = output.getPixel(x, y);

			for(uint8_t &p: pixels){
				p = ~p;
			}

			output.setPixel(x,y,pixels);
		}
	}

	return *this;
}