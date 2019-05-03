# COMS4995-Project

# Table of Contents 
* [Introduction](#intro)
* [Getting Started](#get-started)
* [Documentation](#documentation)
  * [1. grayScale](#grayscale)
  * [2. flipHorizontal](#flipH)
  * [3. flipVertical](#flipV)
  * [4. blur](#blur)
  * [5. resize](#resize)
  * [6. edgeDetection](#edgeD)
  * [7. luminanceScaling](#luminance)
  * [8. cropImage](#crop)
  * [9. masking](#mask)
  * [10. brightnessMod](#brightness)
  * [11. contrastMod](#contrast)
  * [12. rotateAntiClockwise](#rotateAnti)
  * [13. rotateClockwise](#rotateClock)
  * [14. rotate180](#rotate180)
  * [15. padding](#padding)
  * [16. invert](#invert)
  * [17. save](#save)
* [Chaining](#chaining)

# <a name="intro"></a>Introduction
Image manipulation is one of the primary techniques used in Computer Vision research. It augments the data and provides meaningful insight into understanding the domain better. However, there are not many lightweight libraries available out there in C++, which provide a lucid interface for various image manipulations. This library caters to that. **ImgLibrary** is the library built in C++ which provides easy-to-use APIs to achieve image manipulations such as GreyScale conversion, luminance, brightness, and contrast modifications as well as rotations. 

# <a name="get-started"></a>Getting Started
To get started, clone this repository. <Add the steps>

# <a name="documentation"></a>Documentation
This section describes the various APIs provided by the library and their usage.

## <a name="grayscale"></a>1. grayScale
```
img.grayScale();
```
### Arguments
No arguments to be passed.

### Returns
The image object with the grayScale modification applied.

## <a name="flipH"></a>2. flipHorizontal
```
img.flipHorizontal();
```
### Arguments
No arguments to be passed.

### Returns
The image object flipped horizontally (around Y-axis).

## <a name="flipV"></a>3. flipVertical
```
img.flipVertical();
```
### Arguments
No arguments to be passed.

### Returns
The image object flipped vertically (around X-axis).

## <a name="blur"></a>4. blur
```
img.blur();
```
### Arguments
No arguments to be passed.

### Returns
The image object blurred.

## <a name="resize"></a>5. resize
```
img.resize(int newWidth);
```
### Arguments
Accepts an integer which is the new width of the image.

### Returns
If the new width passed in the argument is greater than the original width, it returns an image expanded to the new width. The new height is calculated proportionately. Similarly, if the new width is smaller than the original width, the new image is shrunk and returned.

## <a name="edgeD"></a>6. edgeDetection
```
img.edgeDetection();
```
### Arguments
No arguments to be passed.

### Returns
The image object with edges in the original image highlighted.

## <a name="luminance"></a>7. luminanceScaling
```
img.luminanceScaling(int factor);
```
### Arguments
Accepts an integer factor by which the luminance of the image will be scaled.

### Returns
The image object with scaled luminance.

### Throws 
Out of range errors if the luminance factor is beyond the acceptable range, which is 0-10.

## <a name="crop"></a>8. cropImage
```
img.cropImage(int xOffset, int yOffset, int xWidth, int yHeight);
```
### Arguments
xOffset - the x co-ordinate from where the image has to be cropped.
yOffset - the y co-ordinate from where the image has to be cropped.
xWidth - the length of the image along the X-axis that has to be cropped.
yHeight - the length of the image along the Y-axis that has to be cropped.

### Returns
A new image object cropped per above specifications.

### Throws
Out of range errors when the offsets or lengths passed in the arguments are beyond the height or width of the image.

## <a name="mask"></a>9. masking
```
img.masking(int xOffset, int yOffset, int xWidth, int yHeight);
```
### Arguments
xOffset - the x co-ordinate from where the image has to be masked.
yOffset - the y co-ordinate from where the image has to be masked.
xWidth - the length of the image along the X-axis that has to be masked.
yHeight - the length of the image along the Y-axis that has to be masked.

### Returns
A new image object masked per above specifications.

### Throws
Out of range errors when the offsets or lengths passed in the arguments are beyond the height or width of the image.
 
## <a name="brightness"></a>10. brightnessMod
```
img.brightnessMod(double beta);
```
### Arguments
Accepts a double value which specifies the brightness factor.

### Returns
The image object with brightness applied.

### Throws
Out of range errors when the brightness value is beyond the permissible range.

## <a name="contrast"></a>11. contrastMod
```
img.contrastMod(double alpha);
```
### Arguments
Accepts a double value which specifies the contrast factor.

### Returns
The image object with modified contrast.

### Throws
Out of range errors when the contrast value is beyond the permissible range.


## <a name="rotateAnti"></a>12. rotateAntiClockwise
```
img.rotateAntiClockwise();
```
### Arguments
No arguments to be passed.

### Returns
The image object rotated by 90 degrees in the anticlockwise direction.


## <a name="rotateClock"></a>13. rotateClockwise
```
img.rotateClockwise();
```
### Arguments
No arguments to be passed.

### Returns
The image object rotated by 90 degrees in the clockwise direction.


## <a name="rotate180"></a>14. rotate180
```
img.rotate180();
```
### Arguments
No arguments to be passed.

### Returns
The image object rotated by 180 degrees.

## <a name="padding"></a>15. padding
```
img.padding(int pad);
```
### Arguments
The integer value representing the pixel value of padding to be added on one side. Note that the same padding value will be added to all the sides of the image.

### Returns
The image object with padding added on all sides.

## <a name="invert"></a>16. invert
```
img.invert();
```
### Arguments
No arguments to be passed.

### Returns
The image object with its colors inverted.

## <a name="save"></a>17. save
```
img.save(char *fileName, int quality);
```
### Arguments
The fileName with which the new object will be saved. The quality of the saved image. A value of 100 would be the best possible quality.

### Returns
The image object.

# <a name="chaining"></a>Chaining
We also provide a chaining functionality to call multiple APIs together as follows. For example, to get a grayscale image, rotate by 90 degrees, add padding and then save, we could call the above APIs as follows:

```
img.grayScale().rotateAntiClockwise().padding(16).save("output.jpeg", 100);
```
