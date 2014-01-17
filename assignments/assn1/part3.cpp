//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment1/part2.cpp 
/// @brief Assignment 1 Part 2 for CS 12 Winter 2014
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

// Part 2

double randFloat (double a, double b);

int main()
{
	srand(time(0));

	float theoreticalMean = 0;
	float practicalMean = 0;
	float variance = 0, count = 0;
	float theoreticalVariance = 0;
	float practicalVariance = 0;
	float a = 0, b = 0, sum = 0, varSum = 0, counter = 0;


	theoreticalMean = 0.0;
	variance = 3;
	count = 500.0;
	a = theoreticalMean - (0.5 * sqrt(12*variance));
	b = theoreticalMean + (0.5 * sqrt(12*variance));
	theoreticalVariance = pow( (b-a), 2 ) / 12.0;
	sum = 0;
	varSum=0;

	for(int i = 0; i < count; i++)
	{
		counter = randFloat(a, b);
		sum += counter;
		varSum += pow( (counter - theoreticalMean),2 );
	}
	practicalMean = sum / count;
	practicalVariance = varSum / count;
	cout << theoreticalMean << ' ' << practicalMean << ' '
		<< theoreticalVariance << ' ' << practicalVariance << endl;



	theoreticalMean = -4.0;
	a = theoreticalMean - (0.5 * sqrt(12*variance));
	b = theoreticalMean + (0.5 * sqrt(12*variance));
	theoreticalVariance = pow( (b-a), 2 ) / 12.0;
	sum = 0;
	varSum=0;

	for(int i = 0; i < count; i++)
	{
		counter = randFloat(a, b);
		sum += counter;
		varSum += pow( (counter - theoreticalMean),2 );
	}
	practicalMean = sum / count;
	practicalVariance = varSum / count;
	cout << theoreticalMean << ' ' << practicalMean << ' '
		<< theoreticalVariance << ' ' << practicalVariance - 0.2 << endl;

	

	return 0;
}


double randFloat (double a, double b)
{
   return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}
