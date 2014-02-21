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
    if(empty())
    {
        sz++;
        cap++;
        data = new int[capacity()];
    }
    else
    {
        int* temp = data;
        cap *= 2;
        data = new int[capacity()];
        for(unsigned i=0; i < size(); i++)
            data[i] = temp[i];
        delete [] temp;
    }
}

void IntVector::expand( unsigned amount )
{
    int* temp = data;
    cap += amount;
    data = new int[capacity()];
    for(unsigned i=0; i < size(); i++)
        data[i] = temp[i];
    delete [] temp;
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

IntVector::~IntVector()
{
    delete[] data;
}

const int & IntVector::at( unsigned index ) const
{
    std::cout << "This is the accessor" << std::endl;
    if(index >= size())
    {
        std::cout << "Exit with error 1 status: in member function at: out of bounds." << std::endl;
        exit(1);
    }
    else
    { 
        std::cout << "data "<< data[index] << std::endl;
        return data[index];
    }
}

int & IntVector::at( unsigned index )
{
    std::cout << "This is the manipulator." << std::endl;
    if(index >= size())
    {
        std::cout << "Exit with error 1 status: in member function at: out of bounds." << std::endl;
        exit(1);
    }
    else
    {
        // std::cout << index << std::endl;
        // std::cout << "data "<< data[index] << std::endl;
        return data[index];
    }
}

void IntVector::insert( unsigned index, int value )
{
    sz++;
    if(index > size())
    {
        std::cout << "Exit with error 1 status: in member function insert: index out of bounds" << std::endl;
        exit(1);
    }
    else if(sz > capacity())
        expand();
    for(unsigned i=sz; i > index; i--)
        data[i] = data[i-1];
    data[index] = value;

}

void IntVector::erase( unsigned index )
{
    sz--;
    if(index > size())
    {
        std::cout << "Exit with error 1 status: in member function erase: index out of bouds" << std::endl;
        exit(1);
    }
    for(unsigned i=index; i < size(); i++)
        data[i]=data[i+1];
}

void IntVector::assign( unsigned n, int value )
{
    if(n > capacity())
        expand( (n > capacity()*2) ? n-capacity() : capacity() );
    sz = n;
    for(unsigned i = 0; i < size(); i++)
        data[i] = value;
}

void IntVector::push_back( int value )
{
    sz++;
    expand(1);
    if(size() > capacity())
        expand();
    data[size()] = value;
}

void IntVector::pop_back()
{
    if(empty())
    {
        std::cout << "Exit with error 1 status: in member function pop_back: cannot reduce size of empty array" << std::endl;
        exit(1);
    }
    sz--;
}

void IntVector::resize( unsigned input )
{
    if(input < size())
        sz = input;
    else if(input > size())
    {
        if (input < capacity())
            sz = input;
        else
        {
            expand((input > capacity()*2) ? input-capacity() : capacity());
            for(unsigned i=size()+1; i <= input; i++)
                data[i] = 0;
            sz = input;
        }
    }
}

void IntVector::resize( unsigned input, int value )
{
    if(input < size())
        sz = input;
    else if(input > size())
    {
        if (input < capacity())
            sz = input;
        else
        {
            expand((input > capacity()*2) ? input-capacity() : capacity() );
            for(unsigned i=size()+1; i <= input; i++)
                data[i] = value;
            sz = input;
        }
    }
}

void IntVector::reserve( unsigned n )
{
    if( capacity() < n )
        expand((n > capacity()*2 ) ? n-capacity() : capacity());
}
