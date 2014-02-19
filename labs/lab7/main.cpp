#include <iostream>

#include "IntVector.h"

using namespace std;

int main()
{
    IntVector data(4,6);
    cout << "Yes, it ran" << endl;
    cout << data.size() << endl;
    cout << data.capacity() << endl;
    cout << data.empty() << endl;
    cout << data.at(2) << endl;
    return 0;
}