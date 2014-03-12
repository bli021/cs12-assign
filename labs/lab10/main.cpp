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
#include "Music_collection.h"
int main()
{
	cout << "HERE?" << endl;
	//create a few Tune objects to use later on;
	Tune tune1("one");
	Tune tune2("two");
	Tune tune3("three");
	Tune tune4("a-b-c");
	Tune tune5("baby, you and me now");
	Tune tune6("easy as");
	Tune tune7("1, 2, 3");
	Tune tune8("do, re, mi");
	Tune tune9("simeple as");
	
	cout << "here?" << endl;
	Music_collection A;
	//add a few tunes to A;
	A.add_tune(tune4);
	cout << "here2" << endl;
	Music_collection B(A); 
	cout << "here3" << endl; 
	//change a Tune in B using set_tune function;
	B.add_tune(tune7);
	B.set_tune(0, tune6);
	Music_collection C;
	C = B; 
	//add a Tune to B; 
	B.set_tune(1,tune8);
	//change a Tune in C using set_tune function;
	C.set_tune(0, tune5);
	
	//print A,B,C; 
	cout << A << endl;
	cout << B << endl;
	cout << C << endl;
	cout << "LAST" << endl;
}
