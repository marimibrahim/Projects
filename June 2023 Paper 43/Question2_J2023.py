class Vehicle:
    #self.__ID declared as private and of type STRING
    #self.__MaxSpeed declared as private and of type INTEGER
    #self.__CurrentSpeed declared as private and of type INTEGER
    #self.__IncreaseAmount declared as private and of type INTEGER
    #self.__HorizontalPosition declared as private and of type INTEGER

    def __init__(self, ID, MaxSpeed, CurrentSpeed, IncreaseAmount, HorizontalPosition):
        self.__ID = ID
        self.__MaxSpeed = MaxSpeed
        self.__CurrentSpeed = CurrentSpeed
        self.__IncreaseAmount = IncreaseAmount
        self.__HorizontalPosition = HorizontalPosition

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
        if self.__CurrentSpeed > self.__MaxSpeed:
            self.__CurrentSpeed = self.__MaxSpeed
        self.__HorizontalPosition = self.__HorizontalPosition + self.__CurrentSpeed

    def OutputPositionAndSpeed(self):
        print("The horizontal position is: ", self.__HorizontalPosition)
        print("The current speed is: ", self.__CurrentSpeed)

class Helicopter(Vehicle):
    #self.__VerticalPosition declared as private and of type INTEGER
    #self.__VerticalChange declared as private and of type INTEGER
    #self.__MaxHeight declared as private and of type INTEGER

    def __init__(self, ID, MaxSpeed, CurrentSpeed, IncreaseAmount, HorizontalPosition, VerticalPosition, VerticalChange, MaxHeight):
        Vehicle.__init__(self, ID, MaxSpeed, CurrentSpeed, IncreaseAmount, HorizontalPosition)
        self.__VerticalPosition = VerticalPosition
        self.__VerticalChange = VerticalChange
        self.__MaxHeight = MaxHeight

    def IncreaseSpeed(self):
        self.__VerticalPosition = self.__VerticalPosition + self.__VerticalChange
        if self.__VerticalPosition + self.__VerticalChange > self.__MaxHeight:
            self.__VerticalPosition = self.__MaxHeight
        Vehicle.SetCurrentSpeed(self, Vehicle.GetCurrentSpeed(self) + Vehicle.GetIncreaseAmount(self))
        if Vehicle.GetCurrentSpeed(self) > Vehicle.GetMaxSpeed(self):
            Vehicle.SetCurrentSpeed(self, Vehicle.GetMaxSpeed(self))
        Vehicle.SetHorizontalPosition(self, Vehicle.GetHorizontalPosition(self) + Vehicle.GetCurrentSpeed(self))

    def OutputPositionAndSpeed(self):
        print("The horizontal position is: ", Vehicle.GetHorizontalPosition(self))
        print("The current speed is: ", Vehicle.GetCurrentSpeed(self))
        print("The vertical position is: ", self.__VerticalPosition)

#main
Car = Vehicle("Tiger", 100, 0, 20, 0)
Helicopter = Helicopter("Lion", 350, 0, 40, 0, 0, 3, 100)
Car.IncreaseSpeed()
Car.IncreaseSpeed()
Car.OutputPositionAndSpeed()
Helicopter.IncreaseSpeed()
Helicopter.IncreaseSpeed()
Helicopter.OutputPositionAndSpeed()