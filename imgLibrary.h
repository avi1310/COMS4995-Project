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

class imgLibrary {

    Image output;
    Image img;
    size_t height;
    size_t width;

public:
    imgLibrary() {

    }

    imgLibrary(char *filename) {
        Image imgOriginal(filename);
        this->img = imgOriginal;
        this->output = imgOriginal;
        this->height = img.getHeight();
        this->width  = img.getWidth();
    }

    ~imgLibrary() {

    }

    void save(const std::string& fileName) {
        output.save(fileName, 100);
    }

    void grayScale() {
        for ( size_t y = 0; y < height; ++y )
         {
             for ( size_t x = 0; x < width; ++x )
             {
                 // uint8_t luma = img.getLuminance( x, y );
                 // display( luma );
                 vector<uint8_t> p2;
                 vector<uint8_t> pixels = img.getPixel( x, y);
                 // int i = 0;
                 // for(auto &p: pixels) {
                     // cout<<(int)p<<' ';

                 output.m_bitmapData[y][x*3] = (int)img.getLuminance(x, y);
                 output.m_bitmapData[y][x*3+1] = (int)img.getLuminance(x, y);
                 output.m_bitmapData[y][x*3+2] = (int)img.getLuminance(x, y);
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

};

#endif //COMS4995_PROJECT_IMGLIBRARY_H
