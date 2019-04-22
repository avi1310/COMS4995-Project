#include "jpeg.h"
using namespace std;
#include <iostream>
#include <map>
#include "imgLibrary.h"

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
        using namespace marengo::jpeg;
        // Constructor expects a filename to load:
        Image imgOriginal( argv[1] );
        Image img = imgOriginal;
        // Copy construct a second version so we can
        // shrink non-destructively. Not really necessary
        // here, but just to show it can be done :)
        imgLibrary testImg1(argv[1]);
//        testImg1.grayScale();
//        testImg1.save("output1.jpeg");
//        testImg1.flipHorizontal();
//        testImg1.save("flip.jpeg");
//        testImg1.flipVertical();
//        testImg1.save("fVert.jpeg");
//        testImg1.blur();
//        testImg1.save("blur.jpeg");
//        testImg1.resize(400);
//        testImg1.save("resized.jpeg");
        testImg1.edgeDetection();
        testImg1.save("edgeDetection.jpeg");


        // Image dup_g = Image(img.m_height, img.m_width, img.m_pixelSize);
        // Shrink proportionally to a specific width (in px)
        // img.shrink( 60 );
        // dupImg.shrink(60);

        // Display the image in ASCII, just for fun.
        size_t height = img.getHeight();
        size_t width  = img.getWidth();
        for ( size_t y = 0; y < height; ++y )
        {
            for ( size_t x = 0; x < width; ++x )
            {
                uint8_t luma = img.getLuminance( x, y );
                display( luma );
            }
            std::cout << "\n";
        }

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


////////////////////////////////////////////////////////
        // Crop
        Image to_crop( argv[1] );
        Image t = to_crop;
        
        // int xOffset = 100, yOffset = 100, xWidth = 200, yWidth = 200;

        // for(size_t y = 0; y < height; y++) {
        //     for(size_t x = 0; x < width; x++) {
        //         if((int)x < xOffset || (int)x > (xWidth + xOffset)) { // crop
        //             // pixels = t.getPixel(x, y);
        //             int i = 0;
        //             for(; i < 3; i++) {
        //                 t.m_bitmapData[y][x*3 + i] = 255;
        //             }
        //         }
        //         if((int)y < yOffset || (int)y > (yWidth + yOffset)) { // crop
        //             // pixels = t.getPixel(x, y);
        //             int i = 0;
        //             for(; i < 3; i++) {
        //                 t.m_bitmapData[y][x*3 + i] = 255;
        //             }
        //         }
        //     }
        // }
        // t.save("Cropped.jpeg", 100);

//////////////////////////////////////////////////////////////
// Masking
        Image to_mask( argv[1] );
        Image t_m = to_mask;
        
        // int xOffset = 100, yOffset = 100, xWidth = 200, yWidth = 200;

        // for(size_t y = 0; y < height; y++) {
        //     for(size_t x = 0; x < width; x++) {
        //         if((int)y >= yOffset && (int)y <= (yWidth + yOffset) && (int)x >= xOffset && (int)x <= (xWidth + xOffset)) { // mask
        //             int i = 0;
        //             for(; i < 3; i++) {
        //                 t.m_bitmapData[y][x*3 + i] &= 0x00;
        //             }
        //         }
        //     }
        // }
        // t.save("Masked.jpeg", 100);

/////////////////////////////////////////////////////////
// Brightness and Contrast Modification
        // https://docs.opencv.org/3.4/d3/dc1/tutorial_basic_linear_transform.html
        Image bc_image(argv[1]);
        Image origImg(argv[1]);
        Image bc_i = bc_image;

        // double alpha = 2.3; // to control contrast
        // double beta = 20; // to control brightness

        // // transformation, f(i, j) = alpha*g(i,j) + beta
        // for(size_t y = 0; y < height; y++) {
        //     for(size_t x = 0; x < width; x++) {
        //         // auto pixels = origImg.getPixel(x, y);
        //         int i = 0;
        //         for(; i < 3;) {
        //             int val = (int)(alpha*origImg.m_bitmapData[y][x*3 + i] + beta);
        //             if(val > 255) {
        //                 val = 255;
        //             }
        //             bc_i.m_bitmapData[y][x*3 + i] = val;
        //             i++;
        //         }
        //     }
        // }
        // bc_i.save("brightness_and_contrast.jpeg", 100);

///////////////////////////////////////////////////////////////////
    // Luminance Modification
        Image lum_image(argv[1]);
        Image lum_i = lum_image;

        // cout<<"Enter Luminance factor. We will scale up by this value."<<endl;
        // int lll;
        // cin>>lll;

        // for(size_t y = 0; y < height; y++) {
        //     for(size_t x = 0; x < width; x++) {
        //         auto pixels = lum_i.getPixel(x, y);
        //         uint8_t a = (pixels[0] * 2)*lll/6;
        //         uint8_t b = (pixels[1] * 3)*lll/6;
        //         uint8_t c = (pixels[2])*lll/6;
        //         lum_i.m_bitmapData[y][x*3] = a;
        //         lum_i.m_bitmapData[y][x*3 + 1] = b;
        //         lum_i.m_bitmapData[y][x*3 + 2] = c;
        //     }
        // }
        // lum_i.save("luminance_modified.jpeg", 100);

///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
        // Edge detection
        Image edge_dec( argv[1] );
        Image edge = edge_dec;

        // float kernel[3][3] = {
        //     {-1, -1, -1},
        //     {-1, 8, -1},
        //     {-1, -1, -1},
        // };
        // float kernel[3][3] = {
        //     {-1, -1, -1},
        //     {2, 2, 2},
        //     {-1, -1, -1},
        // };

        // float kernel[3][3] = {
        //     {-1, 2, -1},
        //     {-1, 2, -1},
        //     {-1, 2, -1},
        // };

        // float kernel[3][3] = {
        //     {-1, -1, 2},
        //     {-1, 2, -1},
        //     {2, -1, -1},
        // };

        // for(size_t y = 0; y < height; y++) {
        //     for(size_t x = 0; x < width; x++) {
        //        // auto pixels = blur.getPixel(x, y);
        //         blur.m_bitmapData[y][x*3] = 0.0;
        //         blur.m_bitmapData[y][x*3 + 1] = 0.0;
        //         blur.m_bitmapData[y][x*3 + 2] = 0.0;
        //     }
        // }
        // cout<<"Reached here"<<endl;
        // for(size_t y = 1; y < height-1; y++) {
        //     for(size_t x = 1; x < width-1; x++) {
        //         // float sum[3] = {0.0, 0.0, 0.0};
        //         float sum = 0.0;
        //         for(int k = -1; k <= 1; k++) {
        //             for(int j = -1; j <= 1; j++) {
        //                 // cout<<"Now"<<x<<' '<<y<<endl;
        //                 auto pixels = orig_m.getPixel(x - k, y - j);
        //                 // int i=0;
        //                 for(auto &p: pixels) {
        //                     // sum[i] = sum[i] + kernel[j+1][k+1]*p;
        //                     // i++;
        //                     sum = sum + kernel[j+1][k+1]*p;
        //                 }
        //             }
        //         }
        //         blur_img.m_bitmapData[y][x*3] = sum;
        //         blur_img.m_bitmapData[y][x*3 + 1] = sum;
        //         blur_img.m_bitmapData[y][x*3 + 2] = sum;
        //     }
        // }

        // blur_img.save("edge_2.jpeg", 100);
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////

        // Rotate CCW
        // Image orig_r(argv[1]);
        // Image new_r(argv[1]);
        // Image o_r = orig_r;
        // Image n_r = new_r;

        // // or = 375 h, 500 w
        // // nr = 500 h, 375 w
        // n_r.m_width = o_r.m_height;
        // n_r.m_height = o_r.m_width;

        // n_r.m_bitmapData.resize(n_r.m_height);
        // for(int i = 0; i < (int)n_r.m_height; i++) {
        //     n_r.m_bitmapData[i].resize(n_r.m_width*3);
        // }
        // for(size_t y = 0; y < o_r.m_height; y++) {
        //     for(size_t x = 0; x < o_r.m_width; x++) {
        //         n_r.setPixel(y, x, o_r.getPixel(o_r.m_width - 1 - x, y));
        //     }
        // }
        // n_r.save("rotate90.jpeg", 100);

/////////////////////////////////////////////////////////
        // Rotate CW
        // Image orig_r(argv[1]);
        // Image new_r(argv[1]);
        // Image o_r = orig_r;
        // Image n_r = new_r;

        // // or = 375 h, 500 w
        // // nr = 500 h, 375 w
        // n_r.m_width = o_r.m_height;
        // n_r.m_height = o_r.m_width;

        // n_r.m_bitmapData.resize(n_r.m_height);
        // for(int i = 0; i < (int)n_r.m_height; i++) {
        //     n_r.m_bitmapData[i].resize(n_r.m_width*3);
        // }
        // for(int y = (int)o_r.m_height - 1; y>=0 ; y--) {
        //     for(size_t x = 0; x < o_r.m_width; x++) {
        //         cout<<x<<' '<<y<<endl;
        //         n_r.setPixel(y, x, o_r.getPixel(x, o_r.m_height - 1 - y));
        //     }
        // }
        // n_r.save("rotate90_2.jpeg", 100);

///////////////////////////////////////////////////////////
        // Rotate 180

        Image orig_r(argv[1]);
        Image new_r(argv[1]);
        Image o_r = orig_r;
        Image n_r = new_r;

        // or = 375 h, 500 w
        // nr = 500 h, 375 w
        // n_r.m_width = o_r.m_height;
        // n_r.m_height = o_r.m_width;

        // n_r.m_bitmapData.resize(n_r.m_height);
        // for(int i = 0; i < (int)n_r.m_height; i++) {
        //     n_r.m_bitmapData[i].resize(n_r.m_width*3);
        // }
        // for(size_t y = 0; y < o_r.m_height ; y++) {
        //     for(size_t x = 0; x < o_r.m_width; x++) {
        //         // cout<<x<<' '<<y<<endl;
        //         n_r.setPixel(o_r.m_width - 1 - x, o_r.m_height - 1 - y, o_r.getPixel(x, y));
        //     }
        // }
        // n_r.save("rotate180.jpeg", 100);

////////////////////////////////////////////////////////////////

        // Add padding
        Image add_pad(argv[1]);
        Image a_p = add_pad;

        // for(size_t x = 0; x < a_p.getHeight(); x++) {
        //     for(int k = 0; k < 51; k++) {
        //         a_p.m_bitmapData[x].insert(a_p.m_bitmapData[x].begin(), 0);
        //         a_p.m_bitmapData[x].push_back(0);
        //     }
        // }
        // a_p.m_width += 32;
        // for(int k = 0; k < 16; k++) {
        //     vector<uint8_t> v;
        //     for(int i = 0; i < (int)a_p.m_width*3; i++) {
        //         v.push_back(0);
        //     }
        //     a_p.m_bitmapData.insert(a_p.m_bitmapData.begin(), v);
        //     a_p.m_bitmapData.push_back(v);
        // }
        
        // a_p.m_height += 32;
        // a_p.save("add_pad.jpeg", 100);

        // for ( size_t y = 0; y < height; ++y )
        // {
        //     for ( size_t x = 0; x < width; ++x )
        //     {
        //         uint8_t luma = dupImg.getLuminance( x, y );
        //         // display( luma );
        //     }
        //     std::cout << "\n";
        // }


//////////////////////////////////////////////////////////////
        // Invert image
        // Image inv_image(argv[1]);
        // Image i_v = inv_image;
        // Image n_v(argv[1]);
        // for(size_t y = 0; y < height; y++) {
        //     for(size_t x = 0; x < width; x++) {
        //         auto pixels = i_v.getPixel(x, y);
        //         int i = 0;
        //         for(; i < 3; i++) {
        //             n_v.m_bitmapData[y][x*3 + i] = ~i_v.m_bitmapData[y][x*3 + i];
        //         }
        //     }
        // }

        // n_v.save("Inverted.jpeg", 100);



/////////////////////////////////////////////////////////////
//        Image trialguy(1920,1080);
//        for(size_t i=0; i<trialguy.getWidth(); i++){
//            for(size_t j=0;j<trialguy.getHeight();j++){
//                std::vector<uint8_t> temp {255, 100, 100};
//                trialguy.setPixel(i,j,temp);
//            }
//        }
//        trialguy.save("Trial.jpeg", 100);
//
//        std::cout << "\nImage height: " << img.getHeight();
//        std::cout << "\nImage width : " << img.getWidth();
//        // Pixel "Size" is 3 bytes for colour images (i.e. R,G, & B)
//        // and 1 byte for monochrome.
//        std::cout << "\nImage px sz : " << img.getPixelSize();
//        std::cout << std::endl;
//        return 0;
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