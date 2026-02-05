class Employee:
    #self.__HourlyPay is declared as private and of type REAL
    #self.__EmployeeNumber is declared as private and of type STRING
    #self.__JobTitle is declared as private and of type STRING
    #self.__PayYear2022 is declared as private and ARRAY with 52 elements initialised to 0.0
    def __init__(self, HourlyPay, EmployeeNumber, JobTitle):
        self.__HourlyPay = HourlyPay
        self.__EmployeeNumber = EmployeeNumber
        self.__JobTitle = JobTitle
        self.__PayYear2022 = [0.0 for i in range(52)]

    def GetEmployeeNumber(self):
        return self.__EmployeeNumber

    def SetPay(self, WeekNumber, NumberOfHours):
        Pay = self.__HourlyPay * NumberOfHours
        self.__PayYear2022[WeekNumber - 1] = Pay

    def GetTotalPay(self):
        Total = 0
        for i in range(52):
            Total = Total + self.__PayYear2022[i]
        return Total

class Manager:
    # self.__HourlyPay is declared as private and of type REAL
    # self.__EmployeeNumber is declared as private and of type STRING
    # self.__JobTitle is declared as private and of type STRING
    #self.__BonusValue is declared as private and of type REAL
    def __init__(self, HourlyPay, EmployeeNumber, JobTitle, BonusValue):
        Employee.__init__(HourlyPay, EmployeeNumber, JobTitle)
        self.__BonusValue = BonusValue

    def SetPay(self, WeekNumber, NumberOfHours):
        NumberOfHours = NumberOfHours * (1 + self.__BonusValue/100)
        Employee.SetPay(WeekNumber, NumberOfHours)

#main
EmployeeArray = []
try:
    i = 0
    f = open("Employees.txt", "r")
    line = f.readline().strip()
    while line != "" and i < 8:
        HourlyPay = line
        EmployeeNumber = f.readline().strip()
        line = f.readline().strip()
        try:
            BonusValue = float(line)
            JobTitle = f.readline().strip()
            Record = Manager(HourlyPay, EmployeeNumber, JobTitle, BonusValue)
            EmployeeArray.append(Record)
        except:
            JobTitle = line
            Record = Employee(HourlyPay, EmployeeNumber, JobTitle)
            EmployeeArray.append(Record)
        line = f.readline().strip()
    f.close()
except IOError:
    print("File not found")

def EnterHours():
    try:
        g = open("HoursWeek1.txt", "r")
        for j in range(8):
            line = g.readline().strip()
            for i in range(8):
                if EmployeeArray[i].GetEmployeeNumber() == line:
                    HourlyPay = g.readline().strip()
                    EmployeeArray[i].SetPay(1, float(HourlyPay))
    except IOError:
        print("File not found")

EnterHours()
for i in range(8):
    Total = EmployeeArray[i].GetTotalPay()
    print(EmployeeArray[i].GetEmployeeNumber(), "\t", Total)