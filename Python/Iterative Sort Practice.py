Queue = [-1] * 100 #array declared as integer and initialised as empty
HeadPointer = -1 #declared as integer and initialised as -1 as the array is empty
TailPointer = 0 #declared as integer and initialised as 0 as the array is empty

def Enqueue(Data):
    global Queue
    global HeadPointer
    global TailPointer
    if TailPointer >= 100:
        return False
    else:
        if HeadPointer == -1:
            HeadPointer = 0
        Queue[TailPointer] = Data
        TailPointer = TailPointer + 1
        return True

for i in range(1, 21):
    Insert = Enqueue(i)
if Insert == False:
    print("Unsuccessful")
else:
    print("Successful")

def IterativeOutput(Start):
    global Queue
    if Start == 0:
        return Queue[Start]
    else:
        return Queue[Start] + IterativeOutput(Start - 1)

Total = IterativeOutput(TailPointer - 1)
print(str(Total))

#9618-s21-qp41
class node:
    def __init__(self, data, NextNode):
        self.data = data
        self.NextNode = NextNode

#linkedList = [node(0, 0)] * 10
#linkedList[0] = [node(1, 1)]
#linkedList[1] = [node(5, 4)]
#linkedList[2] = [node(6, 7)]
#linkedList[3] = [node(7, -1)]
#linkedList[4] = [node(2, 2)]
#linkedList[5] = [node(0, 6)]
#linkedList[6] = [node(0, 8)]
#linkedList[7] = [node(56, 3)]
#linkedList[8] = [node(0, 9)]
#linkedList[9] = [node(0, -1)]
startPointer = 0
emptyList = 5

linkedList = [node(1, 1), node(5, 4), node(6, 7), node(7, -1), node(2, 2), node(0, 6), node(0, 8), node(56, 3), node(0, 9), node(0, -1)]

def outputNodes(linkedList, currentPointer):
    while currentPointer != -1:
        print(str(linkedList[currentPointer].data))
        currentPointer = linkedList[currentPointer].NextNode

outputNodes(linkedList, startPointer)

def addNode(linkedList, startPointer, emptyList):
    DataAdded = int(input("Enter the data to be added"))
    if emptyList < 0 or emptyList > 9:
        return False
    else:
        NewNode = node(DataAdded, -1)
        temp = linkedList[emptyList].nextNode
        linkedList[emptyList] = NewNode

        PreviousPointer = 0
        while startPointer != 1:
            PreviousPointer = startPointer
            startPointer = linkedList[startPointer].NextNode
        linkedList[PreviousPointer].nextNode = emptyList
        emptyList = temp
        return True

outputNodes(linkedList, startPointer)
Result = addNode(linkedList, startPointer, emptyList)
if Result == False:
    print("Data not added")
else:
    print("Data added")
outputNodes(linkedList, startPointer)