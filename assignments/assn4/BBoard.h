#include <iostream>
#include <cstdlib>

class BBoard()
{
    private:
        string title;
        vector<User> user_list;
        User current_user;
        vector<Message> message_list;
        void add_uer(istream &infile, const strin &name, const string &pass);
        bool user_exists(const string &name, const string &pass) const;
        User get_user(const string &name) const;
        void display() const;
        void add_message();
        
        void quit(){std::cout << "Bye!" << endl; exit(0);};
        void error(int);
    public:
        BBoard() : current_user("default"), title("Default title"), user_list(), message_list();
        BBoard(const string &ttl) : current_user("default"), title(ttl), user_list(), message_list();
        void setup(const string &input_file);
        void login();
        void run();



};