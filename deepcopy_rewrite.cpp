#include <iostream>
using namespace std;


class Point
{
    private:
        int x;
        int y;
    public:
        Point(): x(0), y(0)
        {
            cout << "Default constructor called" << endl;
        }
        Point(int x_in, int y_in): x(x_in), y(y_in)
        {
            cout << "Constructor called" << endl;
        }
        ~Point()
        {
            cout << "Destructor called" << endl;
        }

        // move (x, y) to (newX, newY)
        void move(int newX, int newY)
        {
            x = newX;
            y = newY;
        }

        // print (x, y)
        void print() const
        {
            cout << "(" << x << ", " << y << ")" << endl;
        }

        int getX() const
        {
            return x;
        }
        int getY() const 
        {
            return y;
        }
};


class ArrayOfPoints
{
    private:
        Point *points;
        int numberOfPoints;
    public:
        ArrayOfPoints(int n): numberOfPoints(n)
        {
            cout << "ArrayOfPoints constructor called" << endl;
            points = new Point [n]; // create a Point array with size of n
        }
        // copy construct: DEEP COPY NEEDED
        ArrayOfPoints(const ArrayOfPoints &ap): numberOfPoints(ap.numberOfPoints)
        {
            cout << "ArrayOfPoints copy constructor called" << endl;
            points = new Point [numberOfPoints];

            for (int i=0; i<numberOfPoints; i++)
                points[i] = ap.points[i]; // NOT SAME AS THE EXAMPLE
        }

        ~ArrayOfPoints()
        {
            cout << "ArrayOfPoints destructor called" << endl;
            delete [] points;
            points = nullptr;
        }

        // element finding function: return quotation of the element
        Point &element(int index)
        {
            if (index < 0 || index >= numberOfPoints)
            {
                cout << "ERROR" << endl;
                return *points;
            }

            return points[index];
        }
};


int main()
{
    ArrayOfPoints pointsArray1(2);
    pointsArray1.element(0).move(5, 10);
    pointsArray1.element(1).move(15, 20);

    // copy construct and deep copy test
    ArrayOfPoints pointsArray2(pointsArray1);
    pointsArray2.element(0).print(); // should be (5, 10)
    pointsArray2.element(1).print(); // should be (15, 20)

    pointsArray1.element(0).print(); // should be (5, 10)
    pointsArray1.element(1).print(); // sould be (15, 20)

    // changing point axis in pointArray1
    pointsArray1.element(0).move(25, 30);
    pointsArray1.element(1).move(35, 40);
    
    // show axis again
    pointsArray2.element(0).print(); // should be (5, 10)
    pointsArray2.element(1).print(); // should be (15, 20)

    pointsArray1.element(0).print(); // should be (25, 30)
    pointsArray1.element(1).print(); // sould be (35, 40)

    return 0;
}
