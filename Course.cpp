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

        CourseSchedule(): size(0)
        {

        }

        CourseSchedule(const Course &c): size(0)
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
            if (size >= MAX_COURSE_SIZE)
                return;

            course_in_schedule[size] = c;
            size++;
        }

        // remove first matched course from course schedule
        void remove(const Course &c)
        {
            if (size == 0)
                return;

            int removeIndex = -1;
            for (int i = 0; i < size; i++)
            {
                // find position to remove
                if (course_in_schedule[i].courseOutput() == c.courseOutput())
                {
                    removeIndex = i;
                    break;
                }
            }

            if (removeIndex == -1)
                return;

            // move elements forward
            for (int i = removeIndex; i < size - 1; i++)
            {
                course_in_schedule[i] = course_in_schedule[i + 1];
            }

            size--;
        }

    private:
        Course course_in_schedule[MAX_COURSE_SIZE]; // (basic requuiremnt) using array to store courses
        int size; // current number of courses
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
