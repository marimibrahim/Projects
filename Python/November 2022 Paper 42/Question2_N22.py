class Character:
    #Name is private and of type STRING
    #XCoordinate is private of type INTEGER
    #YCoordinate is private of type INTEGER
    def __init__(self, Name, XCoordinate, YCoordinate):
        self.__Name = Name
        self.__XCoordinate = XCoordinate
        self.__YCoordinate = YCoordinate

    def GetName(self):
        return self.__Name

    def GetX(self):
        return self.__XCoordinate

    def GetY(self):
        return self.__YCoordinate

    def ChangePosition(self, XChange, YChange):
        self.__XCoordinate = self.__XCoordinate + int(XChange)
        self.__YCoordinate = self.__YCoordinate + int(YChange)

CharacterArray = []
try:
    f = open("Characters.txt", "r")
    Name = f.readline().strip()
    while Name != "":
        XCoordinate = int(f.readline().strip())
        YCoordinate = int(f.readline().strip())
        CharacterArray.append(Character(Name, XCoordinate, YCoordinate))
        Name = f.readline().strip()
    f.close()
except IOError:
    print("File not found")

Found = False
while Found == False:
    UserName = input("Enter the name of the character").lower()
    for i in range(len(CharacterArray)):
        if CharacterArray[i].GetName().lower() == UserName:
            Found = True
            CharacterIndex = i

UserDirection = input("Enter a letter to move the character (A, W, S, D)").lower()
while UserDirection != "a" and UserDirection != "w" and UserDirection != "s" and UserDirection != "d":
    print("Invalid choice. Re-enter.")
    UserDirection = input("Enter a letter to move the character (A, W, S, D)").lower()
if UserDirection == "a":
    CharacterArray[CharacterIndex].ChangePosition((-1) , 0)
elif UserDirection == "w":
    CharacterArray[CharacterIndex].ChangePosition(0, 1)
elif UserDirection == "s":
    CharacterArray[CharacterIndex].ChangePosition(0, (-1))
else:
    CharacterArray[CharacterIndex].ChangePosition(1, 0)

print(CharacterArray[CharacterIndex].GetName()+"'s has changed coordinates to X =", CharacterArray[CharacterIndex].GetX(), "and Y =", CharacterArray[CharacterIndex].GetY())