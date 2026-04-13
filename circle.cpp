/*
实现一个名为SimpleCircle的简单圆类，其数据成员int *itsRadius为一个指向其半径值的指针，存放其半径值，设计函数读取和设置半径值，给出这个类的完整实现并用一下主函数测试该类。

提示：一个类成员为指针，不应该任意指向一个类外数据，要保持一个对象拥有自己的数据，请使用动态分配

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
*/
#include <iostream>
using namespace std;


class SimpleCircle
{
    public:
        // construct with param
        SimpleCircle(int Radius_in)
        {
            itsRadius = new int; // memory allocate
            *itsRadius = Radius_in;
        }

        // copy construct 
        SimpleCircle(const SimpleCircle &c_in)
        {
            itsRadius = new int;
            *itsRadius = *(c_in.itsRadius);
        }


        // assignment operator reload
        SimpleCircle& operator = (const SimpleCircle &other)
        {
            if (this != &other)
            {
                delete itsRadius;
                itsRadius = new int(*other.itsRadius);
            }
            return *this;
        }

        // decosntruct
        ~SimpleCircle()
        {
            delete itsRadius; // release memory
            itsRadius = nullptr; // not necessary, for safety concern
        }

        // set value to Radius of the circle
        void setR(int value_to_set)
        {
            *itsRadius = value_to_set;
        }

        // get value of the Radius of the cirlcle
        int getR() const
        {
            return *itsRadius;
        }

    private:
        int *itsRadius; // pointer points the radius of the cirlce
};


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
