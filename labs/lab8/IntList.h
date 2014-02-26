

struct IntNode
{
    int data;
    IntNode *next;
    IntNode( int data ) : data(data), next(0) {}
};


class IntList
{
    private:
        IntNode * head;
        IntNode * tail;
    public:
        IntList() : head(0), tail(0) {}
        ~IntList(){while(head!=0) pop_front();}
        void display() const;
        void push_front( int value );
        void pop_front();
};
