import ImgLibrary

# Load an image from file
img = ImgLibrary.ImgLibrary("test.jpg")

# Create a new image. Currently useless, don't use!
temp = ImgLibrary.ImgLibrary()

img.grayScale().flipHorizontal().flipVertical().blur()
img.padding(20)
img.save("output_padded.jpg")

img.cropImage(20,20,img.getWidth()-30, img.getHeight()-30)
img.save("output_cropped.jpg")

#Does not work. Deepcopy is not implemented.
temp = img

# temp now points to the object held by img.
temp.masking(50,50,50,50)
temp.save("output_masked.jpg")

# both temp and imp point to same object
img.brightnessMod(1.5).contrastMod(1.5)
img.rotateAntiClockwise().rotateClockwise().rotate180()
img.invert();

# Notice how both output the same image, even though they're different vars
temp.save("output_inverted_rotate_temp.jpg")
img.save("output_inverted_rotate_img.jpg")