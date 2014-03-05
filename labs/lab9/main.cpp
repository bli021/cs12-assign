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
#include <string>

using namespace std;

void reverse(string &s, int i)
{
    if(i >= s.size()/2)
        return;
    else
    {
	   swap( s.at(i), s.at( (s.size()-1) - i) );
       reverse(s, i + 1);
   }
}

void reverse(string &s)
{
    reverse(s, 0);
}

int main()
{
	string temp;
	cout << "Input a string:\t";
	cin >> temp;

	reverse(temp);
	cout << "Reversed:\t" << temp << endl;

    reverse(temp);
    cout << "Re-Reversed:\t" << temp << endl;
	return 0;
}