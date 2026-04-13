/*
在前一次的学生类基础上做添加，写一个学生成绩类：

（1）类名：Student

（2）（数据成员，私有数据）：学号（No，int类型）、姓名（Name，字符数组类型）、数学成绩（Math，double类型）、物理成绩

（Phi，double类型）、总分（Sum，double类型）。

（3）（函数成员，公有成员）：无参构造函数，有参构造函数，拷贝构造函数，析构函数，定义能输入学生成绩的成员函数Input()，

能计算学生总分的成员函数Sum()，能显示学生成绩的成员函数Show()。

（4）编写主函数,写一个Student数组，存入至少3个学生的成绩，并求出所有学生的数学总成绩和全部科目总成绩。 
*/

#include <iostream>
#include <cstring>
#define STUNUM 3
using namespace std;


class Student
{
public:

    //construct without param
    Student()
    {
        No = 0;
        Name = NULL;
        CopyName("");

        Math = 0.0;
        Phi = 0.0;
        //Data = 0.0;
        Sum_of_grade = 0.0;
    }

    //construct with param
    Student(int No_in, const char *Name_in, double Math_in, double Phi_in/*, double Data_in*/)
    {
        Name = NULL;
        No = No_in;
        CopyName(Name_in);
        Math = Math_in;
        Phi = Phi_in;
        //Data = Data_in;

        Sum_of_grade = Sum(); // renew Sum_of_grade
    }

    //construct copy
    Student(const Student &stu)
    {
        Name = NULL;
        No = stu.No;
        CopyName(stu.Name);
        Math = stu.Math;
        Phi = stu.Phi;
        //Data = stu.Data;
        Sum_of_grade = stu.Sum_of_grade;
    }

    // assignment operator
    Student &operator=(const Student &stu)
    {
        if (this == &stu)
        {
            return *this;
        }

        No = stu.No;
        CopyName(stu.Name);
        Math = stu.Math;
        Phi = stu.Phi;
        //Data = stu.Data;
        Sum_of_grade = stu.Sum_of_grade;

        return *this;
    }

    //deconstruct
    ~Student()
    {
        delete [] Name;
    }

    //Stuent information input
    void Input(int No_in, const char *Name_in, double Math_in, double Phi_in/*, double Data_in*/)
    {
        No = No_in;
        CopyName(Name_in);
        Math = Math_in;
        Phi = Phi_in;
        //Data = Data_in;
        
        Sum_of_grade = Sum(); // renew Sum_of_grade
    }

    //show student information
    void Show(void)
    {
        cout << "Student ID:" << No << endl;
        cout << "Student name:" << Name << endl;
        cout << "The Math grade:" << Math << endl;
        cout << "The Physics grade:" << Phi << endl;
        //cout << "The Data Structure grade:" << Data << endl;
        cout << "Sum of the grade:" << Sum_of_grade << endl;
    }

    //Calculate the sum of all grades
    double Sum()
    {
        Sum_of_grade = Math + Phi;
        return Sum_of_grade;
    }

    // output math grade
    // for convenience, add a function to otput Math
    int mathOutput() const
    {
        return Math;
    }

private:

    // copy string Name with private function
    void CopyName(const char *Name_in)
    {
        if (Name_in == NULL)
        {
            Name_in = "";
        }

        delete [] Name;
        Name = new char[strlen(Name_in) + 1];

        if (Name == NULL)
        {
            return;
        }

        strcpy(Name, Name_in);
    }

    int No;
    char *Name;

    double Math;
    double Phi;
    //double Data;
    double Sum_of_grade;
};


int main(void)
{
    // 3 constant memory spaces are allocated
    Student *stu = new Student[STUNUM]; 
    
    // 3 stu obects envalued
    stu[0].Input(1, "Alice", 80, 85);
    stu[1].Input(2,"Bill", 75, 90);
    stu[2].Input(3, "Charles", 95, 60);

    // Student grade show
    for (int i=0; i<STUNUM; i++)
        stu[i].Show();
    
    // find the sum of math and all lectures
    int sumMath = 0;
    int sumAll = 0;
    for (int i=0; i<STUNUM; i++)
    {
        sumMath += stu[i].mathOutput();
        sumAll += stu[i].Sum();
    }

    // sum-calculation outcome output
    cout<<"Total math grade:"<<sumMath<<endl;
    cout<<"Total grade of all the students:"<<sumAll<<endl;

    return 0;
}
