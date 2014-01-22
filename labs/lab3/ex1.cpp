//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab3/ex1.cpp 
/// @brief Lab 3 ex1 for CS 12 Winter 2014
///
/// @author David Anderson [dande011@ucr.edu]
/// @date 1/19/2014
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
#define M 2
#define N 3

using namespace std;

void matrixAdd( const int a[][N], const int b[][N], int sum[][N] );
void matrixInp( int a[][N] );
void matrixOut( int a[][N] );

int main()
{
    int a[M][N];
    int b[M][N];
    int sum[M][N];

    //Input the matrices
    matrixInp( a );
    matrixInp( b );
    cout << endl;

    //Test output
    // cout << "Test:" << endl;
    // matrixOut( a );
    // matrixOut( b );

    //Add the matrixes
    matrixAdd( a, b, sum );

    //Output the new matrix
    cout << "Res:" << endl;
    matrixOut( sum );

    return 0;
}


void matrixAdd( const int a[][N], const int b[][N], int sum[][N] )
{
    for( int i = 0; i < M; i++ )
        for( int j = 0; j < N; j++)
            sum[i][j] = a[i][j] + b[i][j];
}

void matrixInp( int a[][N] )
{
    cout << "Enter Matrix (size " << N << 'x' << M << ')';
    for( int i = 0; i < M; i++ )
        for( int j = 0; j < N; j++)
            cin >> a[i][j];
}

void matrixOut( int a[][N] )
{
    for( int i = 0; i < M; i++ )
    {
        for( int j = 0; j < N; j++)
            cout << a[i][j] << '\t';
        cout << endl;
    }
    cout << endl;
}