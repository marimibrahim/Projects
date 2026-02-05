#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <cmath>

using namespace std;

class PFArray2D
{
public:
    PFArray2D(int rows = 3, int cols = 50);

    PFArray2D(const PFArray2D& pfaObject);

    void addElement(double element, int row);
    //add element to the array[row]

    bool full(int row) const;
    //Returns true if the array[row] is full, false otherwise.

    int getColumns() const;

    int getNumberUsed(int row) const;
    // get the number of items in array[row]

    void emptyArray();
    //Resets the number used=0, effectively emptying the array.

    double at(int row, int col);
    //return the element at array[row][col]

    PFArray2D& operator =(const PFArray2D& rightSide);

    ~PFArray2D();
protected:
    double** a; //for a 2D array of doubles.
    int rows;// for the number of rows in the 2D array
    int columns; //for the number of items in every row of the array.
    int* used; //for the number of array positions currently in use in every row.

};

PFArray2D::PFArray2D(int rows, int cols)
{
    this->rows = rows;
    columns = cols;
    a = new double* [rows];
    used = new int[rows];
    for (int i = 0; i < rows; i++)
    {
        a[i] = new double[columns];
        used[i] = 0;
    }
}

PFArray2D::PFArray2D(const PFArray2D& pfaObject)
{
    columns = pfaObject.columns;
    rows = pfaObject.rows;
    a = new double* [rows];
    used = new int[rows];
    for (int i = 0; i < rows; i++)
    {
        a[i] = new double[columns];
        used[i] = pfaObject.used[i];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < used[i]; j++)
            a[i][j] = pfaObject.a[i][j];
    }
}
double PFArray2D::at(int row, int col)
{
    if (row >= rows || col >= columns)
    {
        cout << "Illegal index in PFArrayD.\n";
        exit(0);
    }
    return a[row][col];
}

PFArray2D& PFArray2D::operator =(const PFArray2D& rightSide)
{
    //TO DO 1: Implement this operator, you need to check for rows and cols first if they are not equal to the ones in the rightSide, then you need to delete all the memory you allocated in the constructors and create new one with same size ( rows and cols) as the rightSide, the rest of the code will be like the copy constructor code.
    if (rows != rightSide.rows || columns != rightSide.columns)
    {
        for (int i = 0; i < columns; i++)
        {
            delete[] a[i];
        }
        delete[] a;
        delete[] used;
        a = new double* [rightSide.rows];
        used = new int[rightSide.rows];
        for (int i = 0; i < rightSide.rows; i++)
        {
            a[i] = new double[rightSide.columns];
            used[i] = rightSide.used[i];
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < used[i]; j++)
            a[i][j] = rightSide.a[i][j];
    }
    return *this;
}

PFArray2D::~PFArray2D()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] a[i];
        a[i] = NULL;
    }
    delete[] a;
    delete[] used;
}

void PFArray2D::addElement(double element, int row)
{
    if (row >= rows)
    {
        cout << "Attempt to exceed row # in PFArrayD.\n";
        exit(0);
    }
    if (used[row] >= columns)
    {
        cout << "Attempt to exceed columns in PFArrayD.\n";
        exit(0);
    }
    a[row][used[row]] = element;
    used[row]++;
}

bool PFArray2D::full(int row) const
{
    if (row >= rows)
    {
        cout << "Row > " << rows;
        exit(0);
    }
    return (columns == used[row]);
}

int PFArray2D::getColumns() const
{
    return columns;
}

int PFArray2D::getNumberUsed(int row) const
{
    if (row >= rows)
    {
        cout << "Row > " << rows;
        exit(0);
    }

    return used[row];
}

void PFArray2D::emptyArray()
{
    for (int i = 0; i < rows; i++)
    {
        used[i] = 0;
    }
}


class PFArray2DBak : public PFArray2D
{
public:
    PFArray2DBak(int rows = 3, int cols = 50);

    //TO DO 2: The copy constructor
    PFArray2DBak(const PFArray2DBak& rhs) : PFArray2D(rhs)
    {
        columns = rhs.columns;
        rows = rhs.rows;
        b = new double* [rows];
        usedB = new int[rows];
        for (int i = 0; i < rows; i++)
        {
            b[i] = new double[columns];
            usedB[i] = rhs.usedB[i];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < usedB[i]; j++)
                b[i][j] = rhs.b[i][j];
        }
    }

    //TO DO 3: The assignment operator (=)
    PFArray2DBak& operator=(const PFArray2DBak& rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        int b_rows = rows;
        int b_columns = columns;
        if (rhs.rows != b_rows || rhs.columns != b_columns)
        {
            for (int i = 0; i < b_rows; i++)
            {
                delete[] b[i];
            }
            delete[] b;
            rows = rhs.rows;
            columns = rhs.columns;
            b = new double* [rows];
            usedB = new int[rows];
            for (int i = 0; i < b_rows; i++)
            {
                b[i] = new double[columns];
                usedB[i] = rhs.usedB[i];
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                b[i][j] = rhs.b[i][j];
            }
        }
        return *this;
    }

    //TO DO 4: The destructor
    ~PFArray2DBak()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] b[i];
            b[i] = NULL;
        }
        delete[] b;
        delete[] usedB;
    }

    void backup();
    //Makes a backup copy of the partially filled 2D array.

    void restore();
    //Restores the partially filled array to the last saved version.
    //If backup has never been invoked, this empties the partially filled array.

private:
    double** b; //for a backup of main array.
    int* usedB; //backup for inherited member variable used.
};

PFArray2DBak::PFArray2DBak(int rows, int cols) :PFArray2D(rows, cols)
{
    b = new double* [rows];
    usedB = new int[rows];
    for (int i = 0; i < rows; i++)
    {
        b[i] = new double[columns];
        usedB[i] = 0;
    }
}

void PFArray2DBak::backup()
{
    for (int i = 0; i < rows; i++)
    {
        usedB[i] = getNumberUsed(i);
        for (int j = 0; j < usedB[i]; j++)
            b[i][j] = a[i][j];
    }
}

void PFArray2DBak::restore()
{
    emptyArray();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < usedB[i]; j++)
            addElement(b[i][j], i);
    }
}


void testPFArray2DBak();
//Conducts one test of the class PFArray2DBak.
int main()
{
    cout << "This program tests the class PFArray2DBak.\n";
    char ans;
    do
    {
        testPFArray2DBak();
        cout << "Test again? (y/n) ";
        cin >> ans;
    } while ((ans == 'y') || (ans == 'Y'));
    return 0;
}
void testPFArray2DBak()
{
    int cols, rows;;
    cout << "Enter rows and columns of this super array: ";
    cin >> rows >> cols;
    PFArray2DBak backupArr(rows, cols);
    for (int row = 0; row < rows; row++)
    {
        cout << "Enter up to " << cols << " nonnegative numbers into ROW " << row << ".\n";
        cout << "Place a negative number at the end.\n";

        double next;

        cin >> next;
        while ((next >= 0) && (!backupArr.full(row)))
        {
            backupArr.addElement(next, row);
            cin >> next;
        }

        if (next >= 0)
        {
            cout << "Could not read all numbers.\n";
            //Clear the unread input:
            while (next >= 0)
                cin >> next;
        }
    }
    cout << "You have the following numbers read and stored:\n";
    for (int row = 0; row < rows; row++)
    {
        cout << "ROW " << row << " : " << backupArr.getNumberUsed(row) << " number \n";
    }
    cout << "Array Content :\n";
    for (int row = 0; row < rows; row++)
    {
        cout << "ROW " << row << " : ";
        for (int col = 0; col < backupArr.getNumberUsed(row); col++)
        {
            cout << backupArr.at(row, col) << " ";
        }
        cout << "\n";
    }
    cout << "Backing up array.\n";
    backupArr.backup();
    cout << "emptying array.\n";
    backupArr.emptyArray();
    cout << "You have the following numbers read and stored:\n";
    for (int row = 0; row < rows; row++)
    {
        cout << "ROW " << row << " : " << backupArr.getNumberUsed(row) << " number \n";
    }
    cout << "Restoring array.\n";
    backupArr.restore();
    cout << "You have the following numbers read and stored:\n";
    for (int row = 0; row < rows; row++)
    {
        cout << "ROW " << row << " : " << backupArr.getNumberUsed(row) << " number \n";
    }
    cout << "Array Content :\n";
    for (int row = 0; row < rows; row++)
    {
        cout << "ROW " << row << " : ";
        for (int col = 0; col < backupArr.getNumberUsed(row); col++)
        {
            cout << backupArr.at(row, col) << " ";
        }
        cout << "\n";
    }
}
