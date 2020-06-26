from cs50 import get_string

s = get_string("Do you agree?\n")

if s[0].lower() in ['y']:
    print("Agreed.")
elif s[0].lower() in ['n']:
    print("Not agreed.")
