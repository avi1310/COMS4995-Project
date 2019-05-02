#include <stdio.h>
#include <chrono>
#include "../ImgLibrary.h"
using namespace std;
#include <iostream>
using namespace imglib;


void printElapsedTime(chrono::high_resolution_clock::time_point start,  chrono::high_resolution_clock::time_point end) {
    cout << "Elapsed time in milliseconds "
    <<chrono::duration_cast<chrono::milliseconds>(end - start).count()
    << " ms" <<endl;
}

void computeGrayscaleLib(char *path) {
    auto start = chrono::high_resolution_clock::now();
    ImgLibrary img(path);
    img.grayScale().save("output_lib.jpeg");
    auto end = chrono::high_resolution_clock::now();
    cout<<"Time taken for ImgLib Grayscale: "<<endl;
    printElapsedTime(start, end);
}

void computeRotateClockwiseLib(char *path) {
    auto start = chrono::high_resolution_clock::now();
    ImgLibrary img(path);
    img.rotateClockwise().save("output_lib.jpeg");
    auto end = chrono::high_resolution_clock::now();
    cout<<"Time taken for ImgLib Rotate Clockwise: "<<endl;
    printElapsedTime(start, end);
}

void computeRotateAntiClockwiseLib(char *path) {
    auto start = chrono::high_resolution_clock::now();
    ImgLibrary img(path);
    img.rotateAntiClockwise().save("output_lib.jpeg");
    auto end = chrono::high_resolution_clock::now();
    cout<<"Time taken for ImgLib Rotate AntiClockwise: "<<endl;
    printElapsedTime(start, end);
}

void computeRotate180Lib(char *path) {
    auto start = chrono::high_resolution_clock::now();
    ImgLibrary img(path);
    img.rotate180().save("output_lib.jpeg");
    auto end = chrono::high_resolution_clock::now();
    cout<<"Time taken for ImgLib Rotate 180: "<<endl;
    printElapsedTime(start, end);
}

void computeFlipVerticalLib(char *path) {
    auto start = chrono::high_resolution_clock::now();
    ImgLibrary img(path);
    img.flipVertical().save("output_lib.jpeg");
    auto end = chrono::high_resolution_clock::now();
    cout<<"Time taken for ImgLib Flip Vertical: "<<endl;
    printElapsedTime(start, end);
}

void computeFlipHorizontalLib(char *path) {
    auto start = chrono::high_resolution_clock::now();
    ImgLibrary img(path);
    img.flipHorizontal().save("output_lib.jpeg");
    auto end = chrono::high_resolution_clock::now();
    cout<<"Time taken for ImgLib Flip Horizontal: "<<endl;
    printElapsedTime(start, end);
}

void computeBlurLib(char *path) {
    auto start = chrono::high_resolution_clock::now();
    ImgLibrary img(path);
    img.blur().save("output_lib.jpeg");
    auto end = chrono::high_resolution_clock::now();
    cout<<"Time taken for ImgLib Blur: "<<endl;
    printElapsedTime(start, end);
}

void computeInvertLib(char *path) {
    auto start = chrono::high_resolution_clock::now();
    ImgLibrary img(path);
    img.invert().save("output_lib.jpeg");
    auto end = chrono::high_resolution_clock::now();
    cout<<"Time taken for ImgLib Invert: "<<endl;
    printElapsedTime(start, end);
}


int main( int argc, char* argv[])
{

    if ( argc < 2 )
    {
        std::cout << "No jpeg file specified\n";
        return 1;
    }
    try
    {
        auto startLib = chrono::high_resolution_clock::now();
        computeGrayscaleLib(argv[1]);
        computeRotateClockwiseLib(argv[1]);
        computeRotateAntiClockwiseLib(argv[1]);
        computeRotate180Lib(argv[1]);
        computeFlipVerticalLib(argv[1]);
        computeFlipHorizontalLib(argv[1]);
        computeBlurLib(argv[1]);
        computeInvertLib(argv[1]);
        auto endLib = chrono::high_resolution_clock::now();
        cout<<"Total Time for running ImgLib functions:"<<endl;
        printElapsedTime(startLib, endLib);
        
    }
    catch( const std::exception& e )
    {
        std::cout << "Main() error handler: ";
        std::cout << e.what() << std::endl;
        return 1;
    }
}
