from cs50 import get_int

# prompt for card's cc_numbers
while True:
    credit_card = get_int("Credit Card Number: ")
    if credit_card > 0:
        break

# convert to string and get the card_size of the cc_numbers string
card_size = len(str(credit_card))

cc_numbers = list()
divisor = 1

# store each number in array
for i in str(credit_card):
    cc_numbers.append(int(i))

# reverse order
cc_numbers = cc_numbers[::-1]

# 1st sum
sum = 0
for i in range(1, card_size, 2):
    # 2 cases: product < 10 and >=10
    if cc_numbers[i] * 2 < 10:
        sum = sum + cc_numbers[i] * 2
    else:
        sum = sum + (cc_numbers[i] * 2) % 10 + ((cc_numbers[i] * 2) // 10) % 10

# 2nd sum
for i in range(0, card_size, 2):
    sum += cc_numbers[i]

# check the validity of the card number
if (sum % 10) != 0:
    print("INVALID")
else:
    if card_size == 15 and cc_numbers[card_size - 1] == 3 and (cc_numbers[card_size - 2] == 4 or cc_numbers[card_size - 2] == 7):
        print("AMEX")
    elif card_size == 16 and cc_numbers[card_size - 1] == 5 and (cc_numbers[card_size - 2] == 1 or cc_numbers[card_size - 2] == 2 or cc_numbers[card_size - 2] == 3 or cc_numbers[card_size - 2] == 4 or cc_numbers[card_size - 2] == 5):
        print("MASTERCARD")
    elif (card_size == 13 or card_size == 16) and cc_numbers[card_size - 1] == 4:
        print("VISA")
    else:
        print("INVALID")
