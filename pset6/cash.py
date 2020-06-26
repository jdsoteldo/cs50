from cs50 import get_float

while True:
    cents = get_float("How much are you owed?\n")
    # prompts the user for a numeric input
    dollars = round(cents * 100)

    if cents > 0:
        # the program keeps asking for as long as the input is lower than 0
        break

quarters = dollars // 25
# the // is use to do floor divisions
# % modulus operator
dimes = (dollars % 25) // 10
nickels = ((dollars % 25) % 10) // 5
pennies = ((dollars % 25) % 10) % 5

print(f"Minimum amount of coins: {quarters + dimes + nickels + pennies}")
#prints the minimum amount of coins possible
