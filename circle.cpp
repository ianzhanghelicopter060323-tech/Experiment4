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