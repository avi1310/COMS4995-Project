#include <stdio.h>
#include <chrono>
#include <opencv4/opencv2/opencv.hpp>
using namespace std;
#include <iostream>
using namespace cv;

void printElapsedTime(chrono::high_resolution_clock::time_point start,  chrono::high_resolution_clock::time_point end) {
    cout << "Elapsed time in milliseconds "
    <<chrono::duration_cast<chrono::milliseconds>(end - start).count()
    << " ms" <<endl;
}

void computeGrayscaleCV() {
    auto start = chrono::high_resolution_clock::now();
    Mat image = imread("test.jpg");
    Mat output;
    cvtColor(image, output, COLOR_BGR2GRAY);
    imwrite( "output_opencv.jpeg", output);
    auto end = chrono::high_resolution_clock::now();
    cout<<"Time taken for Open CV Grayscale: "<<endl;
    printElapsedTime(start, end);
}

void computeRotateClockwiseCV() {
    auto start = chrono::high_resolution_clock::now();
    Mat image = imread("test.jpg");
    Mat output;
    rotate(image, output, ROTATE_90_CLOCKWISE);
    imwrite( "output_opencv.jpeg", output);
    auto end = chrono::high_resolution_clock::now();
    cout<<"Time taken for Open CV Rotate Clockwise: "<<endl;
    printElapsedTime(start, end);
}

void computeRotateAntiClockwiseCV() {
    auto start = chrono::high_resolution_clock::now();
    Mat image = imread("test.jpg");
    Mat output;
    rotate(image, output, ROTATE_90_COUNTERCLOCKWISE);
    imwrite( "output_opencv.jpeg", output);
    auto end = chrono::high_resolution_clock::now();
    cout<<"Time taken for Open CV Rotate AntiClockwise: "<<endl;
    printElapsedTime(start, end);
}

void computeRotate180CV() {
    auto start = chrono::high_resolution_clock::now();
    Mat image = imread("test.jpg");
    Mat output;
    rotate(image, output, ROTATE_180);
    imwrite( "output_opencv.jpeg", output);
    auto end = chrono::high_resolution_clock::now();
    cout<<"Time taken for Open CV Rotate 180: "<<endl;
    printElapsedTime(start, end);
}

void computeFlipVerticalCV() {
    auto start = chrono::high_resolution_clock::now();
    Mat image = imread("test.jpg");
    Mat output;
    flip(image, output ,0);
    imwrite( "output_opencv.jpeg", output);
    auto end = chrono::high_resolution_clock::now();
    cout<<"Time taken for Open CV Flip Vertical: "<<endl;
    printElapsedTime(start, end);
}

void computeFlipHorizontalCV() {
    auto start = chrono::high_resolution_clock::now();
    Mat image = imread("test.jpg");
    Mat output;
    flip(image, output ,1);
    imwrite( "output_opencv.jpeg", output);
    auto end = chrono::high_resolution_clock::now();
    cout<<"Time taken for Open CV Flip Horizontal: "<<endl;
    printElapsedTime(start, end);
}

void computeBlurCV() {
    auto start = chrono::high_resolution_clock::now();
    Mat image = imread("test.jpg");
    Mat output;
    GaussianBlur(image, output, Size(3, 3), 0);
    imwrite( "output_opencv.jpeg", output);
    auto end = chrono::high_resolution_clock::now();
    cout<<"Time taken for Open CV Blur: "<<endl;
    printElapsedTime(start, end);
}

void computeInvertCV() {
    auto start = chrono::high_resolution_clock::now();
    Mat image = imread("test.jpg");
    Mat output;
    threshold(image, output,70, 255, THRESH_BINARY_INV);
    imwrite( "output_opencv.jpeg", output);
    auto end = chrono::high_resolution_clock::now();
    cout<<"Time taken for Open CV Invert: "<<endl;
    printElapsedTime(start, end);
}

int main()
{
    try
    {
        auto startCV = chrono::high_resolution_clock::now();
        computeGrayscaleCV();
        computeRotateClockwiseCV();
        computeRotateAntiClockwiseCV();
        computeRotate180CV();
        computeFlipVerticalCV();
        computeFlipHorizontalCV();
        computeBlurCV();
        computeInvertCV();
        auto endCV = chrono::high_resolution_clock::now();
        cout<<"Total Time for running Open CV functions:"<<endl;
        printElapsedTime(startCV, endCV);
        
    }
    catch( const std::exception& e )
    {
        std::cout << "Main() error handler: ";
        std::cout << e.what() << std::endl;
        return 1;
    }
}
