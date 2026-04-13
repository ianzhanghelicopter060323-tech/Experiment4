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
        Data = 0.0;
        Sum = 0.0;
    }

    //construct with param
    Student(int No_in, const char *Name_in, double Math_in, double Phi_in, double Data_in)
    {
        Name = NULL;
        No = No_in;
        CopyName(Name_in);
        Math = Math_in;
        Phi = Phi_in;
        Data = Data_in;

        UpdateSum();
    }

    //construct copy
    Student(const Student &stu)
    {
        Name = NULL;
        No = stu.No;
        CopyName(stu.Name);
        Math = stu.Math;
        Phi = stu.Phi;
        Data = stu.Data;
        Sum = stu.Sum;
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
        Data = stu.Data;
        Sum = stu.Sum;

        return *this;
    }

    //deconstruct
    ~Student()
    {
        delete [] Name;
    }

    //Information input
    void Input(int No_in, const char *Name_in, double Math_in, double Phi_in, double Data_in)
    {
        No = No_in;
        CopyName(Name_in);
        Math = Math_in;
        Phi = Phi_in;
        Data = Data_in;
        UpdateSum();
    }

    //show student information
    void Show(void)
    {
        cout << "Student ID:" << No << endl;
        cout << "Student name:" << Name << endl;
        cout << "The Math grade:" << Math << endl;
        cout << "The Physics grade:" << Phi << endl;
        cout << "The Data Structure grade:" << Data << endl;
        cout << "Sum of the grade:" << Sum << endl;
    }

    //Calculate the sum of all grades
    void GetSum(void)
    {
        UpdateSum();
    }

private:
    // get sum with private function
    void UpdateSum(void)
    {
        Sum = Math + Phi + Data;
    }

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
    double Data;
    double Sum;
};





int main(void)
{
    char name1[] = "Alice";
    char name2[] = "Bob";
    char name3[] = "Cindy";

    // test default constructor
    Student stu1;
    cout << "stu1 default information:" << endl;
    stu1.Show();
    cout << endl;

    // test constructor with parameters
    Student stu2(1001, name1, 88.5, 92.0, 90.5);
    cout << "stu2 information(auto-sum in constructor):" << endl;
    stu2.Show();
    cout << endl;

    // test copy constructor
    Student stu3(stu2);
    cout << "stu3(copy from stu2) information:" << endl;
    stu3.Show();
    cout << endl;

    // test Input with auto-sum
    stu1.Input(1002, name2, 76.0, 85.5, 91.0);
    cout << "stu1 information after Input(auto-sum):" << endl;
    stu1.Show();
    cout << endl;

    // test GetSum function
    Student stu4(1003, name3, 60.0, 70.0, 80.0);
    stu4.GetSum();
    cout << "stu4 information after calling GetSum:" << endl;
    stu4.Show();
    cout << endl;

    // test assignment operator
    Student stu5;
    stu5 = stu2;
    cout << "stu5 information after assignment from stu2:" << endl;
    stu5.Show();

    return 0;
}
