
arrayData = [10, 5, 6, 7, 1, 12, 13, 15, 21, 8]

def linearSearch(Value):
    for i in range(10):
        if arrayData[i] == Value:
            return True
    return False

def bubbleSort():
    for x in range(10):
        for y in range(9):
            if theArray[y] < theArray[y + 1]:
                temp = theArray[y]
                theArray[y] = theArray[y + 1]
                theArray[y + 1] = temp


#main
Value = int(input("Enter the value to be searched for"))
Result = linearSearch(Value)
if Result == True:
    print("Value found in the array")
else:
    print("Value not found in the array")

