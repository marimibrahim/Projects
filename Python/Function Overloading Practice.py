PI = 3.142

def area(radius = None, length = None, width = None):
    if radius is not None and length is not None:
        print("Error, only enter radius or length")
    elif radius is not None:
        return(PI * radius**2)
    elif length == width or width is None:
        return(length * length)
    else:
        return(length * width)

def perimeter(radius = None, length = None, width = None):
    if radius is not None and length is not None:
        print("Error, only enter radius or length")
    elif radius is not None:
        return(2 * PI * radius)
    elif length == width or width is None:
        return(4 * length)
    else:
        return((2 * length) + (2 * width))

radius = float(input("Enter the radius: "))
length = float(input("Enter the length: "))
width = float(input("Enter the width: "))

print("Area of circle is: ", area(radius))
print("Area of square is: ", area(None, length))
print("Area of rectangle is: ", area(None, length, width))

print("Perimeter of circle is: ", perimeter(radius))
print("Perimeter of square is: ", perimeter(None, length))
print("Perimeter of rectangle is: ", perimeter(None, length, width))
