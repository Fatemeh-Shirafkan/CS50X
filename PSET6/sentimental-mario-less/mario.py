from cs50 import get_int

while True :

    pyramidHeight = get_int("Height: ")

    if pyramidHeight >= 1 and pyramidHeight <= 8 :
        break
    else :
        continue

for j in range(pyramidHeight) :
    print(" " * (pyramidHeight - (j + 1)) + "#" * (j + 1))
