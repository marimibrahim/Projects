Animal = ["" for i in range(20)]
Colour = ["" for i in range(10)]
AnimalTopPointer = 0
ColourTopPointer = 0

def PushAnimal(DataToPush):
    global Animal
    global AnimalTopPointer
    if AnimalTopPointer == 20:
        return False
    else:
        Animal[AnimalTopPointer] = DataToPush
        AnimalTopPointer = AnimalTopPointer + 1
        return True

def PopAnimal():
    global Animal
    global AnimalTopPointer
    if AnimalTopPointer == 0:
        return ""
    else:
        ReturnData = Animal[AnimalTopPointer - 1]
        AnimalTopPointer = AnimalTopPointer - 1
        return ReturnData

def ReadData():
    try:
        global Animal
        global AnimalTopPointer
        f = open("AnimalData.txt", "r")
        line = f.readline().strip()
        while line != "":
            PushAnimal(line)
            line = f.readline().strip()
        f.close()
    except IOError:
        print("File not found")

    try:
        global Colour
        global ColourTopPointer
        g = open("ColourData.txt", "r")
        line = g.readline().strip()
        while line != "":
            PushColour(line)
            line = g.readline().strip()
        g.close()
    except IOError:
        print("File not found")

def PushColour(DataToPush):
    global Colour
    global ColourTopPointer
    if ColourTopPointer == 10:
        return False
    else:
        Colour[ColourTopPointer] = DataToPush
        ColourTopPointer = ColourTopPointer + 1
        return True

def PopColour():
    global Colour
    global ColourTopPointer
    if ColourTopPointer == 0:
        return ""
    else:
        ReturnData = Colour[ColourTopPointer - 1]
        ColourTopPointer = ColourTopPointer - 1
        return ReturnData

def OutputItem():
    Animal = PopAnimal()
    Colour = PopColour()
    if Colour == "":
        print("No colour")
    elif Animal == "":
        print("No animal")
    else:
        print(Colour, Animal)

ReadData()
OutputItem()
OutputItem()
OutputItem()
OutputItem()
