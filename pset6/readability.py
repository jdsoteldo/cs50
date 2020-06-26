letters = 0
words = 1
sentences = 0
text = input("Text: \n")
# use input instead of the get_string method from cs50
text_len = len(text)

for i in range(text_len):
    if text[i].isalpha():
        # verifies all the chars are letters and if so, adds one letter
        letters += 1
    elif text[i].isspace():
        # checks for spaces
        words += 1
    elif text[i] == '.' or text[i] == '!' or text[i] == '?':
        # if any dot (.) bangs (!) or question marks (?) and is so, adds one sentence, for that signifies the end of a sentence.
        sentences += 1

grade_level = round(0.0588 * ((100 * letters) / words) - 0.296 * ((100 * sentences) / words) - 15.8)
# Coleman-Liau index

if grade_level >= 1 and grade_level < 16:
    print(f"Grade: {grade_level}")
elif grade_level < 1:
    print("Before Grade 1")
else:
    print("Grade 16+")
