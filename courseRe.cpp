#include <iostream>
using namespace std;


class Course
{
    private:
        string courseName;
    public:
        Course(): courseName(" ") {}
        Course(string couse_in): courseName(couse_in) {}
        Course(const Course &c): courseName(c.courseName) {}
        ~Course() {};

        // Course& operator=(const Course &other);

        // input courseName
        void courseInput(string course_in) { courseName = course_in; };
        string courseOutput() const {   return courseName;  };
};

/*Course& Course::operator=(const Course &other)
{
    if (this != &other)
    {
        this->courseName = other.courseName;
    }        

    return *this;
}*/

class CourseSchedule
{
    private:
        Course *courses;
        int numberOfCourse;
    public:
        CourseSchedule();
        CourseSchedule(int num_in, const Course *course_in);
        CourseSchedule(const CourseSchedule &cs);
        ~CourseSchedule();

        CourseSchedule& operator=(const CourseSchedule &other);

        void add(const Course &course_to_add);
        void remove(const Course &course_to_remove);
        void show() const ;
};

CourseSchedule::CourseSchedule(): courses(nullptr), numberOfCourse(0)
{}
CourseSchedule::CourseSchedule(int num_in, const Course *course_in): numberOfCourse(num_in)
{
    courses = new Course [numberOfCourse];
    
    for (int i=0; i<numberOfCourse; i++)
        courses[i] = course_in[i];
}
CourseSchedule::CourseSchedule(const CourseSchedule &cs): numberOfCourse(cs.numberOfCourse)
{
    courses = new Course [numberOfCourse];

    for (int i=0; i<numberOfCourse; i++)
        courses[i] = cs.courses[i];
}
CourseSchedule::~CourseSchedule()
{
    delete [] courses;
    courses = nullptr;
}

CourseSchedule& CourseSchedule::operator=(const CourseSchedule &other)
{
    if (this != &other)
    {
        delete [] courses;

        numberOfCourse = other.numberOfCourse;
        courses = new Course [numberOfCourse];
        for (int i=0; i<numberOfCourse; i++)
            courses[i] = other.courses[i];
    }        

    return *this;
}

void CourseSchedule::add(const Course &course_to_add) 
{
    // use Course *temp to restore *courses
    Course *temp = new Course [numberOfCourse];
    for (int i=0; i<numberOfCourse; i++)
        temp[i] = courses[i];

    numberOfCourse ++;

    // reallocate memory
    delete [] courses;
    courses = new Course [numberOfCourse];
    for (int i=0; i<numberOfCourse-1; i++)
        courses[i] = temp[i];
    
    // add the course
    courses[numberOfCourse-1] = course_to_add;  
    
    delete [] temp ; // release *temp 
}

void CourseSchedule::remove(const Course &course_to_remove) 
{
    for (int i=0; i<numberOfCourse; i++)
    {
        // not the last element, forward moveing
        if (i+1 < numberOfCourse && courses[i].courseOutput() == course_to_remove.courseOutput())
        {
            for (int j=i+1; j<numberOfCourse; j++)
                courses[j-1] = courses[j]; // move elemnts behind forward
            numberOfCourse --;
            break;
        }
        // last element, backward moving
        else if (i+1 == numberOfCourse && courses[i].courseOutput() == course_to_remove.courseOutput())
        {
            numberOfCourse --;
            break;
        }
    }
}

void CourseSchedule::show() const
{
    cout << endl;
    for (int i=0; i<numberOfCourse; i++)
        cout << courses[i].courseOutput() << ", ";
    cout << endl;
}


int main()
{
    Course *courses;
    courses = new Course [3];
    
    courses[0].courseInput("Math");
    courses[1].courseInput("Chinese");
    courses[2].courseInput("English");

    // inilialize cs
    CourseSchedule cs(3, courses);
    cs.show();

    // add a Course
    Course course_to_add("Physics");
    cs.add(course_to_add);
    cs.show();

    //remove a Course(rear)
    cs.remove(course_to_add);
    cs.show();

    // remove a Course(middle)
    cs.remove(courses[1]);
    cs.show();

    // remove a Course(head)
    cs.remove(courses[0]);
    cs.show();

    // remove a Course(not exist)
    cs.remove(course_to_add);
    cs.show();

    delete [] courses;
    courses = nullptr;

    return 0;
}