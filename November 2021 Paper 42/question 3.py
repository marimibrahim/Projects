ArrayNodes = [[0 for i in range(3)] for j in range(20)]
RootPointer = -1
FreeNode = 0

def AddNode(ArrayNodes, RootPointer, FreeNode):
    NodeData = int(input("Enter the data"))
    if FreeNode <= 19:
        ArrayNodes[FreeNode][0] = -1
        ArrayNodes[FreeNode][1] = NodeData
        ArrayNodes[FreeNode][2] = -1
        if RootPointer == -1:
            RootPointer = 0
        else:
            Placed = False
            CurrentNode = RootPointer
            while Placed == False:
                if NodeData < ArrayNodes[CurrentNode][1]:
                    if ArrayNodes[CurrentNode][0] == -1:
                        ArrayNodes[CurrentNode][0] = FreeNode
                        Placed = True
                    else:
                        CurrentNode = ArrayNodes[CurrentNode][0]
                else:
                     if ArrayNodes[CurrentNode][2] == -1:
                         ArrayNodes[CurrentNode][2] = FreeNode
                         Placed = True
                     else:
                         CurrentNode = ArrayNodes[CurrentNode][2]
        FreeNode = FreeNode + 1
    else:
        print("Tree is full")
    return ArrayNodes, RootPointer, FreeNode

def InOrder(RootPointer):
        if RootPointer == -1:
            print("Tree is empty")
        else:
            if ArrayNodes[RootPointer][0] != -1:
                InOrder(ArrayNodes[RootPointer][0])
            print(ArrayNodes[RootPointer][1])
            if ArrayNodes[RootPointer][2] != -1:
                InOrder(ArrayNodes[RootPointer][2])

def PrintAll(ArrayNodes):
    for i in range(20):
        print(str(ArrayNodes[i][0]), end="\t")
        print(str(ArrayNodes[i][1]), end="\t")
        print(str(ArrayNodes[i][2]))

for i in range(10):
    ArrayNodes, RootPointer, FreeNode = AddNode(ArrayNodes, RootPointer, FreeNode)
PrintAll(ArrayNodes)
InOrder(RootPointer)