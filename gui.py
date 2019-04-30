import tkinter as tk
from tkinter import *
# from Tkinter import *
from PIL import ImageTk, Image, ImageFilter
import matplotlib.image as mpimg
import sys
import numpy as np

image_path = None
PATH = None


def greyScale(path):
    # return img
    orig = Image.open(path)
    grey = orig.convert('L')
    grey.save('grey.jpeg')
    return 'grey.jpeg'


def rotate90(path):
    # return img
    orig = Image.open(path)
    rot = orig.rotate(90)
    rot.save('rotate.jpeg')
    return 'rotate.jpeg'


def blur(path):
    # return img
    orig = Image.open(path)
    blur = orig.filter(ImageFilter.BLUR)
    blur.save('blur.jpeg')
    return 'blur.jpeg'


def option_changed(variable, panel, path):
    print(variable.get())
    if variable.get() == "greyScale":
        img_out_path = greyScale(path)
        variable.set(img_out_path)
        img = ImageTk.PhotoImage(Image.open(img_out_path))
        panel.configure(image=img)
        panel.img = img  # keep a reference
    elif variable.get() == "rotate90":
        img_out_path = rotate90(path)
        variable.set(img_out_path)
        img = ImageTk.PhotoImage(Image.open(img_out_path))
        panel.configure(image=img)
        panel.img = img  # keep a reference
    elif variable.get() == "blur":
        img_out_path = blur(path)
        variable.set(img_out_path)
        img = ImageTk.PhotoImage(Image.open(img_out_path))
        panel.configure(image=img)
        panel.img = img  # keep a reference


def show_gui(path):
    window = tk.Tk()
    window.title("ImgLibrary App")

    img = ImageTk.PhotoImage(Image.open(path))
    h = img.height() + 300
    w = img.width() + 10
    geom = str(h) + "x" + str(w)
    print(geom)
    window.geometry(geom)
    panel = tk.Label(window, image=img)
    # panel.pack(side="bottom", fill="both", expand="yes")
    panel.place(relx=0.0, rely=0.0, anchor="nw")

    apis = ["rotate90", "greyScale", "blur",
            "luminanceMod", "brightnessMod", "contrastMod",
            "crop", "mask", "padding", "rotate180",
            "edgeDetection", "invert"]
    variable = StringVar(window)
    variable.set(apis[0]) # default
    variable.trace("w", lambda *args: option_changed(variable, panel, path))
    w = OptionMenu(window, variable, *apis)
    w.pack(side="top", anchor="e")
    window.mainloop()


if __name__ == "__main__":
    if len(sys.argv) < 2:
        raise ValueError
    show_gui(sys.argv[1])