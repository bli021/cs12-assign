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
#ifndef MESSAGE_H
#define MESSAGE_H

//inclusion guards
#include <iostream>
#include <vector>
using namespace std;
  class Message
  {
    protected:
      string author;
      string subject;
      string body;
      unsigned id;
      // This will be the size of the message_list vector to which the
      // newly constructed Message* is being pushed_back
      vector<Message*> child_list;
      //This is how a Message is able to keep track of its Replies

    public:
      //default constructor
      Message() : author(), subject(), body(), id(0){}

      //Constructor with parameters
      Message(const string &athr, 
              const string &sbjct, 
              const string &bdy,
              const unsigned num)
        : author(athr), subject(sbjct), body(bdy), id(num){}

      //Be careful here: some Messages will have two pointers to
      //them, stored in very different places!
      // where are they, and who should be responsible for deleting them?
      virtual ~Message();

      //Returns true if the object is a Reply.
      virtual bool is_reply() const = 0;

      virtual string to_formatted_string() const = 0;
      /* This function is responsible for printing the Message 
      * (whether Topic or Reply), and and all of the Message's 
      * "subtree" recursively:
      * After printing the Message with indentation n and appropriate 
      * format (see output details), it will invoke itself 
      * recursively on all of the Replies in its child_list,
      * incrementing the indentation value at each new level.
      *
      * Note: Each indentation increment represents 2 spaces. e.g. if 
      * indentation == 1, the reply should be indented 2 spaces, if 
      * it's 2, indent by 4 spaces, etc.
      */
      void print(unsigned indentation) const;

      //returns the subject string
      const string & get_subject() const {return subject;}

      // returns the id
      unsigned get_id() const {return id;}

      //Adds a pointer to the child to the parent's child_list
      void add_child(Message *child);

      //displays the message in the given format. See output specs.
      // void display() const; //vitrified
  };
//end inc guards
#endif
