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

    public:
        IntVector():sz(0),cap(0),data(0){};
        IntVector(unsigned size);
        IntVector(unsigned size, int value);
        unsigned size() const{return sz;};
        unsigned capacity() const{return cap;};
        bool empty() const{return !sz;};
        const int & at( unsigned index ) const;
};

#endif //INTVECTOR