from cs50 import get_int

x = get_int("x: ")
y = get_int("y: ")

if x < y:
    print("X is less than Y")
elif y < x:
    print("Y is less than X")
else:
    print("X and Y are equals.")
