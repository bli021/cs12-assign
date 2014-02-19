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

//todo
void BBoard::login()
{
    string temp1, temp2;
    // bool validUser = false;
    // bool validPass = false;
    cout << "Welcome to " << title << endl;
    cout << "Enter your username ('Q' or 'q' to quit): ";
    cin >> temp1;
    if((temp1 == "q") || (temp1 == "Q"))
        quit();
    cout << "\nEnter your password: ";
    cin >> temp2;





}

//todo
void BBoard::run()
{

}

//--- PRIVATE ---

//todo
void BBoard::add_user(istream &infile, cons string &name, const string &pass)
{

}

//todo
bool user_exists(const string &name, const strin &pass)
{

}
//todo
User get_User(const string &name) const
{

}

//todo
void BBoard::display() const
{

}
 //todo
void add_message()
{
    
}
void BBoard::error(int errlvl)
{
    switch (errlvl)
    {
        case 3:
            cout << "I/O error. Check that the filename" 
                << " is correct and accessible" << endl;
            break;
    }
    exit(1);
}