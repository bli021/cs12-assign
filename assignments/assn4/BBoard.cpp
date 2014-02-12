#include <iostream>
#include <fstream>

#include "BBoard.h"

using namespace std;

//--- PUBLIC ---
void BBoard::setup(const string &input_file)
{
    ifstream infile;
    infile.open(input_file.c_str());
    if(!infile.is_open())
        error(3);
    int i=0;
    while(infile.good())
    {
        string a,b;
        getline(infile, a, '\t');
        getline(infile, b);
        user_list.at(i) = User(a,b);
        i++;
    }
}
void BBoard::login()
{
    cout << "Enter your username ('Q' or 'q' to quit): ";
    
}

//--- PRIVATE ---
void BBoard::error(int errlvl)
{
    switch (errlvl)
    {
        case 3:
            cout << "I/O error. Check that the filename is correct and accessible" << endl;
            break;
    }
    exit(1);
}