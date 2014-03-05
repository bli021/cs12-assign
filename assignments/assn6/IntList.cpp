#include <iostream>

#include "IntList.h"

using namespace std;

void IntList::display() const
{
    //for( IntNode *cur= head; cur != 0; cur = cur->next)
	//	cout << ( ((cur==tail)||(cur!=head))?' ':'\0') << cur->data;
		
		
    for( IntNode *cur= head; cur != 0; cur = cur->next)
    {
		if( (cur!=head) )
			cout << ' ';
		cout << cur->data;
	}
}

void IntList::push_front(int value)
{
    IntNode *temp = new IntNode(value);
    if(head==0)
		tail = temp;
    temp->next = head;
    head = temp;
}

void IntList::push_back( int value )
{
    IntNode *temp = new IntNode(value);
    if(head==0)
        head = temp;
    else
        tail->next = temp;
    tail = temp;
    temp->next = 0;
}

void IntList::pop_front()
{
    if(head == 0) return;
    IntNode *temp = head;
    head = head->next;
    delete temp;
}

//todo
void IntList::select_sort()
{
    IntNode *min = head;
    for(IntNode *i = head; i->next != 0; i = i->next)
    {
        for(IntNode *j = i->next; j->next != 0; j = j->next)
        {
            if(j->data < min->data)
                min = j;
        }
        swap(i->data,min->data);
    }
}

void IntList::insert_sorted( int value )
{
    IntNode *temp = new IntNode( value );
    IntNode *prev = head;
    if( (head==0) || (value <= head->data) )
    {
        push_front(value);
        return;
    }
    else if(value >= tail->data)
    {
        push_back(value);
        return;
    }
    IntNode *cur;
    for(cur = head; cur != tail; cur = cur->next)
    {
        if(cur->data >= value)
        {
            prev->next = temp;
            temp->next = cur;
            return;
        }
        prev = cur;
    }

    if(value < tail->data)
    {
        prev->next = temp;
        temp->next = cur;
        return;
    }

    // cout << "Error in insert_sorted" << endl;
}

//todo
void IntList::remove_duplicates()
{

}
