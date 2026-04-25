#include <iostream>
using namespace std;


int main()
{
    int *p = new int [10];

    int *current = p;
    for (int i=0; i<10; i++)
    {    
        *current = i + 1;
        current ++;
    }

    int *temp = p;
    for (int j=0; j<10; j++)
    {
        cout << *temp << " " ;
        temp ++;
    }
    cout << endl;

    delete [] p; // delete p
    p = nullptr; 
    
    return 0;
}