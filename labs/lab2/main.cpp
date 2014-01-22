//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab2/lab2.cpp 
/// @brief Lab 2 for CS 12 Winter 2014
///
/// @author David Anderson [dande011@ucr.edu]
/// @date 1/15/2014
///
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
#define ARR_CAP 500

using namespace std;

/// @brief Appends a copy of the C-style string source to
///     the destination C-style string.
/// @param destination The destination array, which should
///     contain a C-style string, and be large enough to 
///     contain the concatenated resulting string.
/// @param source C-style string to be appended.
/// @return nothing
void mystrcat( char destination[], const char source[] );
unsigned mystrlen( const char cstring[] );
void mystrprint( char cstring[] );
void mystrprint( char cstring[] );


int main()
{
    // char stringaling[ARR_CAP] =         "jlcls\0";
    // char stringalingaling[ARR_CAP] =    "vyow\0";
    // cout << mystrlen( stringaling ) << endl;
    // mystrcat( stringaling, stringalingaling );
    // cout << mystrlen( stringaling ) << endl;
    // mystrprint(stringaling);
    return 0;
}

void mystrcat( char destination[], const char source[] )
{
    unsigned length = 0;
    unsigned destlen = 0;

    while( destination[destlen] != '\0' )
        destlen++;
    while( source[length] != '\0' )
        length++;

    for( unsigned i=0; i <= length; i++)
        destination[destlen + i] = source[i];
}

// void mystrprint( char cstring[] )
// {
    // unsigned length;
    // while( cstring[length])
// }

unsigned mystrlen( const char cstring[] )
{
    unsigned curr = 0;
    while( cstring[curr] != '\0' )
        curr++;
    return curr;
}

void mystrprint( char cstring[] )
{
    unsigned length = mystrlen(cstring);
    for( unsigned i = 0; i < length; i++)
        cout << cstring[i];
    cout << endl;
}