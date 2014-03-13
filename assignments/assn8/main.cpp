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
    // cout << "HERE" << endl;
    int num=argc;
    // cout << "HEHRERE" << endl;
    num++;
    // cout << "SDFGHJK" << endl;
    string infile = argv[1];
    // cout << "QWERT" << endl;

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