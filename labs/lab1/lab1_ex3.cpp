//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab1/lab1_ex3.cpp 
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
#include <vector>
using namespace std;

int main()
{
	int input;
	vector<int> list;
	int search, found;
	
	cout << "Please enter in integers (0 to stop): ";
	cin >> input;
	cout << endl;
	
	while(input != 0)
	{
		list.push_back (input);
		cout << "Please enter in integers (0 to stop): ";
		cin >> input;
		cout << endl;
	}
	
	cout << "What number would you like to find and remove?: ";
	cin >> search;
	cout << endl;
	
	cout << "Found: " << found << endl;
	cout << "Result: ";
	for (int i=0; i <= list.size(); i++)
	{
		cout << list[i] << " ";
	}
	return 0;
}

