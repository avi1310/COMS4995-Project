import ImgLibrary

# Load an image from file
img = ImgLibrary.ImgLibrary("test.jpg")

# Create a new image. Currently useless, don't use!
temp = ImgLibrary.ImgLibrary()

img.grayScale().flipHorizontal().flipVertical().blur()

# Edge detection is wonky
# img.edgeDetection()

# Luminance scaling algorithm is wonky
# img.luminanceScaling(int factor)

img.padding(20)
img.save("output_padded.jpg")
img.cropImage(20,20,img.getWidth()-50,img.getHeight()-50)
img.save("output_cropped.jpg")

#Does not work. Deepcopy is not implemented. No idea how to.
temp = img

# temp now points to the object held by img.
temp.masking(50,50,50,50)
temp.save("output_masked.jpg")
img.brightnessMod(1.5).contrastMod(1.5)
img.rotateAntiClockwise().rotateClockwise().rotate180()
img.invert();
temp.save("output_inverted_rotate_temp.jpg")
img.save("output_inverted_rotate_img.jpg")

print(img.getHeight(), img.getWidth())

# somecode = cppimport.imp("ImgLibrary")