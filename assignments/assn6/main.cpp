#include <iostream>

#include "IntList.cpp"

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

    temp.push_back(32);
    temp.display();
    cout << endl;

    IntList temp2;
    temp2.push_back(32);
    temp2.display();
    cout << endl;
    temp2.push_back(45);
    temp2.display();
    cout << endl;

    temp.select_sort();
    temp.display();
    cout << endl;

    IntList temp3;
    temp3.select_sort();
    temp3.display();
    cout << endl;

    temp.display();
    cout << endl;
    temp.insert_sorted(10);
    temp.display();
    cout << endl;
    temp.insert_sorted(33);
    temp.display();
    cout << endl;
    temp.insert_sorted(4);
    temp.display();
    cout << endl;
    temp.insert_sorted(2);
    temp.display();
    cout << endl;

    IntList temp4;
    temp4.push_back(249);
    temp4.push_back(346);
    temp4.push_back(366);
    temp4.push_back(374);
    temp4.push_back(462);
    temp4.push_back(484);
    temp4.push_back(600);
    temp4.push_back(686);
    temp4.push_back(715);
    temp4.push_back(799);
    temp4.push_back(949);
    temp4.display();
    cout << endl;
    temp4.insert_sorted(800);
    temp4.display();
    cout << endl;

    IntList temp5;
    temp5.push_back(249);
    temp5.push_back(346);
    temp5.push_back(715);
    temp5.push_back(799);
    temp5.push_back(949);
    temp5.push_back(366);
    temp5.push_back(374);
    temp5.push_back(462);
    temp5.push_back(484);
    temp5.push_back(600);
    temp5.push_back(686);
    temp5.display();
    cout << endl;
    temp5.select_sort();
    temp5.display();
    cout << endl;


    cout << "End" << endl;
}
