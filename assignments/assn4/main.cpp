#include <iostream>

#include "BBoard.h"
#include "Message.h"
#include "User.h"

using namespace std;

int main(int argc, char* argv[])
{
    // char name[256], age[256];
    // cout << "name: ";
    // cin.getline(name,256);
    // cout << "age: ";
    // cin.getline(age,256);
    // cout << endl << name << age << endl;

    
    cout << endl << endl;
    int num=argc;
    num++;
    string infile=argv[1];

    // cout << "Got to the beginning!" << endl;
    // cout << "about to create a BBoard" << endl;
    BBoard thing( "My Title" );
    // cout << "setup" << endl;
    // cout << "infile: " << infile << endl;
    thing.setup(infile);
    // cout << "login" << endl;
    thing.login();
    // cout << "run" << endl;
    thing.run();
    // cout << "Got to the end!!!" << endl;
    return 1;
}