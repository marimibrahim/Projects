ArrayNodes = [[(-1) for i in range(3)]for j in range(20)]

FreeNode = 6
RootPointer = 0

ArrayNodes[0] = [1, 20, 5]
ArrayNodes[1] = [2, 15, -1]
ArrayNodes[2] = [-1, 3, 3]
ArrayNodes[3] = [-1, 9, 4]
ArrayNodes[4] = [-1, 10, -1]
ArrayNodes[5] = [-1, 58, -1]
ArrayNodes[6] = [-1, -1, -1]

def SearchValue(Root, ValueToFind):
    global ArrayNodes
    if Root == -1:
        return -1
    else:
        if ArrayNodes[Root][1] == ValueToFind:
            return Root
        else:
            if ArrayNodes[Root][1] == -1:
                return -1
    if ArrayNodes[Root][1] > ValueToFind:
        return SearchValue(ArrayNodes[Root][0], ValueToFind)
    if ArrayNodes[Root][1] < ValueToFind:
        return SearchValue(ArrayNodes[Root][2], ValueToFind)

def PostOrder(RootPointer):
    global ArrayNodes
    if RootPointer == -1:
        print("Tree is empty")
    if ArrayNodes[RootPointer][0] != -1:
        PostOrder(ArrayNodes[RootPointer][0])
    if ArrayNodes[RootPointer][2] != -1:
        PostOrder(ArrayNodes[RootPointer][2])
    print(ArrayNodes[RootPointer][1])

Position = SearchValue(RootPointer, 15)
if Position == -1:
    print("Value not found")
else:
    print("Value found at", Position)
PostOrder(RootPointer)