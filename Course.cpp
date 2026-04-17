/*
# v在一个大学的选课系统中，包括两个类：CourseSchedule类和Course类，其关系为CourseSchedule类中的成员函数add和remove的参数是Course类的对象，courseSchedule类中要有一个成员变量用来存放多个Course.
# add和remove函数用来添加和删除一个coureschedule中的course.
这里请自己思考用来存放多个Course的成员变量应该如何设计，参考上课讲过的关于停车场的例子，course类的设计请自己完成（这里的CourseSchedule类是一个课程列表有多个课程对象）
# 用动态分配的链表存放 
*/
#include <iostream>
#include <string>
using namespace std;


class Course
{
    public:
        // construct without param
        Course() {}

        // construct with param
        Course(const string &course_to_input): couseName(course_to_input) {}


        void courseInput(string course_to_input)
        {
            couseName = course_to_input;
        }

        string courseOutput() const
        {
            return couseName;
        }

    private:
        string couseName;
};


class CourseSchedule
{
    public:

        // default construct
        CourseSchedule(): head(nullptr) {}

        // construct with param
        CourseSchedule(const Course &c): head(nullptr)
        {
            add(c);
        }

        // copy construct for deep copy
        CourseSchedule(const CourseSchedule &other) : head(nullptr)
        {
            Node *cur = other.head;
            while (cur != nullptr)
            {
                add(cur->course);
                cur = cur->next;
            }
        }

        // operator defined fo depp copy
        CourseSchedule &operator = (const CourseSchedule &other)
        {
            if (this == &other)
                return *this;    
            
            clear();
            Node *cur = other.head;
            while (cur != nullptr)
            {
                add(cur->course);
                cur = cur->next;
            }
            return *this;
        }

        ~CourseSchedule()
        {
            clear();
        }
        
        // output function
        void Test_elemALLout() const
        {
            if (head == nullptr)
                return ;

            Node *cur = head;
            
            cout << "head -> ";
            while (cur != nullptr)
            {
                cout << cur->course.courseOutput() <<" -> ";
                cur = cur->next;
            }
            cout << "nullptr" << '\n';
        }

        // add course TO LAST in course schedule
        void add(const Course &c)
        {
            Node *node = new Node;
            node->next = nullptr;

            // initialize value
            node->course = c;
            
            // link the node
            if (head == nullptr)
                head = node;
            else
            {
                Node *cur = head;
                while (cur->next != nullptr)
                    cur = cur->next;
  
                cur->next = node;
            }
        }

        // remove first matched course from course schedule
        void remove(const Course &c)
        {
            // if linked list is empty, return directly
            if (head == nullptr)
                return ;

            Node *prev = nullptr;
            Node *cur = head;

            // find targeted Course
            while ((cur != nullptr) && (cur->course.courseOutput() != c.courseOutput()))
            {
                prev = cur;
                cur =cur->next;
            }

            // cur reach the end of the linked list
            if (cur == nullptr)
                return ;
            // find correct node
            if (prev != nullptr)
                prev->next = cur->next;
            // find the correct node which is head (prev be nullptr)
            else
                head = cur->next;

            delete cur;
        }

    private:
        // delete linked list
        void clear()
        {
            Node *cur = head;
            while (cur != nullptr)
            {
                Node *to_delete = cur;
                cur = cur->next;
                delete to_delete;
            }
            head = nullptr;
        }

        // Node for linked list
        struct Node
        {
            Course course;
            Node *next;
        };

        Node *head;
};


int main()
{
    Course c1("Math");
    Course c2("CPP");
    Course c3("Physics");
    Course c4("Control Theory");

    CourseSchedule CS;
    
    // head -> c1 -> nullptr
    CS.add(c1);
    CS.Test_elemALLout();

    // head -> c1 -> c2 nullptr
    CS.add(c2);
    CS.Test_elemALLout();
   
    // head -> c1 -> c2 -> c3 -> nullptr
    CS.add(c3);
    CS.Test_elemALLout();

    // head -> c1 -> c3 -> nullptr
    CS.remove(c2);
    CS.Test_elemALLout();

    // test if remove elemnet is not in the list
    CS.remove(c4); // is not in the list
    CS.Test_elemALLout();
    
    return 0;
}
