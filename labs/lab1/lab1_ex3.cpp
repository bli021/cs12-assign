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

int search(vector<int>&, int);

void remove(vector<int>&, int);

int main()
{
	int input;
	vector<int> list;
	int number, foundIndex;
	
	cout << "Please enter in integers (0 to stop): ";
	cin >> input;
	
	while(input != 0)
	{
		list.push_back (input);
		cin >> input;
	}
	cout << endl;
	cout << "What number would you like to find and remove?: ";
	cin >> number;
	cout << endl;
	foundIndex = search(list, number);
	//cout << "foundIndex: " << foundIndex << endl;
	if(foundIndex != -1)
		remove(list, foundIndex);
	//cout << "removed" << endl;
	
	
	cout << "Found: " << foundIndex << endl;
	cout << "Result: ";
	for (int i=0; i < static_cast<int>(list.size()); i++)
	{
		cout << list.at(i) << " ";
	}
	cout << endl;
	return 0;
}

int search(vector<int> &v, int number)
{
	for(int i=0; i < static_cast<int>(v.size()); i++)
	{
		if(v.at(i) == number)
		{
			return i;
		}
	}
	return -1;
}


void remove(vector<int> &v, int index)
{
	v.erase (v.begin() + index);
}

