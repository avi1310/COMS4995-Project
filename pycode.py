import ImgLibrary

img = ImgLibrary.ImgLibrary("test.jpg")
temp = ImgLibrary.ImgLibrary()

img.grayScale().flipHorizontal().flipVertical().blur()
# img.edgeDetection()
# img.luminanceScaling(int factor)
img.padding(20)
img.save("output_padded.jpg")
img.cropImage(20,20,1920,1080)
img.save("output_cropped.jpg")
temp = img
temp.masking(50,50,50,50)
temp.save("output_masked.jpg")
img.brightnessMod(1.5).contrastMod(1.5)
img.rotateAntiClockwise().rotateClockwise().rotate180()
img.invert();
img.save("output_inverted_rotate.jpg")

# somecode = cppimport.imp("ImgLibrary")