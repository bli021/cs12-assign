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
}
