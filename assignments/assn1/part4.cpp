//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment1/part4.cpp 
/// @brief Assignment 1 Part 4 for CS 12 Winter 2014
///
/// @author David Anderson [dande011@ucr.edu]
/// @date <1/16/2014>
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
#include <cmath>
#include <ctime>

using namespace std;

// Part 4

double rand_mv(double mean, double var);
double randFloat (double a, double b);

int main()
{
	srand(time(0));

	float mean, var;

	cout << "Mean: ";
	cin >> mean;

	cout << "Var: ";
	cin >> var;

	
	// mean = 4;
	// var = 2;

	cout << endl;

	rand_mv(mean, var);


	

	return 0;
}


double rand_mv(double mean, double var)
{
	float count = 500.0;
	float a = mean - (0.5 * sqrt(12*var));
	float b = mean + (0.5 * sqrt(12*var));
	cout << a << ' ' << b << endl;
	float theoreticalVariance = pow( (b-a), 2 ) / 12.0;
	float sum = 0;
	float varSum=0;

	for(int i = 0; i < count; i++)
	{
		float data = randFloat(a, b);
		sum += data;
		varSum += pow( (data - mean),2 );
	}
	float practicalMean = sum / count;
	float practicalVariance = varSum / count;
	// cout << mean << ' ' << practicalMean << ' '
	// 	<< theoreticalVariance << ' ' << practicalVariance << endl;
	return 0;
}


double randFloat (double a, double b)
{
   return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}
