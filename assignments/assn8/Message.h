#ifndef MESSAGE_H
#define MESSAGE_H

//inclusion guards
#include <iostream>
using namespace std;
  class Message
  {
    private:
      string author;
      string subject;
      string body;

    public:
      //default constructor
      Message() : author(), subject(), body(){}

      //Constructor with parameters
      Message(const string &athr, 
              const string &sbjct, 
              const string &bdy)
        : author(athr), subject(sbjct), body(bdy){}


      //displays the message in the given format. See output specs.
      void display() const;
  };
  //end inc guards
  #endif
  