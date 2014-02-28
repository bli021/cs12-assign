#include <iostream>

#include "IntList.cpp"

using namespace std;

int main()
{
    IntList temp;
    IntList temp2;
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

    temp.push_back(32);
    temp.display();
    cout << endl;

    temp2.push_back(32);
    temp2.display();
    cout << endl;
    temp2.push_back(45);
    temp2.display();
    cout << endl;
}
