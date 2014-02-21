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

#include "IntVector.cpp"

using namespace std;

void printValues(IntVector data)
{
    cout << "All values of vector of size " << data.size() << endl;
    for(int i=0; i < data.size(); i++)
        cout << "data.at(" << i << "):\t" << data.at(i) << endl;
    cout << endl;
}

void printStats(IntVector data)
{
    cout << "data.size():\t"        << data.size() << endl;
    cout << "data.capacity():\t"    << data.capacity() << endl;
    cout << "data.empty():\t"       << data.empty() << endl;
    cout << endl;
}

int main()
{
    IntVector data(3,2);

    printValues(data);
    printValues(data);
    // printStats(data);


// /* AT */
//     cout << "data.at(2) = 4;"       << endl;
//     data.at(2) = 4;
//     cout << "data.at(2):\t"         << data.at(2) << endl;

//     cout << endl;

// /* INSERT */
//     cout << "data.insert(2,7)" << endl;
//     data.insert(2,7);
//     cout << "data.at(2):\t"         << data.at(2) << endl;

//     cout << endl;

// /* ERASE */
//     cout << "data.at(2):\t"         << data.at(2) << endl;
//     cout << "data.at(3):\t"         << data.at(3) << endl;
//     cout << "data.erase(2);" << endl;
//     data.erase(2);
//     cout << "data.at(2):\t"         << data.at(2) << endl;

//     cout << endl;

// /* FRONT */
//     cout << "data.at(0):\t"            << data.at(0) << endl;
//     cout << "data.front():\t"          << data.front() << endl;
//     cout << "data.front() = 7;" << endl;
//     data.front() = 7;
//     cout << "data.at(0):\t"            << data.at(0) << endl;

//     cout << endl;

// /* BACK */
//     cout << "data.at(size()-1):\t"        << data.at(data.size()-1) << endl;
//     cout << "data.back():\t"            << data.back() <<endl;
//     cout << "data.back() = 7;" << endl;
//     data.back() = 7;
//     cout << "data.back():\t"            << data.back() << endl;

//     cout << endl;

// /* ASSIGN */
//     printValues(data);
//     cout << "data.assign(5,6);" << endl;
//     data.assign(5,6);
//     printValues(data);

// /* PUSH_BACK */ 
//     printStats(data);
//     printValues(data);
//     cout << "data.push_back(5);" << endl;
//     data.push_back(5);
//     printStats(data);
//     printValues(data);


// /* POP_BACK */
// /* CLEAR */
// /* RESIZE */
// /* RESERVE */



    cout << endl;
    return 0;
}