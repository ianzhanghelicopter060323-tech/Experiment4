# deepcopy.cpp要求
程序填空，同时尝试运行改程序，熟悉深拷贝构造函数的写法
```cpp
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
```
# deepcopy_rewrite.cpp 要求

请编写一个完整的 C++ 程序，实现一个“动态点数组类”，用于练习 **对象数组、动态内存分配、析构函数、拷贝构造函数和深拷贝**。

## 程序要求

1. 定义一个 `Point` 类，表示平面上的一个点。

   - 私有数据成员包括 `x` 和 `y`，均为 `int` 类型。
   - 提供无参构造函数，使点的初始坐标为 `(0, 0)`。
   - 提供有参构造函数，可以用给定的 `x`、`y` 初始化点。
   - 提供 `move(int newX, int newY)` 成员函数，用于修改点的坐标。
   - 提供 `print()` 成员函数，用于输出点的坐标。
   - 提供 `getX()` 和 `getY()` 成员函数，用于返回点的横坐标和纵坐标。

2. 定义一个 `ArrayOfPoints` 类，表示一个动态创建的点数组。

   - 私有数据成员包括：
     - `Point *points`：指向动态创建的 `Point` 数组；
     - `int numberOfPoints`：表示数组中点的个数。
   - 提供有参构造函数 `ArrayOfPoints(int n)`，根据参数 `n` 动态创建包含 `n` 个 `Point` 对象的数组。
   - 提供析构函数，释放动态创建的点数组空间。
   - 提供成员函数 `Point& element(int index)`，返回指定下标的点对象引用，使外部可以修改数组中的某个点。
   - 提供拷贝构造函数，实现深拷贝：当用一个 `ArrayOfPoints` 对象初始化另一个对象时，两个对象应拥有各自独立的动态数组空间，而不是共用同一块内存。

3. 在 `main()` 函数中完成测试：

   - 创建一个包含 2 个点的 `ArrayOfPoints` 对象 `pointsArray1`。
   - 分别将第 0 个点移动到 `(5, 10)`，第 1 个点移动到 `(15, 20)`。
   - 使用 `pointsArray1` 拷贝构造出另一个对象 `pointsArray2`。
   - 输出 `pointsArray2` 中两个点的坐标。
   - 修改 `pointsArray1` 中两个点的坐标，例如改为 `(25, 30)` 和 `(35, 40)`。
   - 再次输出 `pointsArray2` 中两个点的坐标。
   - 如果程序实现了深拷贝，则 `pointsArray2` 的坐标不应随着 `pointsArray1` 的修改而改变。

4. 程序中应适当输出构造函数、拷贝构造函数和析构函数的提示信息，便于观察对象创建、复制和释放的过程。
# new.cpp要求
声明一个int型指针，用new语句为其分配包含10个元素的地址空间，并赋值为1到10并打印；然后释放空间 

# Student.cpp要求
在前一次的学生类基础上做添加，写一个学生成绩类：

1. 类名：Student
2. （数据成员，私有数据）：学号（No，int类型）、姓名（Name，字符数组类型）、数学成绩（Math，double类型）、物理成绩（Phi，double类型）、总分（Sum，double类型）。
3. （函数成员，公有成员）：无参构造函数，有参构造函数，拷贝构造函数，析构函数，定义能输入学生成绩的成员函数```Input()```，能计算学生总分的成员函数```Sum()```，能显示学生成绩的成员函数Show()。
4. 编写主函数,写一个```Student```数组，存入至少3个学生的成绩，并求出所有学生的数学总成绩和全部科目总成绩。 

# circle.cpp
1. 实现一个名为```SimpleCircle```的简单圆类，其数据成员```int *itsRadius```为一个指向其半径值的指针，存放其半径值，设计函数读取和设置半径值，给出这个类的完整实现并用一下主函数测试该类。
2. 提示：一个类成员为指针，不应该任意指向一个类外数据，要保持一个对象拥有自己的数据,请使用动态分配
```cpp
int main()

{

         SimpleCircle c1(10);

         cout<<"c1's radius is:  "<<c1.getR()<<endl;

         SimpleCircle c2(c1);

         c2.setR(20);

         cout<<"c1's radius is:  "<<c1.getR()<<endl;

         cout<<"c2's radius is:  "<<c2.getR()<<endl;

         return 0;

}

cl' s radius is: 10
cl' s radius is: 10
c2' s radius is: 20
```

# Course.cpp 要求
在一个大学的选课系统中，包括两个类：```CourseSchedule```类和```Course```类，其关系为```CourseSchedule```类中的成员函数```add```和```remove```的参数是```Course```类的对象，```courseSchedule```类中要有一个成员变量用来存放多个```Course```，```add```和```remove```函数用来添加和删除一个```coureschedule```中的```course```，这里请自己思考用来存放多个```Course```的成员变量应该如何设计，参考上课讲过的关于停车场的例子，```course```类的设计请自己完成（这里的```CourseSchedule```类是一个课程列表有多个课程对象）

提示：1、可以用数组存放（100）(本题里面显示50分)
2、可以用动态分配的数组存放（120）(本题里面显示60分)
3、可以用动态分配的链表存放（200）(本题里面显示100分)

不同的实现方式将获得不同的上机分数 