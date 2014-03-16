#ifndef BBOARD_H
#define BBOARD_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

#include "User.h"
#include "Message.h"

using namespace std;

class BBoard
{
    private:
        string title;
        vector<User> user_list;
        User *current_user;
        vector<Message *> message_list;
        // void add_user(istream &infile, const string &name, const string &pass);
        bool user_exists(const string &name, const string &pass) const;
        // User get_user(const string &name) const;
        void display() const;
        void add_message();
        
        void test(){}
        
        void quit(){cout << "Bye!" << endl; exit(0);};
        void error(int);
    public:
        BBoard() : title("Default Title"), user_list(), current_user(new User("default","")), message_list(){}
        BBoard(const string &ttl) : title(ttl), user_list(), current_user(new User("default","")), message_list(){}
        void setup(const string &input_file);
        void login();
        void run();



};
#endif
