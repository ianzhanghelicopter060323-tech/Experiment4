/*
声明一个int型指针，用new语句为其分配包含10个元素的地址空间，并赋值为1到10并打印；然后释放空间 
*/

#include <iostream>
#define SIZE 10
using namespace std;


class NewPrt
{
    public:
        NewPrt()
        {
            cout<<"CONSTRUCT CALLED"<<endl;
            pointer = new int[SIZE]; 
        }
        
        ~NewPrt()
        {
            cout<<"DECONSTRUCT CALLED"<<endl;
            delete [] pointer;
            pointer = nullptr;
        }


        void prtPrint() const
        {
            for (int i=0; i<SIZE; i++)
                cout<<pointer[i]<<" ";

            cout<<'\n';
        }

        void setPointer(int value_input, int pos_input)
        {
            pointer[pos_input] = value_input;
        }
    private:
        int *pointer; // int pointer. size 10
};


int main()
{
    NewPrt ptr;

    // pointer envalued
    for (int i=0; i<SIZE; i++)
        ptr.setPointer(i+1, i);

    ptr.prtPrint();
    return 0;
}