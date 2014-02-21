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

#include "IntVector.h"
#include <cstdlib>
#include <iostream>



/* ---PRIVATE--- */

void IntVector::expand()
{
    int* temp = data;
    cap *= 2;
    data = new int[cap];
    for(int i=0; i < sz; i++)
        data[i] = temp[i];
    delete temp;
}

void IntVector::expand( unsigned amount )
{
    int* temp = data;
    cap += amount;
    data = new int[cap];
    for(int i=0; i < sz; i++)
        data[i] = temp[i];
    delete temp;
}

/* ---PUBLIC--- */

IntVector::IntVector(unsigned size):sz(size),cap(size)
{
    data = new int[size];
    for(unsigned i=0; i < size; i++)
        data[i] = 0;
}

IntVector::IntVector(unsigned size, int value):sz(size),cap(size)
{
    data = new int[size];
    for(unsigned i=0; i < size; i++)
        data[i] = value;
}

int & IntVector::at( unsigned index )
{
    if(index < sz)
        return data[index];
    else
    {
        std::cout << "Exit with error 1 status: in member function at: out of bounds." << std::endl;
        exit(1);
    }
}

void IntVector::insert( unsigned index, int value )
{
    sz++;
    if(index > sz)
    {
        std::cout << "Exit with error 1 status: in member function insert: index out of bounds" << std::endl;
        exit(1);
    }
    else if(sz > capacity())
        expand();
    for(int i=sz; i > index; i--)
        data[i] = data[i-1];
    data[index] = value;

}
