class Picture:
    #self.__Description declared as private and STRING
    #self.__Width declared as private and INTEGER
    #self.__Height declared as private and INTEGER
    #self.__FrameColour declared as private and STRING

    def __init__(self, Description, Width, Height, FrameColour):
        self.__Description = Description
        self.__Width = Width
        self.__Height = Height
        self.__FrameColour = FrameColour

    def GetDescription(self):
        return self.__Description

    def GetHeight(self):
        return self.__Height

    def GetWidth(self):
        return self.__Width

    def GetColour(self):
        return self.__FrameColour

    def SetDescription(self, Description):
        self.__Description = Description

PictureArray = [Picture("", 0, 0, "") for i in range(100)]

def ReadData():
    try:
        f = open("Pictures.txt", "r")
        i = 0
        Description = f.readline().strip().lower()
        while Description != "":
            Width = int(f.readline().strip())
            Height = int(f.readline().strip())
            FrameColour = f.readline().strip().lower()
            PictureArray[i] = Picture(Description, Width, Height, FrameColour)
            i = i + 1
            Description = f.readline().strip().lower()
        f.close()
        return i
    except IOError:
        print("File not found")

NumberOfPictures = ReadData()
print(NumberOfPictures)

UserFrameColour = input("Enter the colour of the frame").lower()
UserMaxWidth = int(input("Enter the maximum width"))
UserMaxHeight = int(input("Enter the maximum height"))

for i in range(0, NumberOfPictures):
    if UserFrameColour == PictureArray[i].GetColour() and UserMaxWidth >= PictureArray[i].GetWidth() and UserMaxHeight >= PictureArray[i].GetHeight():
        print(PictureArray[i].GetDescription(), end=", ")
        print(PictureArray[i].GetWidth(), end=", ")
        print(PictureArray[i].GetHeight(), end=", ")
        print(PictureArray[i].GetColour())
        i = i + 1