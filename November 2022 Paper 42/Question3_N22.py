#Queue is an array of type INTEGER that has 100 elements
#HeadPointer is of type INTEGER and initialed to -1
#TailPointer is of type INTEGER and intialised to 0
Queue = [-1 for i in range(100)]
HeadPointer = -1
TailPointer = 0

def Enqueue(Value):
    global Queue
    global HeadPointer
    global TailPointer
    if HeadPointer == -1:
        HeadPointer = 0
    if TailPointer == 100:
        return False
    Queue[TailPointer] = Value
    TailPointer = TailPointer + 1
    return True

for i in range(1, 21):
    Result = Enqueue(i)
    if Result == True:
        print("Successful")
    else:
        print("Unsuccessful")

def IterativeOutput(Start):
    global Queue
    global HeadPointer
    global TailPointer
    Total = 0
    for Count in range(Start - 1, HeadPointer, -1):
        Total = Total + Queue[Count]
    return Total

def RecursiveOutput(Start):
    if Start == HeadPointer:
        return Queue[Start]
    else:
        return Queue[Start] + RecursiveOutput(Start - 1)

print(RecursiveOutput(TailPointer - 1))