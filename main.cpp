#include <iostream>
#include <map>
#include "ImgLibrary.h"

using namespace std;

void display( uint8_t luma )
{
    static std::vector<char> ascii{
        ' ', '.', ',', ':', '-', '=', '+', '*', '#', '%', '@'
        };

    int val = luma / 24;
    std::cout << ascii[val] << ascii[val];
}

int main( int argc, char* argv[] )
{
    if ( argc < 2 )
    {
        std::cout << "No jpeg file specified\n";
        return 1;
    }
    try 
    {
        // Constructor expects a filename to load:
        // Image imgOriginal( argv[1] );
        // Image img = imgOriginal;
        // Copy construct a second version so we can
        // shrink non-destructively. Not really necessary
        // here, but just to show it can be done :)
        ImgLibrary testImg1(argv[1]);

//        testImg1.flipHorizontal();
//        testImg1.save("flip.jpeg");
//        testImg1.flipVertical();
//        testImg1.save("fVert.jpeg");
//        testImg1.blur();
//        testImg1.save("blur.jpeg");
//       testImg1.resize(400);
//        testImg1.save("resized.jpeg");
//
//        testImg1.masking(200, 500, 200, 200);
//        testImg1.save("mask.jpeg");
//        testImg1.contrastMod(2.3);
//        testImg1.save("contrast.jpeg");
//        testImg1.brightnessMod(20);
//        testImg1.save("brightness.jpeg");
//        testImg1.grayScale();
          testImg1.rotateAntiClockwise().rotateClockwise().rotate180().rotate180().padding(16).invert().save("output1.jpg");


//        testImg1.edgeDetection();
//        testImg1.save("edgeDetection.jpeg");
//          testImg1.luminanceScaling(2);
//          testImg1.save("luminanceScaling.jpeg");


        // Image dup_g = Image(img.m_height, img.m_width, img.m_pixelSize);
        // Shrink proportionally to a specific width (in px)
        // img.shrink( 60 );
        // dupImg.shrink(60);

        // Display the image in ASCII, just for fun.
//        size_t height = img.getHeight();
//        size_t width  = img.getWidth();
//        for ( size_t y = 0; y < height; ++y )
//        {
//            for ( size_t x = 0; x < width; ++x )
//            {
//                uint8_t luma = img.getLuminance( x, y );
//                display( luma );
//            }
//            std::cout << "\n";
//        }

        // cout<<"Bitmap data is as follows"<<endl;
        // for(size_t y = 0; y < height; y++) {
        //     for(size_t x = 0; x < width; x++) {
        //         // auto p = img.m_bitmapData[y][x];
        //         // cout<<typeof(p)<<' ';
        //         // cout<<"\n";
        //     }
        //     cout<<'\n';
        // }
/////////////////////////////////////////////////////////////////////////
//        Image dupImage( argv[1] );
//        Image dupImg = dupImage;
//        cout<<"\n\n\n";
//         for ( size_t y = 0; y < height; ++y )
//         {
//             for ( size_t x = 0; x < width; ++x )
//             {
//                 // uint8_t luma = img.getLuminance( x, y );
//                 // display( luma );
//                 vector<uint8_t> p2;
//                 vector<uint8_t> pixels = img.getPixel( x, y);
//                 int i = 0;
//                 for(auto &p: pixels) {
//                     // cout<<(int)p<<' ';
//                     dupImg.m_bitmapData[y][x*3 + i] = 2*int(p);
//                     i++;
//                     // pp.push_back(2*int(p));
//                     // p2.push_back(2*int(p));
//                 }
//                 // dupImg.m_bitmapData[y][x] = pp;
//                 // cout<<'\n';
//             }
//             // std::cout << "\n";
//         }
//         dupImg.save("output.jpeg", 100);

/////////////////////////////////////////////////////////////////////////


        // random design image
        // Image ran_img( argv[1] );
        // Image ran = ran_img;

        // height = ran_img.getHeight();
        // width = ran_img.getWidth();

        // float radius = 5;
        // for(size_t y = 5; y < height-5; y+=5) {
        //     for(size_t x = 5; x < width-5; x+=5) {
        //         auto pixels = ran_img.getPixel(x, y);

        //         int r = 0;
        //         int g = 0;
        //         int b = 0;

        //         for(int ry = -radius; ry <= radius; ry++) {
        //             for(int rx = -radius; rx <= radius; rx++) {
        //                 auto kernel_pixels = ran_img.getPixel(x + rx, y + ry);

        //                 r += kernel_pixels[0];
        //                 g += kernel_pixels[1];
        //                 b += kernel_pixels[2];
        //             }
        //         }

        //         r += ((radius*2 + 1)*(radius*2 + 1));
        //         g += ((radius*2 + 1)*(radius*2 + 1));
        //         b += ((radius*2 + 1)*(radius*2 + 1));

        //         ran_img.m_bitmapData[y][x*3] = r;
        //         ran_img.m_bitmapData[y][x*3 + 1] = g;
        //         ran_img.m_bitmapData[y][x*3 + 2] = b;
        //     }
        // }
        // ran_img.save("random_design.jpeg", 100);

/////////////////////////////////////////////////////////
// Brightness and Contrast Modification
        // https://docs.opencv.org/3.4/d3/dc1/tutorial_basic_linear_transform.html


/////////////////////////////////////////////////////////////
        // Image trialguy(1920,1080);
        // for(size_t i=0; i<trialguy.getWidth(); i++){
        //     for(size_t j=0;j<trialguy.getHeight();j++){
        //         std::vector<uint8_t> temp {255, 100, 100};
        //         trialguy.setPixel(i,j,temp);
        //     }
        // }
        // trialguy.save("Trial.jpeg", 100);

        // std::cout << "\nImage height: " << img.getHeight();
        // std::cout << "\nImage width : " << img.getWidth();
        // // Pixel "Size" is 3 bytes for colour images (i.e. R,G, & B)
        // // and 1 byte for monochrome.
        // std::cout << "\nImage px sz : " << img.getPixelSize();
        // std::cout << std::endl;
        return 0;
    }
    catch( const std::exception& e )
    {
        std::cout << "Main() error handler: ";
        std::cout << e.what() << std::endl;
        return 1;
    }
}

/*
Done:
1. Masking
2. Cropping
3. Mirror invert horizontally
4. Mirror invert vertically
5. Random design
6. Expand/Shrink/Resize
7. Grayscale
8. Blurring
9. Brightness and Contrast Modification
10. Luminance Modification
11. Edge Detection
12. Add padding
13. Color Inversion
*/

/* TODO
1. Rotation
2. Filters
*/