def IterativeVowels(Value):
    Total = 0
    LengthString = len(Value)
    for x in range(0, LengthString):
        FirstCharacter = Value[0]
        if FirstCharacter == 'a' or FirstCharacter == 'e' or FirstCharacter == 'i' or FirstCharacter == 'o' or FirstCharacter == 'u':
            Total = Total + 1
        Value = Value[1 : LengthString]
    return Total

print(IterativeVowels("house"))

def RecursiveVowels(Value):
    LengthString = len(Value)
    if LengthString == 0:
        return 0
    else:
        FirstCharacter = Value[0]
    if FirstCharacter == 'a' or FirstCharacter == 'e' or FirstCharacter == 'i' or FirstCharacter == 'o' or FirstCharacter == 'u':
        return 1 + RecursiveVowels(Value[1: LengthString])
    else:
        return RecursiveVowels(Value[1 : LengthString])

print(RecursiveVowels("imagine"))