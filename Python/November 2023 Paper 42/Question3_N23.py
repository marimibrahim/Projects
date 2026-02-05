import datetime


class Character:
    #self.__CharacterName is declared private and of type STRING
    #self.__DateOfBirth is declared private and of type DATE
    #self.__Intelligence is declared as private and of type REAL
    #self.__Speed is declared as private and of type INTEGER
    def __init__(self, CharacterName, DateOfBirth, Intelligence, Speed):
        self.__CharacterName = CharacterName
        self.__DateOfBirth = DateOfBirth
        self.__Intelligence = Intelligence
        self.__Speed = Speed

    def GetIntelligence(self):
        return self.__Intelligence

    def GetName(self):
        return self.__CharacterName

    def SetIntelligence(self, Intelligence):
        self.__Intelligence = Intelligence

    def Learn(self):
        self.SetIntelligence(self.__Intelligence * 1.10)

    def ReturnAge(self):
        Age = 2023 - int(self.__DateOfBirth.year)
        return Age

FirstCharacter = Character("Royal", datetime.datetime(2019, 1, 1), 70, 30)
FirstCharacter.Learn()
print("Name:", FirstCharacter.GetName(), ", Age:", FirstCharacter.ReturnAge(), ", Intelligence:", FirstCharacter.GetIntelligence())

class MagicCharacter(Character):
    # self.__CharacterName is declared private and of type STRING
    # self.__DateOfBirth is declared private and of type DATE
    # self.__Intelligence is declared as private and of type REAL
    # self.__Speed is declared as private and of type INTEGER
    # self.__Element is declared as private and of type STRING
    def __init__(self, CharacterName, DateOfBirth, Intelligence, Speed, Element):
        Character.__init__(self, CharacterName, DateOfBirth, Intelligence, Speed)
        self.__Element = Element

    def Learn(self):
        self.__Element = self.__Element.lower()
        if self.__Element == "fire" or self.__Element == "water":
            Character.SetIntelligence(self, (Character.GetIntelligence(self) * 1.20))
        elif self.__Element == "earth":
            Character.SetIntelligence(self, Character.GetIntelligence(self) * 1.30)
        else:
            Character.SetIntelligence(self, Character.GetIntelligence(self) * 1.10)

FirstMagic = MagicCharacter("Light", datetime.datetime(2018, 3, 3), 75, 22, "fire")
FirstMagic.Learn()
print("Name:", FirstMagic.GetName(), ", Age:", FirstMagic.ReturnAge(), ", Intelligence:", FirstMagic.GetIntelligence())

