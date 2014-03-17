//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assignment1/main.cpp 
/// @brief Assignment 2 for CS 12 Winter 2014
///
/// @author David Anderson [dande011@ucr.edu]
/// @date <2/19/2014>
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 021
/// @par
///     TA: Nkenge Wheatland
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  =============== END ASSESSMENT HEADER ==================
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
        void display(vector<vector<int> > a) const;
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
