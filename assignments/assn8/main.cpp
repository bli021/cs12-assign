#include <iostream>

#include "BBoard.h"
#include "Message.h"
#include "User.h"

using namespace std;


int main(int argc, char **argv)
{
    // check commandline arguments 
    // (see Zyante Chapter 7, section 7.7 for explanations and examples)   
    if (argc != 3){
        cout << "ERROR: Invalid program call." << endl
            << "Usage: <program_name> userfile datafile" << endl;
        return 1;
    }
    string userfile(argv[1]);
    string datafile(argv[2]);
   
    BBoard bb("CS12 Bulletin Board");
   
    // load users from file
    if (!bb.load_users(userfile))
    {
        cout << "ERROR: Cannot load users from " << userfile << endl;
        return 1;
    }
   
    // load messages   
    if (!bb.load_messages(datafile))
    {
        cout << "ERROR: Cannot load messages from " << datafile << endl;
        return 1;
    }
   
    bb.login();
    bb.run();

    // save messages
    if (!bb.save_messages(datafile))
    {
        cout << "ERROR: Cannot save messages to " << datafile << endl;
        return 1;
    }

    return 0;
} 






// int main(int argc, char* argv[])
// {
//     // char name[256], age[256];
//     // cout << "name: ";
//     // cin.getline(name,256);
//     // cout << "age: ";
//     // cin.getline(age,256);
//     // cout << endl << name << age << endl;

    
//     cout << endl << endl;
//     // cout << "HERE" << endl;
//     int num=argc;
//     // cout << "HEHRERE" << endl;
//     num++;
//     // cout << "SDFGHJK" << endl;
//     string infile = argv[1];
//     // cout << "QWERT" << endl;

//     // cout << "Got to the beginning!" << endl;
//     // cout << "about to create a BBoard" << endl;
//     BBoard thing( "My Title" );
//     // cout << "setup" << endl;
//     // cout << "infile: " << infile << endl;
//     thing.load_users(infile);
//     // cout << "login" << endl;
//     thing.login();
//     // cout << "run" << endl;
//     thing.run();
//     // cout << "Got to the end!!!" << endl;
//     return 1;
// }