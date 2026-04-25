#include <iostream>
using namespace std;


class SimpleCircle
{
    private:
        int *itsRadius;
    public:
        SimpleCircle();
        SimpleCircle(const int &radius_in);
        SimpleCircle(const SimpleCircle &sc);
        ~SimpleCircle();

        int radiusGet() const;
        void radiusSet(const int &radius_to_set);
};

SimpleCircle::SimpleCircle()
{
    itsRadius = new int;
    *itsRadius = 0;
}
SimpleCircle::SimpleCircle(const int &radius_in)
{
    itsRadius = new int;

    if (radius_in < 0)
    {
        cout << "ERROR" << endl;
        *itsRadius = 0;
    }
    else
    {
        *itsRadius = radius_in;
    }
}

SimpleCircle::SimpleCircle(const SimpleCircle &sc)
{
    itsRadius = new int;
    *itsRadius = *(sc.itsRadius);
}
SimpleCircle::~SimpleCircle()
{
    delete itsRadius;
    itsRadius = nullptr;
}


int SimpleCircle::radiusGet() const
{
    return *itsRadius;
}
void SimpleCircle::radiusSet(const int &radius_to_set)
{
    if (radius_to_set < 0)
    {
        cout << "ERROR" << endl;
        return ;
    }

    *itsRadius = radius_to_set;
}


int main()

{

         SimpleCircle c1(10);

         cout<<"c1's radius is:  "<<c1.radiusGet()<<endl;

         SimpleCircle c2(c1);

         c2.radiusSet(20);

         cout<<"c1's radius is:  "<<c1.radiusGet()<<endl;

         cout<<"c2's radius is:  "<<c2.radiusGet()<<endl;

         return 0;

}