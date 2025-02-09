arrayData = [10, 5, 6, 7, 1, 12, 13, 15, 21, 8]

def linearSearch(Value):
    for i in range(len(arrayData)):
        if arrayData[i] == Value:
            return True
    return False

UserValue = int(input("Enter the value to be searched for"))
Result = linearSearch(UserValue)
if Result == True:
    print("Value was found")
else:
    print("Value was not found")

def bubbleSort():
    for x in range(10):
        for y in range(9):
            if arrayData[y] > arrayData[y + 1]:
                temp = arrayData[y]
                arrayData[y] = arrayData[y + 1]
                arrayData[y + 1] = temp
