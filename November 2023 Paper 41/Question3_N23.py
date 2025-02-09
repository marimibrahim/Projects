class Character:
    #self.__Name is private and of type STRING
    #self._-XPosition is private and of type INTEGER
    #self.__YPosition is private and of type INTEGER
    def __init__(self, Name, XPosition, YPosition):
        self.__Name = Name
        self.__XPosition = XPosition
        self.__YPosition = YPosition

    def GetXPosition(self):
        return self.__XPosition

    def GetYPosition(self):
        return self.__YPosition

    def SetXPosition(self, XPosition):
        self.__XPosition = self.__XPosition + XPosition
        if self.__XPosition > 10000:
            self.__XPosition = 10000
        elif self.__XPosition < 0:
            self.__XPosition = 0

    def SetYPosition(self, YPosition):
        self.__YPosition = self.__YPosition + YPosition
        if self.__YPosition > 10000:
            self.__YPosition = 10000
        elif self.__YPosition < 0:
            self.__YPosition = 0

    def Move(self, Direction):
        Direction = Direction.lower()
        if Direction == "up":
            self.SetYPosition(10)
        elif Direction == "down":
            self.SetYPosition(-10)
        elif Direction == "left":
            self.SetXPosition(-10)
        elif Direction == "right":
            self.SetXPosition(10)

Jack = Character("Jack", 50, 50)

class BikeCharacter(Character):
    # self.__Name is private and of type STRING
    # self._-XPosition is private and of type INTEGER
    # self.__YPosition is private and of type INTEGER
    def __init__(self, Name, XPosition, YPosition):
        Character.__init__(self, Name, XPosition, YPosition)

    def Move(self, Direction):
        Direction = Direction.lower()
        if Direction == "up":
            self.SetYPosition(20)
        elif Direction == "down":
            self.SetYPosition(-20)
        elif Direction == "left":
            self.SetXPosition(-20)
        elif Direction == "right":
            self.SetXPosition(20)

Karla = BikeCharacter("Karla", 100, 50)

UserCharacter = input("Enter the name of the character (Jack/Karla)").lower()
while UserCharacter != "jack" and UserCharacter != "karla":
    print("Invalid choice. Re-enter.")
    UserCharacter = input("Enter the name of the character (Jack/Karla)").lower()
UserDirection = input("Enter the direction (up/down/left/right)").lower()
while UserDirection != "up" and UserDirection != "down" and UserDirection != "left" and UserDirection != "right":
    print("Invalid choice. Re-enter.")
    UserDirection = input("Enter the direction (up/down/left/right)").lower()
if UserCharacter == "jack":
    Jack.Move(UserDirection)
    print("Jack's new position is X =", Jack.GetXPosition(), " Y =", Jack.GetYPosition())
else:
    Karla.Move(UserDirection)
    print("Karla's new position is X =", Karla.GetXPosition(), " Y =", Karla.GetYPosition())
