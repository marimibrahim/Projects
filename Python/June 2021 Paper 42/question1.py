class node:
    #self.data declared as INTEGER
    #self.nextNode declared as INTEGER
    def __init__(self, data, nextNode):
        self.data = data
        self.nextNode = nextNode

linkedList = [node(1, 1), node(5, 4), node(6, 7), node(7, -1), node(2, 2), node(0, 6), node(0, 8), node(56, 3), node(0, 9), node(0, -1)]
startPointer = 0
emptyList = 5

def outputNodes(linkedList, startPointer):
    while startPointer != -1:
        print(linkedList[startPointer].data)
        startPointer = linkedList[startPointer].nextNode

outputNodes(linkedList, startPointer)

def addNode(linkedList, startPointer, emptyList):
    Value = int(input("Enter the value to be added"))
    if emptyList < 0 or emptyList > 9:
        return False
    else:
        newNode = node(Value, -1)
        NewEmptyList = linkedList[emptyList].nextNode
        PreviousPointer = 0
        while startPointer != -1:
            PreviousPointer = startPointer
            startPointer = linkedList[startPointer].nextNode
        linkedList[PreviousPointer].nextNode = emptyList
        linkedList[emptyList] = newNode
        emptyList = NewEmptyList
        return True

outputNodes(linkedList, startPointer)
Result = addNode(linkedList, startPointer, emptyList)
if Result == True:
    print("Value added")
else:
    print("Value not added")
outputNodes(linkedList, startPointer)
