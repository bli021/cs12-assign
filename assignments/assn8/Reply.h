#ifndef __REPLY_H__
#define __REPLY_H__

#include <iostream>
#include "Message.h"

using namespace std;

class Reply: public Message
{
    //no new member variables
    public:
        //default constructor
        Reply();

        /* Parameterized constructor - similar to Message's constructor
        except:
        The subject should be initialized to "Re: <sbjct>" not <sbjct>.
        */
        Reply(const string &athr,
                const string &sbjct,
                const string &bdy,
                unsigned id)
            : Message(athr,sbjct,bdy,id){}

        virtual bool is_reply() const {return true;} // Returns true

        /* to_formatted_string writes the contents of the Reply to a string
        in the following format:

        <begin_reply>
        :id: 4
        :subject: single line
        :from: author
        :children: 5 6 [this line should not be printed if there are no children.]
        :body: multiple lines
        2nd line
        <end>

        * the line starting with :children: has the list of id's of all children
        * (See file specs for details)
        */
        virtual string to_formatted_string() const;
};
#endif

// The given file structure:
/*
//inclusion guards
  //includes
*
  class Reply : public Message
  {
   // no new member variables

   public:
     //default constructor
     Reply();

     * Parameterized constructor - similar to Message's constructor except:
      * The subject should be initialized to "Re: <sbjct>" not <sbjct>.
      *
     Reply(const string &athr, 
           const string &sbjct, 
           const string &body, 
           unsigned id);
     
     virtual bool is_reply() const; // Returns true
     
     * to_formatted_string writes the contents of the Reply to a string in the 
      * following format:
        
       <begin_reply>
       :id: 4
       :subject: single line
       :from: author
       :children: 5 6 [this line should not be printed if there are no children.]
       :body: multiple lines
       2nd line
       <end>

      * the line starting with :children: has the list of id's of all children 
* (See file specs. for details)
      *
     virtual string to_formatted_string() const; // New !!
       
  };

  //end inc guards
  */