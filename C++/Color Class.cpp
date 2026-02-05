#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <cmath>

using namespace std;

class Color {
private:
    int red, green, blue;
    int checkAndTruncate(int x) const {
        if (x >= 0 && x <= 255)
            return x;
        else if (x < 0) {
            return 0;
        }
        else {
            return 255;
        }
    }


public:
    Color() {
        red = 0;
        green = 0;
        blue = 0;
    }
    Color(int x) { red = green = blue = checkAndTruncate(x); }
    void setRed(int r) { red = checkAndTruncate(r); }
    void setGreen(int g) { green = checkAndTruncate(g); };
    void setBlue(int b) { blue = checkAndTruncate(b); }
    int getRed() const { return red; }
    int getGreen() const { return green; }
    int getBlue() const { return blue; }
    void input(istream& in) {
        in >> red >> green >> blue;
        red = checkAndTruncate(red);
        green = checkAndTruncate(green);
        blue = checkAndTruncate(blue);
    }
    void output(ostream& out) {
        out << "[" << red << "," << green << "," << blue << "]";
    }
    Color operator+(const Color& c1);
    Color operator-(const Color& c1);
    Color operator-();
    bool operator==(const Color& c1);
    bool operator!=(const Color& c1);
    int operator[](int i);
};

Color Color::operator+(const Color& c1)
{
    Color rst;
    rst.setRed(red + c1.red);
    rst.setBlue(blue + c1.blue);
    rst.setGreen(green + c1.green);
    return rst;
}

Color Color::operator-(const Color& c1)
{
    Color rst;
    rst.setRed(red - c1.red);
    rst.setBlue(blue - c1.blue);
    rst.setGreen(green - c1.green);
    return rst;
}

Color Color::operator-()
{
    Color rst;
    rst.setRed(255 - red);
    rst.setBlue(255 - blue);
    rst.setGreen(255 - green);
    return rst;
}

bool Color::operator==(const Color& c1)
{
    return(red == c1.red && blue == c1.blue && green == c1.green);
}

bool Color::operator!=(const Color& c1)
{
    return(red != c1.red || blue != c1.blue || green != c1.green);
}

int Color::operator[](int i)
{
    if (i == 0)
        return red;
    else if (i == 1)
        return green;
    else if (i == 2)
        return blue;
    else
    {
        cout << "Invalid index.\n";
        return -1;
    }
}

int main()
{
    Color col1, col2;
    cout << "Please enter Red Green and Blue for Color1: ";
    col1.input(cin);
    cout << "Please enter Red Green and Blue for Color2: ";
    col2.input(cin);
    Color sum = col1 + col2;
    col1.output(cout); cout << " + "; col2.output(cout); cout << " = "; sum.output(cout); cout << endl;
    Color sub = col1 - col2;
    col1.output(cout); cout << " - "; col2.output(cout); cout << " = "; sub.output(cout); cout << endl;
    Color col3 = -col1;
    cout << "-"; col1.output(cout); cout << " = "; col3.output(cout); cout << endl;
    col1.output(cout); cout << " == "; col1.output(cout); cout << " = " << (col1 == col1) << endl;
    col1.output(cout); cout << " == "; col2.output(cout); cout << " = " << (col1 == col2) << endl;
    col1.output(cout); cout << " != "; col1.output(cout); cout << " = " << (col1 != col1) << endl;
    col1.output(cout); cout << " != "; col2.output(cout); cout << " = " << (col1 != col2) << endl;
    cout << "Color1[0] : " << col1[0] << endl;
    cout << "Color1[1] : " << col1[1] << endl;
    cout << "Color1[2] : " << col1[2] << endl;
    cout << "Color1[3] : " << col1[3] << endl;

    return 0;
}