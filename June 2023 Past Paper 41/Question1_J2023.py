DataArray = [] * 25 #25 elements as INTEGER
try:
    f = open("Data.txt", "r")
    for i in f:
        DataArray.append(int(i))
    f.close()
except IOError:
    print("File not found.")

def PrintArray(DataArray):
    for i in range(25):
        print(DataArray[i], end = " ")
PrintArray(DataArray)

print(" ")
def LinearSearch(DataArray, SearchValue):
    count = 0
    for i in DataArray:
        if int(i) == SearchValue:
            count = count + 1
    return count

UserNumber = int(input("Enter an integer value between 0 and 100: "))
while UserNumber < 0 or UserNumber > 100:
    print("Value out of range.")
    UserNumber = int(input("Re-enter value: "))
Result = LinearSearch(DataArray, UserNumber)
print("The number", UserNumber, "is found", Result, "times.")