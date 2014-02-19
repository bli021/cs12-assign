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