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
        img = output;
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
    //Need to check error with setPixel which is commented out;
    void flipHorizontal() {
        img = output;
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

    void flipVertical() {
        img = output;
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

    void blur() {
        img = output;
//         float kernel[3][3] = {
//             {1/9.0, 1/9.0, 1/9.0},
//             {1/9.0, 1/9.0, 1/9.0},
//             {1/9.0, 1/9.0, 1/9.0},
//         };
         float kernel[3][3] = {
             {0, 1, 0},
             {1, -4, 1},
             {0, 1, 0},
         };
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

    void resize(int newWidth) {
        img = output;
        output.resize(newWidth);
    }

};

#endif //COMS4995_PROJECT_IMGLIBRARY_H
