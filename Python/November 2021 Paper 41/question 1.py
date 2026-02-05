def Unknown(X, Y):
    if X < Y:
        print(X + Y)
        return(Unknown(X + 1, Y) * 2)
    else:
        if X == Y:
            return 1
        else:
            print(X + Y)
            return (Unknown(X - 1, Y) // 2)

def IterativeUnknown(X, Y):
    Total = 1
    while X != Y:
        print(str(X + Y))
        if X < Y:
            X = X + 1
            Total = Total * 2
        else:
            X = X - 1
            Total = int(Total / 2)
    return Total

print("X = 10 and Y = 15")
Value = Unknown(10, 15)
print(Value)
print("X = 10 and Y = 10")
Value = Unknown(10, 10)
print(Value)
print("X = 15 and Y = 10")
Value = Unknown(15, 10)
print(Value)

print("X = 10 and Y = 15")
Value = IterativeUnknown(10, 15)
print(Value)
print("X = 10 and Y = 10")
Value = IterativeUnknown(10, 10)
print(Value)
print("X = 15 and Y = 10")
Value = IterativeUnknown(15, 10)
print(Value)