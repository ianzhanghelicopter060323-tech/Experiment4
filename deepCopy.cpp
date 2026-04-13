/*
#include<iostream>

using namespace std;

#include <iostream>

using namespace std;

class Point

{

public:

Point();

Point(int x, int y);

~Point();

void move(int newX, int newY);

void print();

int GetX() {return x;}

int GetY() {return y;}

private:

int x,y;

};

Point::Point()

{

x = 0;

y = 0;

cout<<"Default constructor called\n"; 

}

Point::Point(int xx, int yy)

{

x = xx;

y = yy;

cout<<"Constructor called"<<endl;

}

Point::~Point()

{

cout<<"Destructor called"<<endl;

}



void Point::move(int newX, int newY)

{

x = newX;

y = newY;

cout<<"Moving to ( "<<x<<" , "<<y<<" ) "<<endl;

}



void Point::print()

{

cout<<"Point at ( "<<x<<" , "<<y<<" ) "<<endl;

}

class ArrayOfPoints

{  

public:

     ArrayOfPoints(int n)

     { 

 numberOfPoints=n;  

          points=new Point[n]; 

}

ArrayOfPoints(ArrayOfPoints &AoP)

{   

numberOfPoints = AoP. numberOfPoints;  

    points =           （1）            ；

    for (int i=0; i<         (5)         ; i++)

         points[i].move(        （2）          );

}

     ~ArrayOfPoints()

     { 

 cout<<"Deleting..."<<endl;

         numberOfPoints=0;   

                     （3）               ;  

    }

     Point& Element(int n)

     {  

 return          (4)               ;

}

private:

     Point *points;

     int numberOfPoints;

};

int main()

{

         ArrayOfPoints pointsArray1 (2);   

        

         ArrayOfPoints pointsArray2(pointsArray1);

 pointsArray1.Element(0).move(25,30);

         pointsArray2.Element(1).print()；

} 
*/


#include <iostream>
using namespace std;


class Point
{
    public:
        Point();
        Point(int x, int y);
        ~Point();

        void move(int newX, int newY);
        void print();

        int GetX() {return x;}
        int GetY() {return y;}

    private:
        int x,y;
};

Point::Point()
{
    x = 0;
    y = 0;
    cout<<"Default constructor called\n"; 
}

Point::Point(int xx, int yy)
{
    x = xx;
    y = yy;
    cout<<"Constructor called"<<endl;
}

Point::~Point()
{
    cout<<"Destructor called"<<endl;
}

void Point::move(int newX, int newY)
{
    x = newX;
    y = newY;
    cout<<"Moving to ( "<<x<<" , "<<y<<" ) "<<endl;
}

void Point::print()
{
    cout<<"Point at ( "<<x<<" , "<<y<<" ) "<<endl;
}


class ArrayOfPoints
{  
    public:
        ArrayOfPoints(int n)
        { 
            numberOfPoints=n;  
            points=new Point[n]; 
        }

ArrayOfPoints(ArrayOfPoints &AoP)
{   
    numberOfPoints = AoP. numberOfPoints;  

    points = /*(1)*/ new Point[numberOfPoints];
    for (int i=0; i</*(5)*/numberOfPoints; i++)
        points[i].move(/*(2)*/AoP.points[i].GetX(),AoP.points[i].GetY());
}

    ~ArrayOfPoints()
    { 
        cout<<"Deleting..."<<endl;
        numberOfPoints=0;   
        /*(3)*/
        delete[] points;
        points = nullptr;
    }

    Point& Element(int n)
    {  
        return /*(4)*/points[n];
}

private:

    Point *points;
    int numberOfPoints;
};


int main()
{

    ArrayOfPoints pointsArray1 (2);   
    ArrayOfPoints pointsArray2(pointsArray1);

    pointsArray1.Element(0).move(25,30);
    pointsArray2.Element(1).print();
    return 0;
} 
