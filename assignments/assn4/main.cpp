#include <iostream>

#include "BBoard.h"
#include "Message.h"
#include "User.h"

using namespace std;

int main(/*int argc, char* argv[]*/)
{
    BBoard thing( "My Title" );
    thing.setup(infile);
    thing.login();
    thing.run();
    return 1;
}