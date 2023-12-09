import string
from cs50 import get_string

lett = 0
senten = 0
content = get_string("Text: ")

for j in content:
    if (j.isalpha()):
        lett += 1

word = len(content.split())

for l in content:
    if (l == '.' or l == '?' or l == '!'):
        senten += 1

wordsinsentence = word / 100

s = senten / wordsinsentence
l = lett / wordsinsentence

indx = round(0.0588 * l - 0.296 * s - 15.8)

if indx < 1 :
    print("Before Grade 1")
elif indx >= 16:
    print("Grade 16+")
else:
    print(f"Grade {indx}")
