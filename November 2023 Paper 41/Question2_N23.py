#Queue is an array of type STRING with 50 spaces
#HeadPointer points to the first element and is initialised to -1
#TailPointer points to the next available space and is initialised to 0
Queue = []
HeadPointer = -1
TailPointer = 0

def Enqueue(Value):
    global Queue
    global TailPointer
    global HeadPointer
    if TailPointer == 50:
        print("Queue is full")
    else:
        if HeadPointer == -1:
            HeadPointer = 0
        Queue.append(Value)
        TailPointer = TailPointer + 1

def Dequeue():
    global Queue
    global HeadPointer
    global TailPointer
    if TailPointer - HeadPointer == 1 or HeadPointer == -1:
        return "Empty"
    else:
        Temp = Queue[HeadPointer]
        HeadPointer = HeadPointer + 1
        return Temp

def ReadData():
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
    #self.ID is defined ad public and of type STRING
    #self.Total is defined as public and of type INTEGER
    def __init__(self, ID, Total):
        self.ID = ID
        self.Total = Total

#Records is an array of type RecordData and 50 elements
#NumberRecords is initialised to 0
Records = []
NumberRecords = 0

def TotalData():
    global Records
    global NumberRecords
    DataAccessed = Dequeue()
    Flag = False
    if NumberRecords == 0:
        Records.append(RecordData(DataAccessed, 1))
        Flag = True
        NumberRecords = NumberRecords + 1
    else:
        for X in range(0, NumberRecords):
            if Records[X].ID == DataAccessed:
                Records[X].Total = Records[X].Total + 1
                Flag = True
    if Flag == False:
        Records.append(RecordData(DataAccessed, 1))
        NumberRecords = NumberRecords + 1

def OutputRecords():
    global Records
    for i in range(NumberRecords):
        print("ID", Records[i].ID, " Total", Records[i].Total)

ReadData()
for i in range(len(Queue) - 1):
    TotalData()
OutputRecords()