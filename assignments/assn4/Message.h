//inclusion guards
#include <iostream>
  class Message
  {
    private:
      std::string author;
      std::string subject;
      std::string body;

    public:
      //default constructor
      Message();

      //Constructor with parameters
      Message(const std::string &athr, 
              const std::string &sbjct, 
              const std::string &body);


      //displays the message in the given format. See output specs.
      void display() const;
  };
  //end inc guards