DataArray = []

try:
    f = open("Data.txt", "r")
    for i in range(25):
        line = int(f.readline().strip())
        DataArray.append(line)
except IOError:
    print("File not found")

def PrintArray(Array):
    for i in range(len(Array)):
        print(Array[i], end="  ")
    print("")

def LinearSearch(Array, Value):
    Found = 0
    for i in range(len(Array)):
        if Array[i] == Value:
            Found = Found + 1
    return Found

PrintArray(DataArray)

Value = int(input("Enter a whole number between 0 and 100"))
while Value < 0 or Value > 100:
    print("Value out of range")
    Value = int(input("Enter a whole number between 0 and 100"))
Found = LinearSearch(DataArray, Value)
print("The number ", Value, " is found ", Found, " times.")