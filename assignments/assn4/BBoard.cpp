#include <iostream>
#include <fstream>

#include "BBoard.h"

using namespace std;

//--- PUBLIC ---\\
void BBoard::setup(const string &input_file)
{
    ifstream infile;
    infile.open(input_file);
    if(!infile.is_open())
        error(3);
    int i=0;
    while(infile.good())
    {
        user_list.at(i) = infile.getline();
        i++;
    }
}
void BBoard::login()
{
    cout << "Enter your username ('Q' or 'q' to quit): ";
    
}

//--- PRIVATE ---\\
void BBoard::error(int &errlvl)
{
    switch (errlvl)
    {
        case 3:
            cout << "I/O error. Check that the filename is correct and accessible" << endl;
            break;
    }
    exit(1);
}