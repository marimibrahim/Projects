global Animal
global Colour
global AnimalTopPointer
global ColourTopPointer

Animal = [] #20 elements of STRING
Colour = [] #10 elements of STRING
AnimalTopPointer = 0
ColourTopPointer = 0

def PushAnimal(DataToPush):
    global Animal
    global AnimalTopPointer
    if AnimalTopPointer == 20:
        return False
    else:
        Animal.append(DataToPush)
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

def PushColour(DataToPush):
    global Colour
    global ColourTopPointer
    if ColourTopPointer == 10:
        return False
    else:
        Colour.append(DataToPush)
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

def ReadData():
    global Animal
    try:
        f = open("AnimalData.txt", "r")
        for i in f:
            PushAnimal(i.strip())
        f.close()
    except IOError:
        print("File not found.")
    try:
        s = open("ColourData.txt", "r")
        for i in s:
            PushColour(i.strip())
        s.close()
    except IOError:
        print("File not found.")

def OutputItem():
    global AnimalTopPointer
    global ColourTopPointer
    if ColourTopPointer == 0:
        print("No colour")
        PushAnimal(Item)
    elif AnimalTopPointer == 0:
        print("No animal")
        PushColour(Item)
    else:
        Item = (PopColour() + " " + PopAnimal())
        print(Item)

ReadData()
OutputItem()
OutputItem()
OutputItem()
OutputItem()