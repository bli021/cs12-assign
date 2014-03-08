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
#include <fstream>

using namespace std;

int gcd(int a, int b)
{
	int x, y, r, sx, sy, sr;
	x = a;
	sx = 1;
	y = b;
	sy = 0;
	while(y != 0)
	{
		r = x % y;
		sr = sx - sy*(x - r)/y;
		x = y;
		sx = sy;
		y = r;
		sy = sr;
	}
	return x;
	// if(a > b)
	// {
	// 	if(a % b == 0)
	// 		return b;
	// 	else
	// 	{
	// 		a = a % b;
	// 		gcd(a, b);
	// 	}
	// }
	// else
	// {
	// 	if(b % a == 0)
	// 		return a;
	// 	else
	// 	{
	// 		b = b % a;
	// 		gcd(a, b);
	// 	}
	// }
	// return 0;
}

bool diophantine(int a, int b, int c, int &x, int &y)
{
	if(a==0 && b==0)
		return false;
	else if(!(gcd(a,b) % c == 0))
		return false;
	else if(b % a == 0)
	{
		cout << "b % a == 0" << endl;
		x = 0;
		y = c/b;
		return true;
	}
	else
	{
		cout << "default case" << endl;
		int q = ( a / b );
		int r = ( a % b );
		int u = q*x + y;
		int v = x;
		while(diophantine(b, r, c, u, v));
		x = v;
		y = u-q*x;
		return true;
	}
	return false;
}

int main()
{
	// string infile, outfile;
	// cout << "Enter name of input file: ";
	// cin >> infile;
	// cout << "Enter name of output file: ";
	// cin >> outfile;
	
	// ifstream in;
	// in.open(infile.c_str());
	// if(!in.is_open())
	// {
	// 	cout << "Error: input file not valid. Quitting" << endl;
	// 	return 0;
	// }
	// ofstream out;
	// out.open(outfile.c_str());
	// if(!out.is_open())
	// {
	// 	cout << "Error: output file not valid. Quitting" << endl;
	// 	return 0;
	// }
	
	// while(!in.eof())
	{
		int a, b, c, x, y;
		cin >> a >> b >> c;
		if(diophantine(a, b, c, x, y))
			cout << "No solution!" << endl;
		else
		{
			cout << a << "x + " << b << "y = " << c << endl;
			cout << "x = " << x << endl;
			cout << "y = " << y << endl;
		}
	}
	return 0;
}
