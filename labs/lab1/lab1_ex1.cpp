//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab1/lab1_ex1.cpp 
/// @brief Lab 01 for CS 12 Winter 2014
///
/// @author David Anderson [dande011@ucr.edu]
/// @date 01/08/2014
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
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	int number_to_guess = rand()%100;
   
	cout << "Guess a number between 1 and 100." << endl << "? ";
     
    int guess;
    cin >> guess;
    
    while ( number_to_guess != guess )
    {

		if ( guess >= number_to_guess )
		{
			cout << "Try lower." << endl << "? ";
		}
		else if ( guess <= number_to_guess )
		{
			cout << "Try Higher." << endl << "? ";
		}
		cin >> guess;
    }

    cout << "You guessed right!!!" << endl;
    return 0;
}
