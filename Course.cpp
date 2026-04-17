/*
在一个大学的选课系统中，包括两个类：CourseSchedule类和Course类，其关系为CourseSchedule类中的成员函数add和remove的参数是Course类的对象，
courseSchedule类中要有一个成员变量用来存放多个Course.
add和remove函数用来添加和删除一个coureschedule中的course，
这里请自己思考用来存放多个Course的成员变量应该如何设计，参考上课讲过的关于停车场的例子，course类的设计请自己完成（这里的CourseSchedule类是一个课程列表有多个课程对象）

提示：1、可以用数组存放（100）(本题里面显示50分）
2、可以用动态分配的数组存放（120）(本题里面显示60分）
3、可以用动态分配的链表存放（200）(本题里面显示100分）

不同的实现方式将获得不同的上机分数 
*/

#include <iostream>
#include <string>
using namespace std;

#define MAX_COURSE_SIZE 100


class Course
{
    public:
        // construct without param
        Course()
        {

        }

        // construct with param
        Course(const string &course_to_input): couseName(course_to_input)
        {

        }


        void couseInput(string course_to_input)
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

        CourseSchedule()
        {
            new Node;
            head = nullptr;
            size = 0;
        }

        CourseSchedule(const Course &c)
        {
            add(c);
        }


        /*=========test============*/
        int Test_returnSize() const
        {
            return size;
        }
        /*=========test============*/

        /*=========test============*/
        void Test_elemALLout() const
        {
            if (size == 0)
                return;

            for (int j = 0; j < size; j++)
                cout << course_in_schedule[j].courseOutput() << " ";
            cout << "\n";
        }
        /*=========test============*/


        // add course TO LAST in course schedule
        void add(const Course &c)
        {
            Node *node = new Node;
            // initialize value
            node->course = c.courseOutput();
            
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

            // update size
            size ++;
        }

        // remove first matched course from course schedule
        void remove(const Course &c)
        {
            Node *prev = nullptr;
            Node *cur = head;

            // find targeted Course
            while ((cur->next != nullptr) && (cur->course.courseOutput() != c.courseOutput()))
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
            size --;
        }

    private:
        // Node for linked list
        struct Node
        {
            Course course;
            Node *next;
        };

        Node *head;
        int size;
};


int main()
{
    Course c1("Math");
    Course c2("CPP");
    Course c3("Physics");

    CourseSchedule CS(c1);
    // size should = 1
    cout << "c1 Couse in Course Schedule: "
         << CS.Test_returnSize() << endl;

    // size should = 2
    CS.add(c2);
    cout << "c2 Couse in Course Schedule: "
         << CS.Test_returnSize() << endl;

    // size should = 3
    CS.add(c3);
    cout << "c3 Couse in Course Schedule: "
         << CS.Test_returnSize() << endl;

    // Couses out
    CS.Test_elemALLout();

    // remove c3
    // size should be 2
    CS.remove(c3);
    cout << "c3 Couse REMOVED in Course Schedule: "
         << CS.Test_returnSize() << endl;

    // remove c2
    // size should be 1
    CS.remove(c2);
    cout << "c2 Couse REMOVED in Course Schedule: "
         << CS.Test_returnSize() << endl;

    // remove c1
    // size should be 0
    CS.remove(c1);
    cout << "c1 Couse REMOVED in Course Schedule: "
         << CS.Test_returnSize() << endl;

    // Couses out
    CS.Test_elemALLout();

    return 0;
}
