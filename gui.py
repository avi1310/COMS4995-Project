import tkinter as tk
from tkinter import *
# from Tkinter import *
from PIL import ImageTk, Image, ImageFilter
import ImgLibrary
import matplotlib.image as mpimg
import sys
import numpy as np

image_path = None
PATH = None

def greyScale(path):
    # return img
    ImgLibrary.ImgLibrary(path).grayScale().save('output_temp.jpeg')
    return 'output_temp.jpeg'

def rotateClockwise(path):
    # return img
    ImgLibrary.ImgLibrary(path).rotateClockwise().save('output_temp.jpeg')
    return 'output_temp.jpeg'

def rotateAntiClockwise(path):
    ImgLibrary.ImgLibrary(path).rotateAntiClockwise().save('output_temp.jpeg')
    return 'output_temp.jpeg'

def rotate180(path):
    ImgLibrary.ImgLibrary(path).rotate180().save('output_temp.jpeg')
    return 'output_temp.jpeg'

def blur(path):
    # return img
    ImgLibrary.ImgLibrary(path).blur().save('output_temp.jpeg')
    return 'output_temp.jpeg'

def flipHorizontal(path):
    ImgLibrary.ImgLibrary(path).flipHorizontal().save('output_temp.jpeg')
    return 'output_temp.jpeg'

def flipVertical(path):
    ImgLibrary.ImgLibrary(path).flipVertical().save('output_temp.jpeg')
    return 'output_temp.jpeg'

def edgeDetection(path):
    ImgLibrary.ImgLibrary(path).edgeDetection().save('output_temp.jpeg')
    return 'output_temp.jpeg'

def invert(path):
    ImgLibrary.ImgLibrary(path).invert().save('output_temp.jpeg')
    return 'output_temp.jpeg'

def luminanceScaling(path):
    ImgLibrary.ImgLibrary(path).luminanceScaling(2).save('output_temp.jpeg')
    return 'output_temp.jpeg'

def cropImage(path):
    ImgLibrary.ImgLibrary(path).cropImage(100, 100, 200, 200).save('output_temp.jpeg')
    return 'output_temp.jpeg'

def masking(path):
    ImgLibrary.ImgLibrary(path).masking(100, 100, 100, 100).save('output_temp.jpeg')
    return 'output_temp.jpeg'

def brightnessMod(path):
    ImgLibrary.ImgLibrary(path).brightnessMod(1.5).save('output_temp.jpeg')
    return 'output_temp.jpeg'

def contrastMod(path):
    ImgLibrary.ImgLibrary(path).contrastMod(2).save('output_temp.jpeg')
    return 'output_temp.jpeg'

def padding(path):
    ImgLibrary.ImgLibrary(path).padding(15).save('output_temp.jpeg')
    return 'output_temp.jpeg'

def option_changed(variable, panel, path):
    global PATH
    PATH = path
    print(variable.get())
    if variable.get() == "grayScale":
        img_out_path = greyScale(PATH)
    elif variable.get() == "rotateClockwise":
        img_out_path = rotateClockwise(PATH)
    elif variable.get() == "blur":
        img_out_path = blur(PATH)
    elif variable.get() == "rotateAntiClockwise":
        img_out_path = rotateAntiClockwise(PATH)
    elif variable.get() == "rotate180":
        img_out_path = rotate180(PATH) 
    elif variable.get() == "flipHorizontal":
        img_out_path = flipHorizontal(PATH)
    elif variable.get() == "flipVertical":
        img_out_path = flipVertical(PATH)  
    elif variable.get() == "edgeDetection":
        img_out_path = edgeDetection(PATH)
    elif variable.get() == "invert":
        img_out_path = invert(PATH)
    elif variable.get() == "luminanceScaling":
        img_out_path = luminanceScaling(PATH)
    elif variable.get() == "cropImage":
        img_out_path = cropImage(PATH)
    elif variable.get() == "masking":
        img_out_path = masking(PATH)
    elif variable.get() == "brightnessMod":
        img_out_path = brightnessMod(PATH)
    elif variable.get() == "contrastMod":
        img_out_path = contrastMod(PATH)
    elif variable.get() == "padding":
        img_out_path = padding(PATH)

    variable.set(variable.get())
    img = ImageTk.PhotoImage(Image.open(img_out_path))
    panel.configure(image=img)
    panel.img = img  # keep a reference     
    PATH = img_out_path

def show_gui(path):
    global PATH
    window = tk.Tk()
    window.title("ImgLibrary App")
    PATH = path
    img = ImageTk.PhotoImage(Image.open(path))
    h = img.height() + 350
    w = img.width() + 10
    geom = str(h) + "x" + str(w)
    print(geom)
    window.geometry(geom)
    panel = tk.Label(window, image=img)
    # panel.pack(side="bottom", fill="both", expand="yes")
    panel.place(relx=0.0, rely=0.0, anchor="nw")

    apis = ["rotateClockwise", "rotateAntiClockwise", "rotate180", "flipHorizontal", "grayScale", "blur",
            "flipVertical", "luminanceScaling", "brightnessMod", "contrastMod",
            "cropImage", "masking", "padding",
            "edgeDetection", "invert"]
    variable = StringVar(window)
    variable.set(apis[0]) # default
    variable.trace("w", lambda *args: option_changed(variable, panel, PATH))
    w = OptionMenu(window, variable, *apis)
    w.pack(side="top", anchor="e")
    window.mainloop()


if __name__ == "__main__":
    if len(sys.argv) < 2:
        raise ValueError
    show_gui(sys.argv[1])