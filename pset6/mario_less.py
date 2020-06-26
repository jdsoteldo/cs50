from cs50 import get_int

while True:
    # happens while true
    height = get_int("Height: ")
    if height >= 1 and height <= 8:
        #breaks if users number is between 1 and 8
        break

for i in range(1, height + 1):
    spaces = height - i
    print(" " * spaces, end="")
    print("#" * i)
