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
        const User *current_user;
        vector<Message*> message_list;
        // void add_user(istream &infile, const string &name, const string &pass);
        bool user_exists(const string &name, const string &pass) const;
        // User get_user(const string &name) const;
        void display() const;
        // void add_message(); //vitrified
        void add_topic();
        void add_reply();
        
        void quit(){cout << "Bye!" << endl; exit(0);};
        void error(int);
        void test();
    public:
        BBoard() : title("Default Title"), user_list(0), current_user(new User("","")), message_list(){}
        BBoard(const string &ttl) : title(ttl), user_list(0), current_user(new User("","")), message_list(){}
        ~BBoard();
        // void setup(const string &input_file); //vitrified
        bool load_users(const string &userfile);
        bool load_messages(const string& datafile);
        bool save_messages(const string& datafile);

        void login();
        void run();



};
#endif
