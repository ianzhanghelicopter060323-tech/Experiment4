#include <iostream>
#include <cstring>
using namespace std;


class Student
{
    private:
        int No;
        char *Name;

        double Math;
        double Phi;
        double Sum;

        void sumCalculate() { Sum = Math + Phi; }
    public:
        Student();
        Student(const char *name_in, int no_in, int math_in, int phi_in);
        Student(const Student &stu);
        ~Student();

        Student& operator=(const Student &other);

       // student information input
       void input(const char *name_in, int no_in, int math_in, int phi_in);
       // calculate sum
       double sum();
       // show student information
       void show() const;
};


Student::Student(): No(0), Math(0), Phi(0), Sum(0)
{
    Name = new char [50];
    Name[0] = '\0';
}
Student::Student(const char *name_in, int no_in, int math_in, int phi_in): No(no_in), Math(math_in), Phi(phi_in)
{
    Name = new char [50];
    strncpy(Name, name_in, strlen(name_in));
    Name[strlen(name_in)] = '\0';

    sumCalculate();
}
Student::Student(const Student &stu): No(stu.No), Math(stu.Math), Phi(stu.Phi)
{
    Name = new char [50];
   strncpy(Name, stu.Name, strlen(stu.Name));
    Name[strlen(stu.Name)] = '\0';

    sumCalculate();
}
Student::~Student()
{
    delete [] Name;
    Name = nullptr;
}


Student& Student::operator=(const Student &other)
{
    if (this != &other)
    {
        delete [] Name;

        Name = new char [50];
        strncpy(Name, other.Name, strlen(other.Name));
        Name[strlen(other.Name)] = '\0';

        No = other.No;
        Math = other.Math;
        Phi = other.Phi;
                
        sumCalculate();
    }

    return *this;
}


void Student::input(const char *name_in, int no_in, int math_in, int phi_in)
{
    // Name = new char [50];
    // already allocated enough space
    strncpy(Name, name_in, strlen(name_in));
    Name[strlen(name_in)] = '\0';

    No = no_in;
    Math = math_in;
    Phi = phi_in;

    sumCalculate();
}

double Student::sum()
{
    sumCalculate();
    return Sum;
}

void Student::show() const
{
    cout << "No: "
         << No << endl;
    cout << "Name: "
         << Name << endl;
    cout << "Math: "
         << Math << endl;
    cout << "Phi: "
         << Phi << endl;
    cout << "Sum: "
         << Sum << endl;
}


int main()
{
    char Name1[] = "Alice";
    char Name2[] = "Bob";
    char Name3[] = "Charlie";
    
    Student *stu;
    stu = new Student [3];
    
    stu[0].input(Name1, 1001, 85, 90);
    stu[1].input(Name2, 1002, 90, 95);
    stu[2].input(Name3, 1003, 100, 100);

    for (int j=0; j<3; j++)
        stu[j].show();
    
    stu[2] = stu[1];
    
    for (int j=0; j<3; j++)
        stu[j].show();

    delete [] stu;
    return 0;
}