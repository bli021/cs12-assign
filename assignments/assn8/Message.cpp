#include <iostream>

#include "Message.h"

using namespace std;

void Message::display() const
{
    cout << subject << endl;
    cout << "from " << author << ": " << body << endl;
}