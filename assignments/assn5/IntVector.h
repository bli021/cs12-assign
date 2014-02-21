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
#ifndef _INTVECTOR_H_
#define _INTVECTOR_H_

class IntVector
{
    private:
        unsigned sz;
        unsigned cap;
        int* data;
        void expand();
        void expand( unsigned amount );

    public:
        IntVector():sz(0),cap(0),data(0){};
        IntVector(unsigned size);
        IntVector(unsigned size, int value);
        ~IntVector(){delete data;};
        unsigned size() const{return sz;};
        unsigned capacity() const{return cap;};
        bool empty() const{return !sz;};
        const int & at( unsigned index ) const{return at(index);};
        int & at( unsigned index );
        void insert( unsigned index, int value );
        //todo
        void erase( unsigned index );
        //todo
        const int & front() const{return front();};
        //todo
        int & front(){return data[0];};
        //todo
        const int &back() const{return back();};
        //todo
        int & back(){return data[sz];};
        //todo
        void assign( unsigned n, int value );
        //todo
        void push_back( int value );
        //todo
        void pop_back();
        //todo
        void clear();
        //todo
        void resize( unsigned size, int value );
        //todo
        void reserve( unsigned n );
        
};

#endif //INTVECTOR