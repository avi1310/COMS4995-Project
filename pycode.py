import ImgLibrary

img = ImgLibrary.ImgLibrary("test.jpg")
img.rotateAntiClockwise().rotateClockwise().rotate180().invert().rotate180().padding(16).save("output.jpg")
# somecode = cppimport.imp("ImgLibrary")