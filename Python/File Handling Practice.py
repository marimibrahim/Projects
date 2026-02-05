try:
    f = open("abc.txt", "w+")

    for i in range(1, 11):
        f.write(str(i) + "\n")

    for i in range(1, 11):
        f.write(str(i) + "\t")

    for i in range(1, 11):
        f.write(str(i) + "  ")

    f.close()
except IOError:
    print("File not found.")

try:
    f = open("abc.txt", "r")
    s = f.read()
    for i in s:
        print(i)
except IOError:
    print("File not found.")