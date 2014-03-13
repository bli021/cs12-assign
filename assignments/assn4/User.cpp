#include <iostream>

#include "User.h"

using namespace std;

bool User::check(const string &uname, const string &pass) const
{
    // cout << "User::check: " << uname << '\t' << pass << endl;
    return (username!="") && (username==uname) && (password==pass);
}