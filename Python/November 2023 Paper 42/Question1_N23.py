#Array StackVowel is declared as STRING and has 100 spaces
#Array StackConsonant is declared as STRING and has 100 spaces
StackVowel = ["" for i in range(100)]
StackConsonant = ["" for i in range(100)]

#VowelTop is a variable which points to the next free space in StackVowel and is initialised to 0
#ConsonantTop is a variable which points to the next free space in StackConsonant and is initialised to 0
VowelTop = 0
ConsonantTop = 0

def PushData(Letter):
    global StackVowel
    global VowelTop
    global StackConsonant
    global ConsonantTop
    if Letter == 'a' or Letter == 'e' or Letter == 'i' or Letter == 'o' or Letter == 'u':
        if VowelTop == 100:
            print("Stack is full")
        else:
            StackVowel[VowelTop] = Letter
            VowelTop = VowelTop + 1
    else:
        if ConsonantTop == 100:
            print("Stack is full")
        else:
            StackConsonant[ConsonantTop] = Letter
            ConsonantTop = ConsonantTop + 1

def ReadData():
    try:
        f = open("StackData.txt", "r")
        line = f.readline().strip()
        while line != "":
            PushData(line)
            line = f.readline().strip()
        f.close()
    except IOError:
        print("File not found")

def PopVowel():
    global VowelTop
    global StackVowel
    if VowelTop == 0:
        return "No data"
    else:
        VowelTop = VowelTop - 1
        temp = StackVowel[VowelTop]
        return temp

def PopConsonant():
    global ConsonantTop
    global StackConsonant
    if ConsonantTop == 0:
        return "No data"
    else:
        ConsonantTop = ConsonantTop - 1
        temp = StackConsonant[ConsonantTop]
        return temp

ReadData()
Text = ""
for i in range(5):
    Choice = input("Enter your choice of vowel or consonant: ").lower()
    while Choice != "vowel" and Choice != "consonant":
        print("Invalid choice. Re-enter.")
        Choice = input("Enter your choice of vowel or consonant: ").lower()
    if Choice == "vowel":
        PopValue = PopVowel()
        if PopValue == "No data":
            print("No vowels left")
        else:
            Text = Text + PopValue
    elif Choice == "consonant":
        PopValue = PopConsonant()
        if PopValue == "No data":
            print("No consonants left")
        else:
            Text = Text + PopValue
print(Text)