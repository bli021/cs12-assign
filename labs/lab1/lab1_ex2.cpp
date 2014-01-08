//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab1/lab1_ex2.cpp 
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
#include <cmath>
using namespace std;

// given the coordinates of a point (x,y) computes if the point is inside the circle 
// centered at origin with radius R. Returns 'true' if it is inside, 'false' otherwise.
bool is_inside(float x, float y, float R)
{
	return sqrt(pow(y,2) + pow(x,2)) <= R/2;
}

// given the side,s, of a square that is centered at origin, 
// chooses a random coordinates inside the square, and calls is_inside function 
// to test if the point is inside the circle or not.
bool throw_dart(int s)
{
	int x, y;
    // assign x and y to two random numbers between -s/2 and s/2
    x = rand()%s - s/2;
    y = rand()%s - s/2;
    //cout << x << " " << y << endl;
    // see the previous exercise to see an example. 
    //Call the is_inside function and return its output. 
    //You do not have to cast x,y to floats, it is done automatically.
    return is_inside(x, y, s);
}
   
int main()
{
	srand(time(0));
	int side = 1000; // this is the side of the square and is also our resolution. 
    int tries;  // this is the number of tries.
    float pi;

    //Ask the user for the number of tries using cout.
    cout << "Enter number of tries: ";
    //Get the users input using cin.
    cin >> tries;
    cout << endl;


    int in_count = 0; //counter to track number of throws that fall inside

	for(int i = 0; i < tries; i++)
    {
		//throw a dart using throw_dart method and increment the counter depending on its output.
		if(throw_dart(side))
			in_count++;
		//cout << "in_count: " << in_count << endl;
	}

	//Compute and display the estimated value of PI. Make sure you are not doing integer division.
	pi = 4 * static_cast<float>(in_count) / tries;
	cout << "pi: " << pi << endl;


	return 0;
}
