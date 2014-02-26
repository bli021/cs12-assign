#include <iostream>

#include "IntList.h"

using namespace std;

int main()
{
    IntList temp;
    temp.display();
    cout << endl;
    temp.push_front(5);
    temp.display();
    cout << endl;
    temp.push_front(15);
    temp.push_front(45);
    temp.display();
    cout << endl;
    temp.pop_front();
    temp.display();
    cout << endl;
}