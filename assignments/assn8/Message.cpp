#include <iostream>

#include "Message.h"

using namespace std;

Message::~Message()
{
    for(unsigned i = 0; i < child_list.size(); i++)
        delete child_list.at(i);
}

// void Message::display() const //vitrified
// {
//     cout << subject << endl;
//     cout << "from " << author << ": " << body << endl;
// }

void Message::print(unsigned indentation) const
{
    string indent(indentation,'\t');
    cout << "Message #" << id << ": " << subject << endl;
    cout << "from " << author << ": " << body << endl;
    // cout << "Author: " << author << endl;
    // cout << "Subject: " << subject << endl;
    // cout << "Body: " << body << endl;
}