// #include <iostream>
#include <fstream>

#include "BBoard.h"
#include "User.h"
#include "Message.h"

using namespace std;

//--- PUBLIC ---
void BBoard::setup(const string &input_file)
{
    cout << "Welcome to " << title << endl;
    // cout << endl << "Function: setup" << endl;
    // cout << "infile" << endl;
    ifstream infile;
    // cout << "input_file: " << input_file << endl;
    infile.open(input_file.c_str());
    if(!infile.is_open())
        error(3);
    int i=0;
    // cout << "while loop" << endl;
    while(infile.good())
    {
        // cout << "declare strings" << endl;
        string a,b;
        // cout << "getline a" << endl;
        // getline(infile, a, '\t'); // this might have been giving me errors on galah
        infile >> a;
        // cout << "a: " << a << endl;
        // cout << "getline b" << endl;
        // getline(infile, b);
        infile >> b;
        // cout << "b: " << b << endl;
        // cout << ".at(" << i << ')' << endl;
        user_list.push_back(User(a,b));
        // cout << "i++" << endl;
        i++;
        // cout << "looping" << endl;
    }
    // cout << "finished loop and function" << endl;
}

void BBoard::login()
{
    string temp1, temp2;
    bool done=false;
    while(!done)
    {
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> temp1;
        if((temp1 == "q") || (temp1 == "Q"))
            quit();
        cout << "Enter your password: ";
        cin >> temp2;
        if (user_exists(temp1, temp2))
        {
            delete current_user;
            current_user = new User(temp1,temp2);
            done = true;
        }
        else
        {
           cout << "Invalid Username or Password!" << endl << endl; 
        }
    }


}


void BBoard::run()
{
    char temp;
    bool done = false;
    cout << "Welcome back " << current_user->get_username() << '!' << endl;
    cout << endl;
    while(!done)
    {
        cout << "Menu" << endl;
        cout << " - Display Messages ('D' or 'd')" << endl
                << " - Add New Message ('N' or 'n')" << endl
                << " - Quit ('Q' or 'q')" << endl;
        cout << "Choose an action: ";
        cin >> temp;
        if(temp=='Q' || temp=='q')
            exit(0);
        else if(temp=='D' || temp=='d')
            display();
        else if(temp=='N' || temp=='n')
            add_message();
    }
}

//--- PRIVATE ---

//todo
bool BBoard::user_exists(const string &name, const string &pass) const
{
    // cout << "Entered: " << name << '\t' << pass << endl;
    for(unsigned i=0; i<user_list.size();i++)
    {
        // cout << user_list.at(i).get_username() << endl;
        if(user_list.at(i).check(name,pass))
            return true;
    }
    return false;
}

//todo
void BBoard::display() const
{
    string dashes="-----------------------------------------------";
    if(message_list.size()==0)
        cout << endl << "Nothing to display." << endl << endl;
    else
    {
        for(unsigned i=0; i<message_list.size();i++)
        {
            cout << dashes << endl;
            cout << "Message #" << i << ": ";
            message_list.at(i).display();
        }

        cout << dashes << endl;
    }
}

 //todo
void BBoard::add_message()
{
    char name[256], age[256];
    cout << "Subject: ";
    cin.getline(name,256);
    cin.getline(name,256);
    cout << "Body: ";
    cin.getline(age,256);
    message_list.push_back(Message(current_user->get_username(), name, age));
    cout << "Message Recorded!" << endl << endl;
}


void BBoard::error(int errlvl)
{
    switch (errlvl)
    {
        case 1:
            cout << "Bye!" << endl;
            break;
        case 2:
            cout << "User not logged in" << endl;
            break;
        case 3:
            cout << "I/O error. Check that the filename" 
                << " is correct and accessible" << endl;
            break;
    }
    exit(0);
}