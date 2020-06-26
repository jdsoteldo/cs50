from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height >= 1 and height <= 8:
        # validates the user input is between 1 and 8
        # doesnt allow negatives number, letters nor greater than 8
        break

for i in range(1, height + 1):
    spaces = height - i
    # the lower the piramid the less space
    print(" " * spaces, end="")
    print("#" * i, end="")
    print("  ", end="")
    print("#" * i)
# make sure to eliminate the \n at the end so they all print in the same line
