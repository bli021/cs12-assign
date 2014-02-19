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

const int & IntVector::at( unsigned index ) const
{
    if(index < sz)
        return data[index];
    else
        exit(1);
}