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

void IntList::pop_front()
{
    if(head == 0) return;
    IntNode *temp = head;
    head = head->next;
    delete temp;
}
