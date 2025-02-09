def IterativeVowels(Value):
    Total = 0
    LengthString = len(Value)
    for i in range(0, LengthString):
        FirstCharacter = Value[0]
        if FirstCharacter == 'a' or FirstCharacter == 'e' or FirstCharacter == 'i' or FirstCharacter == 'o' or FirstCharacter == 'u':
            Total = Total + 1
        Value = Value[1 : len(Value)]
    return Total

Total = IterativeVowels("house")
print(Total)

def RecursiveVowels(Value):
    if len(Value) == 0:
        return 0
    else:
        FirstCharacter = Value[0]
    if FirstCharacter == 'a' or FirstCharacter == 'e' or FirstCharacter == 'i' or FirstCharacter == 'o' or FirstCharacter == 'u':
        return 1 + RecursiveVowels(Value[1:len(Value)])
    else:
        return RecursiveVowels(Value[1:len(Value)])

Total = RecursiveVowels("imagine")
print(Total)