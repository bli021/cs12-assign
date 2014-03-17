//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment1/main.cpp 
/// @brief Assignment 2 for CS 12 Winter 2014
///
/// @author David Anderson [dande011@ucr.edu]
/// @date <2/19/2014>
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 021
/// @par
///     TA: Nkenge Wheatland
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  =============== END ASSESSMENT HEADER ==================
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

void Message::add_child(Message* child)
{
    cout << "Adding child to " << id << " at id " << child << endl;
}