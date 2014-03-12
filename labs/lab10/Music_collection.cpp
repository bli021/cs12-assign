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
#ifndef __MUSIC_COLLECTION_CPP__
#define __MUSIC_COLLECTION_CPP__
#include "Music_collection.h"

Music_collection::Music_collection( const Music_collection &m )
{
	number = m.number;
	max = m.max;
	collection = new Tune[m.max];
	for(int i=0; i<m.number; i++)
		collection[i] = m.collection[i];
}

bool Music_collection::add_tune( const Tune &t )
{
	if(number==max)
		return false;
	number++;
	collection[number-1] = t;
	return true;
}

bool Music_collection::set_tune( int index, const Tune &t )
{
	if(index>=number)
		return false;
	collection[index] = t;
	return true;
}


Music_collection & Music_collection::operator=( const Music_collection &m )
{
	//if(m.number>max)
	//{
		delete[] collection;
		collection = new Tune[m.max];
	//}
	number = m.number;
	max = m.max;
	for(int i=0; i<m.number; i++)
		collection[i] = m.collection[i];
	return *this;
}

ostream & operator<<(ostream &out, const Music_collection &m)
{
	for(int i=0; i<m.number; i++)
		out << m.collection[i].get_title() << '\n';
	return out;
}
#endif
