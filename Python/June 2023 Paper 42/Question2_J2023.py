class SaleData:
    #self.ID is public and stores ID of type STRING
    #self.Quantity is public and stores ID of type INTEGER
    def __init__(self, ID, Quantity):
        self.ID = ID
        self.Quantity = Quantity

CircularQueue = [SaleData("", -1) for i in range(5)]
Head = 0
Tail = 0
NumberOfItems = 0

def Enqueue(Record):
    global CircularQueue
    global Head
    global Tail
    global NumberOfItems
    if NumberOfItems == 5:
        return -1
    else:
        CircularQueue[Tail] = Record
        Tail = Tail + 1
        if Tail == 5:
            Tail = 0
        NumberOfItems = NumberOfItems + 1
        return 1

def Dequeue():
    global CircularQueue
    global Head
    global Tail
    global NumberOfItems
    if NumberOfItems == 0:
        return None
    else:
        NumberOfItems = NumberOfItems - 1
        Temp = CircularQueue[Head]
        Head = Head + 1
        if Head == 5:
            Head = 0
        return Temp

def EnterRecord():
    global CircularQueue
    global Head
    global Tail
    ID = input("Enter the ID")
    Quantity = int(input("Enter the quantity"))
    Record = SaleData(ID, Quantity)
    Result = Enqueue(Record)
    if Result == -1:
        print("Full")
    else:
        print("Stored")

EnterRecord()
EnterRecord()
EnterRecord()
EnterRecord()
EnterRecord()
EnterRecord()
Result = Dequeue()
if Result == None:
    print("The circular queue is empty")
else:
    print(Result.ID, "\t", Result.Quantity)
EnterRecord()
for i in range(5):
    print(CircularQueue[i].ID, "\t", CircularQueue[i].Quantity)
