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
#ifndef __MUSIC_COLLECTION_H__
#define __MUSIC_COLLECTION_H__
#include <iostream>
using namespace std;

class Tune
{
  private:
   string title;

  public:
   Tune():title(){}
   Tune( const string &n ):title(n){}  
   const string & get_title() const{return title;}
};

class Music_collection
{
 private: 
   int number; // the number of tunes actually in the collection 
   int max;    // the number of tunes the collection will ever be able to hold 
   Tune *collection; // a dynamic array of Tunes: "Music_collection has-many Tunes"

 public:
   // default value of max is a conservative 100
   Music_collection():number(0),max(100),collection(new Tune[max]){}     

   // sets max to n
   Music_collection( int n ):number(0),max(n),collection(new Tune[max]){} 

   // overloaded copy constructor
   Music_collection( const Music_collection &m);

   // returns true if add was successful, 
   // returns false if not enough room to add
   bool add_tune( const Tune &t );

   // sets the Tune at position index in collection to t, 
   // returns true if index < number    
   bool set_tune( int index, const Tune &t );

   // overloaded assignment operator
   Music_collection & operator=( const Music_collection &m );

   // Destructor
   ~Music_collection(){delete[] collection;}
 
  // overloaded stream insertion operator
  // outputs the title of each Tune in the collection on a separate line
  friend ostream & operator<<( ostream &out, const Music_collection &m ); 
};
#endif
