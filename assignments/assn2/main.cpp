//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment1/part1.cpp 
/// @brief Assignment 1 Part 1 for CS 12 Winter 2014
///
/// @author David Anderson [dande011@ucr.edu]
/// @date <1/22/2014>
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
#include <fstream>
#include <cstdlib>

using namespace std;


void outGrid(const double grid[][8]);


int main()
{
	double grid[6][8] =
	{
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
	};
	string inFile, outFile;
	cout << "Enter the input filename: ";
	cin >> inFile;
	cout << endl;
	cout << "Enter the output filename: ";
	cin >> outFile;
	cout << endl;

	/// <TESTING> ///
	// inFile = "input.txt";
	// outFile = "output.txt";

	/// </TESTING>

	ifstream input;
	double top, right, bottom, left, tolerance;
	double delta=1.0;

	input.open(inFile.c_str());

	if(!input.is_open())
	{
		cout << "Error: cannot open " << inFile;
		exit(0);
	}

	input >> top >> right >> bottom >> left >> tolerance;


	// cout << "Top:\t" << top << endl;
	// cout << "Right:\t" << right << endl;
	// cout << "Bottom:\t" << bottom << endl;
	// cout << "Left:\t" << left << endl;
	// cout << "Tolerance:\t" << tolerance << endl;

	for(int i=0; i<6; i++)
	{
		grid[i][0] = left;
		grid[i][7] = right;
	}
	for(int i=0; i<8; i++)
	{
		grid[0][i] = top;
		grid[5][i] = bottom;
	}

	double old=0.0;
	do
	{
		for(int i=1; i<5; i++)
			for(int j=1; j<7; j++)
			{
				old=grid[i][j];
				grid[i][j] = (grid[i+1][j]+grid[i-1][j]+grid[i][j+1]+grid[i][j-1])/4;
				delta = grid[i][j] - old;
				// cout << "Delta:\t" << delta << endl;
				// outGrid(grid);
			}
	}while(delta > tolerance);

	// cout << "Delta:\t" << delta << endl;
	// outGrid(grid);
	ofstream output;
	output.open (outFile.c_str());

	if(!output.is_open())
	{
		cout << "Error: cannot open " << outFile;
		exit(0);
	}
	for(int i=1; i<5; i++)
	{
		for(int j=1; j<7; j++)
			output << grid[i][j] << ' ';
		output << endl;
	}
	outGrid(grid);
	return 0;
}

void outGrid(const double grid[][8])
{
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<8; j++)
			cout << grid[i][j] << '\t';
		cout << endl;
	}
}