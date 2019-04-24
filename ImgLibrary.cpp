#include "ImgLibrary.h"

ImgLibrary::ImgLibrary(char *filename) {
	Image imgOriginal(filename);
	this->output = imgOriginal;
	this->height = output.getHeight();
	this->width  = output.getWidth();
}

void ImgLibrary::save(const std::string& fileName) {
	output.save(fileName, 100);
}

void ImgLibrary::grayScale() {
	for ( size_t y = 0; y < height; ++y )
	{
		for ( size_t x = 0; x < width; ++x )
		{
			// uint8_t luma = img.getLuminance( x, y );
			// display( luma );
			vector<uint8_t> p2;
			vector<uint8_t> pixels = output.getPixel( x, y);
			// int i = 0;
			// for(auto &p: pixels) {
				// cout<<(int)p<<' ';
			int luminance = (int)output.getLuminance(x, y);
			output.m_bitmapData[y][x*3] = luminance;
			output.m_bitmapData[y][x*3+1] = luminance;
			output.m_bitmapData[y][x*3+2] = luminance;
			// dup_g.m_bitmapData[y][x*3] = (int)img.getLuminance(x, y);
				// i++;
				// pp.push_back(2*int(p));
				// p2.push_back(2*int(p));
			// }
			// dupImg.m_bitmapData[y][x] = pp;
			// cout<<'\n';
		}
		// std::cout << "\n";
	}
}

void ImgLibrary::flipHorizontal() {
	for(size_t y = 0; y < height; ++y) {
		for(size_t x = 0; x < width/2; ++x) {
			// cout<<"Here = "<<x<<" "<<y<<endl;
//                 cout<<x<<"  "<<width - x<<endl;
			auto pixels_l = output.getPixel(x, y);
			auto pixels_r = output.getPixel(width - x, y);
			// auto pixels_r = dup_f.getPixel(x, y);

			int i = 0;
			for(auto &p: pixels_r) {
				output.m_bitmapData[y][x*3 + i] = (int)p;
				i++;
			}
			i = 0;
			for(auto &p: pixels_l) {
				output.m_bitmapData[y][(width - x)*3 + i] = (int)p;
				i++;
			}
		}
	}
}

void ImgLibrary::flipVertical() {
	for(size_t y = 0; y < height/2; ++y) {
		for(size_t x = 0; x < width; ++x) {
			// cout<<"Here = "<<y<<" "<<height - y<<endl;
			// cout<<x<<"  "<<width - x<<endl;
			// cout<<"1"<<endl;
			auto pixels_u = output.getPixel(x, y);
			// cout<<"2"<<endl;
			auto pixels_d = output.getPixel(x, height - y - 1);
			//cout<<pixels_d.size()<<endl;
			// auto pixels_r = dup_f.getPixel(x, y);
			// cout<<"Yes";
			int i = 0;
			for(auto &p: pixels_d) {
				output.m_bitmapData[y][x*3 + i] = (int)p;
				i++;
			}
			i = 0;
			for(auto &p: pixels_u) {
				output.m_bitmapData[height - y - 1][x*3 + i] = (int)p;
				i++;
			}
		}
	}
}

void ImgLibrary::blur() {
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
	for(size_t y = 0; y < height; y++) {
		for(size_t x = 0; x < width; x++) {
			// auto pixels = blur.getPixel(x, y);
			output.m_bitmapData[y][x*3] = 0.0;
			output.m_bitmapData[y][x*3 + 1] = 0.0;
			output.m_bitmapData[y][x*3 + 2] = 0.0;
		}
	}

	for(size_t y=1; y < height-1; y++) {
		for(size_t x = 1; x < width-1; x++) {
			float sum[3] = {0.0, 0.0, 0.0};
			for(int k = -1; k <= 1; k++) {
				for(int j = -1; j <= 1; j++) {
					// cout<<"Now"<<x<<' '<<y<<endl;
					auto pixels = img.getPixel(x - k, y - j);
					int i=0;
					for(auto &p: pixels) {
						sum[i] = sum[i] + kernel[j+1][k+1]*p;
						i++;
					}
				}
			}
			output.m_bitmapData[y][x*3] = sum[0];
			output.m_bitmapData[y][x*3 + 1] = sum[1];
			output.m_bitmapData[y][x*3 + 2] = sum[2];
		}
	}
}

void ImgLibrary::resize(int newWidth) {
	output.resize(newWidth);
	height = output.getHeight();
	width = output.getWidth();
}

void ImgLibrary::edgeDetection() {
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

	for(size_t y = 0; y < height; y++) {
		for(size_t x = 0; x < width; x++) {
			// auto pixels = blur.getPixel(x, y);
			output.m_bitmapData[y][x*3] = 0.0;
			output.m_bitmapData[y][x*3 + 1] = 0.0;
			output.m_bitmapData[y][x*3 + 2] = 0.0;
		}
	}

	for(size_t y = 1; y < height-1; y++) {
		for(size_t x = 1; x < width-1; x++) {
			// float sum[3] = {0.0, 0.0, 0.0};
			float sum = 0.0;
			for(int k = -1; k <= 1; k++) {
				for(int j = -1; j <= 1; j++) {
					// cout<<"Now"<<x<<' '<<y<<endl;
					auto pixels = img.getPixel(x - k, y - j);
					// int i=0;
					for(auto &p: pixels) {
						// sum[i] = sum[i] + kernel[j+1][k+1]*p;
						// i++;
						sum = sum + kernel[j+1][k+1]*p;
					}
				}
			}
			output.m_bitmapData[y][x*3] = sum;
			output.m_bitmapData[y][x*3 + 1] = sum;
			output.m_bitmapData[y][x*3 + 2] = sum;
		}
	}
}

void ImgLibrary::luminanceScaling(int factor) {
	// Luminance Modification

	 for(size_t y = 0; y < height; y++) {
		 for(size_t x = 0; x < width; x++) {
			 auto pixels = output.getPixel(x, y);
			 uint8_t a = (pixels[0] * 2)*factor/6;
			 uint8_t b = (pixels[1] * 3)*factor/6;
			 uint8_t c = (pixels[2])*factor/6;
			 output.m_bitmapData[y][x*3] = a;
			 output.m_bitmapData[y][x*3 + 1] = b;
			 output.m_bitmapData[y][x*3 + 2] = c;
		 }
	 }
}

void ImgLibrary::cropImage(int xOffset, int yOffset, size_t widthCrop, size_t heightCrop) {
	Image temp(widthCrop, heightCrop);
	for(size_t i=xOffset, i1=0; i<xOffset+widthCrop; i++, i1++){
		for(size_t j=yOffset, j1=0; j<yOffset+heightCrop; j++, j1++){
			temp.setPixel(i1, j1, output.getPixel(i,j));
		}
	}
	output = temp;
	height = output.getHeight();
	width = output.getWidth();
}

void ImgLibrary::masking(int xOffset, int yOffset, int xWidth, int yWidth) {
	// Masking

	 for(size_t y = 0; y < height; y++) {
		 for(size_t x = 0; x < width; x++) {
			 if((int)y >= yOffset && (int)y <= (yWidth + yOffset) && (int)x >= xOffset && (int)x <= (xWidth + xOffset)) { // mask
				 int i = 0;
				 for(; i < 3; i++) {
					 output.m_bitmapData[y][x*3 + i] &= 0x00;
				 }
			 }
		 }
	 }
}

void ImgLibrary::brightnessMod(double beta) {
	Image img = output;
	for(size_t y = 0; y < height; y++) {
		 for(size_t x = 0; x < width; x++) {
			 // auto pixels = origImg.getPixel(x, y);
			 int i = 0;
			 for(; i < 3;) {
				 int val = (int)(img.m_bitmapData[y][x*3 + i] + beta);
				 if(val > 255) {
					 val = 255;
				 }
				 output.m_bitmapData[y][x*3 + i] = val;
				 i++;
			 }
		 }
	 }
}

void ImgLibrary::contrastMod(double alpha) {
	Image img = output;
	for(size_t y = 0; y < height; y++) {
		for(size_t x = 0; x < width; x++) {
			// auto pixels = origImg.getPixel(x, y);
			int i = 0;
			for(; i < 3;) {
				int val = (int)(alpha*img.m_bitmapData[y][x*3 + i]);
				if(val > 255) {
					val = 255;
				}
				output.m_bitmapData[y][x*3 + i] = val;
				i++;
			}
		}
	}
}

void ImgLibrary::rotateAntiClockwise() {
	// Rotate CCW
	 Image img = output;

	 // or = 375 h, 500 w
	 // nr = 500 h, 375 w
	 output.m_width = img.m_height;
	 output.m_height = img.m_width;

	 output.m_bitmapData.resize(output.m_height);
	 for(int i = 0; i < (int)output.m_height; i++) {
		 output.m_bitmapData[i].resize(output.m_width*3);
	 }
	 for(size_t y = 0; y < img.m_height; y++) {
		 for(size_t x = 0; x < img.m_width; x++) {
			 output.setPixel(y, x, img.getPixel(img.m_width - 1 - x, y));
		 }
	 }

	 height = output.getHeight();
	 width = output.getWidth();
	// n_r.save("rotate90.jpeg", 100);
}

void ImgLibrary::rotateClockwise() {
	// Rotate CW
	Image img = output;

	// // or = 375 h, 500 w
	// // nr = 500 h, 375 w
	 output.m_width = img.m_height;
	 output.m_height = img.m_width;

	 output.m_bitmapData.resize(output.m_height);
	 for(int i = 0; i < (int)output.m_height; i++) {
		 output.m_bitmapData[i].resize(output.m_width*3);
	 }
	 for(int y = (int)img.m_height - 1; y>=0 ; y--) {
		 for(size_t x = 0; x < img.m_width; x++) {
//                 cout<<x<<' '<<y<<endl;
			 output.setPixel(y, x, img.getPixel(x, img.m_height - 1 - y));
		 }
	 }

	height = output.getHeight();
	width = output.getWidth();
	// n_r.save("rotate90_2.jpeg", 100);
}

void ImgLibrary::rotate180() {
	Image img = output;

	// or = 375 h, 500 w
	// nr = 500 h, 375 w

	 for(int i = 0; i < (int)output.m_height; i++) {
		 output.m_bitmapData[i].resize(output.m_width*3);
	 }
	 for(size_t y = 0; y < img.m_height ; y++) {
		 for(size_t x = 0; x < img.m_width; x++) {
			 // cout<<x<<' '<<y<<endl;
			 output.setPixel(img.m_width - 1 - x, img.m_height - 1 - y, img.getPixel(x, y));
		 }
	 }
}

void ImgLibrary::padding(int pad) {
	 for(size_t x = 0; x < height; x++) {
		 for(int k = 0; k < 3*pad; k++) {
			 output.m_bitmapData[x].insert(output.m_bitmapData[x].begin(), 0);
			 output.m_bitmapData[x].push_back(0);
		 }
	 }
	 output.m_width += 2*pad;
	 for(int k = 0; k < pad; k++) {
		 vector<uint8_t> v;
		 for(int i = 0; i < (int)output.m_width*3; i++) {
			 v.push_back(0);
		 }
		 output.m_bitmapData.insert(output.m_bitmapData.begin(), v);
		 output.m_bitmapData.push_back(v);
	 }

	output.m_height += 2*pad;
	height = output.getHeight();
	width = output.getWidth();
}

void ImgLibrary::invert() {
	// Invert image
	 for(size_t y = 0; y < height; y++) {
		 for(size_t x = 0; x < width; x++) {
			 auto pixels = output.getPixel(x, y);
			 int i = 0;
			 for(; i < 3; i++) {
				 output.m_bitmapData[y][x*3 + i] = ~output.m_bitmapData[y][x*3 + i];
			 }
		 }
	 }
}