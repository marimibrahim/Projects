#DataArray is an array of type INTEGER which was 100 spaces
DataArray = []

def ReadFile():
    global DataArray
    try:
        f = open("IntegerData.txt", "r")
        for i in range(100):
            line = f.readline().strip()
            DataArray.append(int(line))
        f.close()
    except IOError:
        print("File not found")

def FindValues():
    global DataArray
    Total = 0
    UserNumber = int(input("Enter a number (from 1 to 100)"))
    while UserNumber < 1 or UserNumber > 100:
        print("Invalid number. Re-enter.")
        UserNumber = int(input("Enter a number (from 1 to 100)"))
    for i in range(100):
        if DataArray[i] == UserNumber:
            Total = Total + 1
    return Total

ReadFile()
Total = FindValues()
print("The number of times the number was found in the array is", Total)

def BubbleSort():
    global DataArray
    for i in range(len(DataArray) - 1):
        for j in range(len(DataArray) - i - 1):
            if DataArray[j] > DataArray[j + 1]:
                Temp = DataArray[j]
                DataArray[j] = DataArray[j + 1]
                DataArray[j + 1] = Temp
    for i in range(100):
        print(DataArray[i])

BubbleSort()