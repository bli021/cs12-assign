// #include <iostream>
#include <fstream>
#include <string>

#include "BBoard.h"
#include "User.h"
#include "Message.h"
#include "Reply.h"
#include "Topic.h"

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
        bool isReply;
        string subject, author, body, current, field, text;
        unsigned numMsgs, id, children=-1, startPos;
        data >> numMsgs;
        for(unsigned i=0; i <= numMsgs; i++)
        {
            vector<int> children;
            unsigned done=0;
            while(done<5)
            {
                getline(data,current);
                if(current.find(":") != string::npos)
                {
                    startPos = current.find(":",current.find(":"));
                    text = current.substr(startPos);
                    field = current.substr(current.find(":"),startPos);
                    isReply = (field.find("Re") != string::npos);
                    cout << "Field: " << field << endl;
                    if(field=="id")
                        id = atoi(field.c_str());
                    else if(field=="subject")
                        subject = field;
                    else if(field=="from")
                        author = field;
                    else if(field=="children")
                        children.push_back(atoi(field.c_str()));
                    else if(field=="body")
                        body = field;
                    done++;
                }
                else if(current.find("<end>") != string::npos)
                    done = 5;
                else
                    body += "\n" + current;
                // if(current.find(":id:") != npos)
                //     id = current.substr(current.find(":",current.find(":")+1));
            }
            if(isReply)
                message_list.push_back(new Reply(author, subject, body, id));
            else
                message_list.push_back(new Topic(author, subject, body, id));
            for(int y=0; y < children.size(); y++)
                message_list.at(i).add_child(children.at(y)); 
    
        }
        for(unsigned x=0; x < children.size(); x++ )
            message_list.at(children.at(i)).add_child(message_list);
        /*
        <begin_topic>
        :id: 1
        :subject: 2
        :from: 3
        :children: 4
        :body: 5
        <end>
        */
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
        else if(temp=='T' || temp=='t')
            test();
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
            if(message_list.at(i)->is_reply())

            cout << dashes << endl;
            message_list.at(i)->print(0);
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
    string subject, prev=" ";
    string body, curr;
    cout << "Subject: ";
    getline(cin,subject);
    getline(cin,subject);
    cout << "Body: ";
    getline(cin,curr);
    body += curr + "\n";
    while(prev!="" && curr!="")
    {
        prev = curr;
        getline(cin,curr);
        body += curr + "\n";
        // cout << "<prev>" << prev << "</prev>";
        // cout << "<curr>" << curr << "</curr>"; 
    }
    // cout << "::" << body << "::" << endl;
    body.at(body.size()-1) = '\0';
    body.at(body.size()-2) = '\0';
    // cout << "::" << body << "::" << endl;
    // cout << "Finished body: " << endl << body;
    message_list.push_back(new Topic(current_user->get_username(), subject, body, message_list.size()));
}


void BBoard::add_reply()
{
    bool done=false;
    unsigned id;
    string title, body, curr, prev;
    while(!done)
    {
        cout << "Enter Message ID: ";
        cin >> id;
        id--;
        if(id >= message_list.size())
            cout << "ID is too big." << endl;
        else
        {
            title = message_list.at(id)->get_subject();
            title = "Re: " + title;
            cout << "Body: ";
            getline(cin,curr);
            body += curr + "\n";
            while(prev!="" && curr!="")
            {
                prev = curr;
                getline(cin,curr);
                body += curr + "\n";
                // cout << "<prev>" << prev << "</prev>";
                // cout << "<curr>" << curr << "</curr>"; 
            }
            // body.pop_back();
            // cout << "::" << body << "::" << endl;
            body.at(body.size()-1) = '\0';
            body.at(body.size()-2) = '\0';
            // cout << "::" << body << "::" << endl;
            message_list.push_back(new Reply(current_user->get_username(), title, body, message_list.size()));
            //create a new reply and push pointer to message_list
            cout << "Message recorded!" << endl;
            done = true;
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

void BBoard::test()
{
    bool parts[5] = {false, false, false, false, false};
    cout << parts;
}
