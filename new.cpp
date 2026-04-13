/*
声明一个int型指针，用new语句为其分配包含10个元素的地址空间，并赋值为1到10并打印；然后释放空间 
*/

#include <iostream>
using namespace std;


int main() {
    int* p = new int[10]; // allocate 10 memory spaces

    // envalued
    for (int i = 0; i < 10; ++i) 
    { 
        p[i] = i + 1;
    }

    // print values
    for (int i = 0; i < 10; ++i) 
    {
        cout << p[i] << " ";
    }
    cout << '\n';

    // memory spaces free
    delete[] p;
    p = nullptr;

    return 0;
}
