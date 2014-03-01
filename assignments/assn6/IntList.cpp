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
    
}

//todo
void IntList::insert_sorted()
{

}

//todo
void IntList::remove_duplicates()
{

}
