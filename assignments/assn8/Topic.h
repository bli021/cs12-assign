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
#ifndef __TOPIC_H__
#define __TOPIC_H__

#include <iostream>
#include "Message.h"

using namespace std;

class Topic: public Message
{
    // no new member variables
    public:
        //default constructor
        Topic();

        //Parameterized constructor
        Topic(const string &athr,
                const string &sbjct,
                const string &bdy,
                unsigned id)
            : Message(athr,sbjct,bdy,id){}

        virtual bool is_reply() const {return false;} //returns false

        /* to_formatted_string writes the contents of the Topic to a
        string in the following format:

        <begin_topic>
        :id: 4
        :subject: single line
        :from: author
        :children: 5 6 [this line should not be printed if there are no children.]
        :body: multiple lines - line 1
        line 2
        line 3
        <end>

        * line starting with :children: has the id's of all children (See file specs.
        for details)
        */
        
        virtual string to_formatted_string() const;
};
#endif