// #include <iostream>
#include <fstream>

#include "BBoard.h"
#include "User.h"
#include "Message.h"

using namespace std;

//--- PUBLIC ---
BBoard::~BBoard()
{
    for(unsigned i=0; i<message_list.size();i++)
        delete message_list.at(i);
}


// void BBoard::setup(const string &input_file)
// {
//     cout << "Welcome to " << title << endl;
//     // cout << endl << "Function: setup" << endl;
//     // cout << "infile" << endl;
//     ifstream infile;
//     // cout << "input_file: " << input_file << endl;
//     infile.open(input_file.c_str());
//     if(!infile.is_open())
//         error(3);
//     int i=0;
//     // cout << "while loop" << endl;
//     while(infile.good())
//     {
//         // cout << "declare strings" << endl;
//         string a,b;
//         // cout << "getline a" << endl;
//         // getline(infile, a, '\t'); // this might have been giving me errors on galah
//         infile >> a;
//         // cout << "a: " << a << endl;
//         // cout << "getline b" << endl;
//         // getline(infile, b);
//         infile >> b;
//         // cout << "b: " << b << endl;
//         // cout << ".at(" << i << ')' << endl;
//         user_list.push_back(User(a,b));
//         // cout << "i++" << endl;
//         i++;
//         // cout << "looping" << endl;
//     }
//     // cout << "finished loop and function" << endl;
// }


bool BBoard::load_users(const string &userfile)
{
    cout << "Welcome to " << title << endl;
    // cout << endl << "Function: setup" << endl;
    // cout << "infile" << endl;
    ifstream infile;
    // cout << "userfile: " << userfile << endl;
    infile.open(userfile.c_str());
    if(!infile.is_open())
        return false;
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
    return true;
}

bool BBoard::load_messages(const string& datafile)
{
    ifstream data;
    data.open(datafile.c_str());
    if(!data.is_open())
        return false;
    for(int i=0; data.good(); i++)
    {
        string a,b;
        data >> a >> b;
        //todo
    }
    return true;
}

bool BBoard::save_messages(const string& datafile)
{
    ofstream data;
    data.open(datafile.c_str());
    if(!data.is_open())
        return false;
    for(unsigned i=0; i<message_list.size();i++)
    {
        data << message_list.at(i);
    }
    return true;
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
        {
            cout << "Bye!" << endl;
            return;
        }
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
    if(current_user->get_username()=="")
        return;
    char temp;
    bool done = false;
    cout << "Welcome back " << current_user->get_username() << '!' << endl;
    cout << endl;
    while(!done)
    {
        cout << "Menu" << endl;
        cout << " - Display Messages ('D' or 'd')" << endl
                << " - Add New Topic ('N' or 'n')" << endl
                << " - Add Reply ('R' or 'r')" << endl
                << " - Quit ('Q' or 'q')" << endl;
        cout << "Choose an action: ";
        cin >> temp;
        if(temp=='Q' || temp=='q')
            return;
        else if(temp=='D' || temp=='d')
            display();
        else if(temp=='N' || temp=='n')
            add_topic();
        else if(temp=='R' || temp=='r')
            add_reply();
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
            message_list.at(i)->print();
        }

        cout << dashes << endl;
    }
}


// void BBoard::add_message()   //vitrified
// {
//     char name[256], age[256];
//     cout << "Subject: ";
//     cin.getline(name,256);
//     cin.getline(name,256);
//     cout << "Body: ";
//     cin.getline(age,256);
//     message_list.push_back(new Message(current_user->get_username(), name, age));
//     cout << "Message Recorded!" << endl << endl;
// }


void BBoard::add_topic()
{
    char subject[256], curr, prev;
    string body;
    cout << "Subject: ";
    cin.getline(subject,256);
    cin.getline(subject,256);
    while(curr!='\n' && prev!='\n')
    {
        prev = curr;
        cin >> curr;
        body+=curr;
    }

}


void BBoard::add_reply()
{
    bool done=false;
    int id;
    string title;
    while(!done)
    {
        cout << "Enter Message ID: ";
        cin >> id;
        if(id<0)
            return;
        else if(id>static_cast<int>(message_list.size()))
            cout << "too big" << endl;
        else
        {
            //find the title of the original post
            title = "Re: " + title;
            //cin body
            //create a new reply and push pointer to message_list
        }
    }

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