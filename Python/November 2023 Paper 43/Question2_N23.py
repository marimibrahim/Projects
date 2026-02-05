Queue = ["" for i in range(50)] #array declared as STRING and initialised as empty
HeadPointer = -1 #declared as integer and initialised as -1 as the array is empty
TailPointer = 0 #declared as integer and initialised as 0 as the array is empty

def Enqueue(Value):
    global Queue
    global HeadPointer
    global TailPointer
    if TailPointer == 50:
        print("The queue is full")
    else:
        if HeadPointer == -1:
            HeadPointer = 0
        Queue[TailPointer] = Value
        TailPointer = TailPointer + 1

def Dequeue():
    global Queue
    global HeadPointer
    global TailPointer
    if HeadPointer == -1:
        print("The queue is empty")
    else:
        Temp = HeadPointer
        HeadPointer = HeadPointer + 1
        return Queue[Temp]

def ReadData():
    global Queue
    global HeadPointer
    global TailPointer
    try:
        f = open("QueueData.txt", "r")
        line = f.readline().strip()
        while line != "":
            Enqueue(line)
            line = f.readline().strip()
        f.close()
    except IOError:
        print("File not found")

class RecordData:
    #self.ID declared as STRING
    #self.Total declared as INTEGER
    def __init__(self, ID, Total):
        self.ID = ID
        self.Total = Total

#Records declared as array of type STRING
#NumberRecords declared as INTEGER and initialised as 0
Records = [RecordData("", 0) for i in range(50)]
NumberRecords = 0

def TotalData():
    global Records
    global NumberRecords
    DataAccessed = Dequeue()
    Flag = False
    if NumberRecords == 0:
        Records[NumberRecords].ID = DataAccessed
        Records[NumberRecords].Total = 1
        Flag = True
        NumberRecords = NumberRecords + 1
    else:
        for X in range(NumberRecords):
            if Records[X].ID == DataAccessed:
                Records[X].Total = Records[X].Total + 1
                Flag = True
    if Flag == False:
        Records[NumberRecords].ID = DataAccessed
        Records[NumberRecords].Total = 1
        NumberRecords = NumberRecords + 1

def OutputRecords():
    global Records
    global NumberRecords
    for i in range(NumberRecords):
        print("ID", Records[i].ID, "Total", Records[i].Total)

ReadData()
while HeadPointer != TailPointer:
    TotalData()
OutputRecords()