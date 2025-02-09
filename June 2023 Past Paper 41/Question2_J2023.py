class Vehicle:
    def __init__(self, ID, MaxSpeed, IncreaseAmount):
        self.__ID = ID #ID is STRING
        self.__MaxSpeed = MaxSpeed #MaxSpeed is INTEGER
        self.__CurrentSpeed = 0 #CurrentSpeed is INTEGER and initialised 0
        self.__IncreaseAmount = IncreaseAmount #IncreaseAmount is INTEGER
        self.__HorizontalPosition = 0 #HorizontalPosition is INTEGER and initialised 0

    def GetCurrentSpeed(self):
        return self.__CurrentSpeed

    def GetIncreaseAmount(self):
        return self.__IncreaseAmount

    def GetMaxSpeed(self):
        return self.__MaxSpeed

    def GetHorizontalPosition(self):
        return self.__HorizontalPosition

    def SetCurrentSpeed(self, CurrentSpeed):
        self.__CurrentSpeed = CurrentSpeed

    def SetHorizontalPosition(self, HorizontalPosition):
        self.__HorizontalPosition = HorizontalPosition

    def IncreaseSpeed(self):
        self.__CurrentSpeed = self.__CurrentSpeed + self.__IncreaseAmount
        self.__HorizontalPosition = self.__HorizontalPosition + self.__CurrentSpeed
        if self.__CurrentSpeed > self.__MaxSpeed:
            self.__CurrentSpeed = self.__MaxSpeed

    def SpeedAndHeight(self):
        print("The horizontal position of the vehicle is: ", self.__HorizontalPosition)
        print("The speed of the vehicle is: ", self.__CurrentSpeed)

class Helicopter:
    def __init__(self, ID, MaxSpeed, IncreaseAmount, VerticalChange, MaxHeight):
        Vehicle.__init__(self, ID, MaxSpeed, IncreaseAmount)
        self.__VerticalChange = VerticalChange
        self.__MaxHeight = MaxHeight
        self.__VerticalPosition = 0 #VerticalPosition is INTEGER and initialised as 0

    def IncreaseSpeed(self):
        self.__VerticalPosition = self.__VerticalChange + self.__VerticalPosition
        Vehicle.SetCurrentSpeed(self, Vehicle.GetCurrentSpeed(self) + Vehicle.GetIncreaseAmount(self))
        self.__HorizontalPosition = Vehicle.GetHorizontalPosition(self) + Vehicle.GetCurrentSpeed(self)
        if self.__VerticalPosition > self.__MaxHeight:
            self.__VerticalPosition = self.__MaxHeight
        if Vehicle.GetCurrentSpeed(self) > Vehicle.GetMaxSpeed(self):
            Vehicle.SetCurrentSpeed(self, Vehicle.GetMaxSpeed(self))
        Vehicle.SetHorizontalPosition(self, Vehicle.GetHorizontalPosition(self) + Vehicle.GetCurrentSpeed(self))

    def SpeedAndHeight(self):
        print("The horizontal position of the helicopter is: ", Vehicle.GetHorizontalPosition(self))
        print("The speed of the helicopter is: ", Vehicle.GetCurrentSpeed(self))
        print("The vertical position of the helicopter is: ", self.__VerticalPosition)

Car1 = Vehicle("Tiger", 100, 20)
Helicopter1 = Helicopter("Lion", 350, 40, 3, 100)
Car1.IncreaseSpeed()
Car1.IncreaseSpeed()
Car1.SpeedAndHeight()
Helicopter1.IncreaseSpeed()
Helicopter1.IncreaseSpeed()
Helicopter1.SpeedAndHeight()