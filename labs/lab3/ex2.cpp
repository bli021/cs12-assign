//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab3/ex2.cpp 
/// @brief Lab 3 ex2 for CS 12 Winter 2014
///
/// @author David Anderson [dande011@ucr.edu]
/// @date 1/19/2014
///
/// @par Enrollment Rotes 
///     Lecture Section: 001
/// @par
///     Lab Section: 021
/// @par
///     TA: Nkenge Wheatland
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ERTIRELY my own original work.
//  =============== END ASSESSMERT HEADER ==================
#include <iostream>
#define Q 2
#define R 3
#define S 3

using namespace std;

const int MAX = max(R, S);

void matrixMult(const int a[][R], const int b[][S], int product[][S]);
void matrixInp( int a[][R], int x, int y );
void matrixOut( int a[][R], int x, int y );

int main()
{
    int a[Q][R];
    int b[R][S];
    int sum[Q][S];

    //Input the matrices
    matrixInp( a, Q, R );
    matrixInp( b, R, S );
    cout << endl;

    //Test output
    cout << "Test:" << endl;
    matrixOut( a, Q, R );
    matrixOut( b, R, S );

    //Multiply the matrixes
    matrixMult( a, b, sum );

    //Output the new matrix
    cout << "Res:" << endl;
    matrixOut( sum, Q, S );

    return 0;
}

void matrixMult(const int a[][R], const int b[][S], int product[][S])
{
    for(int i = 0; i < Q; i++)
        for(int j = 0; j < R; j++)
            for(int k = 0; k < S; k++)
                product[i][j] += a[i][k] * b[k][j];
}


void matrixInp( int a[][R], int x, int y )
{
    cout << "Enter Matrix (size " << x << 'x' << y << ')';
    for( int i = 0; i < x; i++ )
        for( int j = 0; j < y; j++)
            cin >> a[i][j];
}

void matrixOut( int a[][R], int x, int y )
{
    for( int i = 0; i < x; i++ )
    {
        for( int j = 0; j < y; j++)
            cout << a[i][j] << '\t';
        cout << endl;
    }
    cout << endl;
}