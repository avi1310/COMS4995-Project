#include <iostream>

#include "ImgLibrary.h"

using namespace std;
using namespace imglib;

int main( int argc, char* argv[] )
{
    if ( argc < 2 ) {
        std::cout << "No jpeg file specified\n";
        return 1;
    }
    try {
        ImgLibrary testImg1(argv[1]);

        testImg1
            .padding(40)
            .invert()
            .rotateClockwise()
            .masking(40,40,50,50)
            .save("output.jpg");
        return 0;
    }
    catch( const std::exception& e ) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
}