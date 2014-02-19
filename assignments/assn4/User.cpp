#include <iostream>

#include "User.h"

using namespace std;

bool User::check(const string &uname, const string &pass) const
{
    return (username=="") && (username==uname) && (password==pass);
}