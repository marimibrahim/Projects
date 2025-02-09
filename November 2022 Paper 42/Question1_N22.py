#Jobs is a 2D array of type INTEGER
#NumberOfJobs is of type INTEGER
Jobs = []
NumberOfJobs = 0

def Initialise():
    global Jobs
    global NumberOfJobs
    Jobs = [[(-1) for i in range(2)] for j in range(100)]
    NumberOfJobs = 0

def AddJob(JobNumber, Priority):
    global Jobs
    global NumberOfJobs
    NumberOfJobs = NumberOfJobs + 1
    if NumberOfJobs == 100:
        print("Not added")
    else:
        Jobs[NumberOfJobs - 1][0] = JobNumber
        Jobs[NumberOfJobs - 1][1] = Priority
        print("Added")

Initialise()
AddJob(12, 10)
AddJob(526, 9)
AddJob(33, 8)
AddJob(12, 9)
AddJob(78, 1)

def InsertionSort():
    global Jobs
    global NumberOfJobs
    for i in range(1, NumberOfJobs):
        Current1 = Jobs[i][0]
        Current2 = Jobs[i][1]
        while i > 0 and Jobs[i - 1][1] > Current2:
            Jobs[i][0] = Jobs[i - 1][0]
            Jobs[i][1] = Jobs[i - 1][1]
            i = i - 1
        Jobs[i][0] = Current1
        Jobs[i][1] = Current2

def PrintArray():
    global Jobs
    global NumberOfJobs
    for i in range(NumberOfJobs):
        print(Jobs[i][0], "priority", Jobs[i][1])

InsertionSort()
PrintArray()