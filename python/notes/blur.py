from PIL import Image, ImageFilter

before = Image.open("bridge.bmp")
after = before.filer(ImageFilter.BLUR)
after.save("bride_new.bmp")
