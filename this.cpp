#include <iostream>
#include <cstring>
using namespace std;


class Student
{
    private:
        char name[30];
        int id;
        int score;
    public:
        Student(const char* name, int id, int score);
        ~Student() {};

        Student &operator=(const Student &other);

        Student& setInfo(const char* name, int id, int score);
        Student& addScore(int score);

        void print() const 
        {
            cout << "Name: " << name
                 << ", ID: " << id
                 << ", Score: " << score 
                 << endl;    
        }
};

Student::Student(const char* name, int id, int score)
{
    strncpy(this->name, name, 29);
    this->name[29] = '\0';

    this->id = id;
    this->score = score;
}

Student& Student::operator=(const Student &other)
{
    if (this != &other)
    {
        strncpy(this->name, other.name, 29);
        this->name[29] = '\0';

        id = other.id;
        score = other.score;
    }

    return *this;
}

Student& Student::setInfo(const char* name, int id, int score)
{
    strncpy(this->name, name, 29);
    this->name[29] = '\0';

    this->id = id;
    this->score = score;
    
    return *this;
}

Student& Student::addScore(int score)
{
    this->score += score;
    return *this;
}


int main()
{
    Student s1("Alice", 1001, 80);
    Student s2("Bob", 1002, 90);

    // infor print
    s1.print();
    s2.print();

    // addScore() chain-call test
    s1.addScore(5).addScore(10).print();

    // setInfor() & add Score() chain-call test
    s2.setInfo("Cindy", 1003, 88).addScore(7).print();

    //operator= test
    s1 = s2;
    s1.print();

    s1 = s1;
    s1.print();

    return 0;
}