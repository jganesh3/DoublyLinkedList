/*
*	Author  : Ganesh Vijay Joshi
*	Subjecy : CSCI 311 
*			  Assignment Number 1
*   Date	: 02/07/2013
*	Version : 1.0.0
*   File    : DoublyLinkedList.cpp
*/
#include <iostream>
#include "DoublyLinkedList.h"
#include <string>

void data::add(string &x)
{   string *data=&x;
	music=*data;
}

string* data::getdata()
{
	return &music;
}

string data::chkData()
{
	return music;
}


/*@brief : This Function will append new node to current node*/
void DoublyLinkedList::append(string &s)
{	
	
	//Skip if user enters Blank spaces 
	if((s=="appendSong")|| s[0]=='\0')
	 return;
	if(empty())
	{
		data * x;
		x=new(data);
		x->add(s);
		current=new(node);
		current->next=NULL;
		current->back=NULL;
		current->obj=x;
		head=current;
		tail=current;
	}
	else
	{	data *x;
		node *newnode;
		current=head;
		while(current->next!=NULL)    //Traversing to last node to append
		{
			current=current->next;

		}	x=new(data);
		    x->add(s);
			newnode=new(node);
			newnode->next=NULL;
			newnode->back=current;
			current->next=newnode;
			newnode->obj=x;
			tail=newnode;
			current=newnode;
		


	}
}

 
/*@brief : This Function will check whether link list is empty or note.*/
bool DoublyLinkedList::empty()
{
	if (head==NULL)
		return 1;
	else 
		return 0;


}
/*@brief : This Function will move current to the end*/
void DoublyLinkedList::end()
{
	current=tail;
}


/*@brief : This Function will use to access data node*/
const string& DoublyLinkedList::getData()
{	
	string *p;
	p=current->obj->getdata();
	return *p;
	
}

/*@brief : This Function will compair pass data to node data */
bool DoublyLinkedList::find(string& s)
{   
	node *temp=head;
	int x;
	bool y=0;
	
	while(temp->next=NULL)
	{
		x=s.compare(temp->obj->chkData());
		if(!x)
		{current=temp;y=1;}
		else
			temp=temp->next;
	}
	
	return y;
	
}
/*@brief : This Function will move current pointer to first location*/
void DoublyLinkedList::begin()
{
	current=head;
	
}
/*@brief : This Function will insert node before song*/

void DoublyLinkedList::insertBefore(string &s)
{
		node *tempnode=current; 
		node *newnode;
		node *temp;
		if (head==NULL)  //Return if header is NULL
			return;
		if(s=="insertBefore" || s[0]=='\0')    // Return if the string is empty
			return;
		if(tempnode->back==NULL)
			{
			data * x;
			x=new(data);
			x->add(s);
			newnode=new(node);
			newnode->next=head;
			newnode->back=NULL;
			newnode->obj=x;
			head=newnode;
			current=newnode;
			}
			else
			{
			
			data * x;
			x=new(data);
			x->add(s);
			newnode=new(node);
			temp=current->back;
			newnode->next=current;
			newnode->back=temp;
			temp->next=newnode;
			current->back=newnode;
			newnode->obj=x;
			current=newnode;
			}
	
}

/*@brief : This Function will inset new song after*/
void DoublyLinkedList::insertAfter(string &s)
{
			node *tempnode=current; 
			node *newnode;
			node *temp;
     		if(head==NULL)
				return;
			if(s=="insertAfter" || s[0]=='\0')
				return;
			if(tempnode->next==NULL)
			{
			data * x;
			x=new(data);
			x->add(s);
			newnode=new(node);
			newnode->next=NULL;
			newnode->back=current;
			tempnode->next=newnode;
			newnode->obj=x;
			tail=newnode;
			current=newnode;
			}
			else
			{
			data * x;
			x=new(data);
			x->add(s);
			newnode=new(node);
			temp=current->next;
			temp->back=newnode;
			current->next=newnode;
			newnode->back=current;
			newnode->next=temp;
			newnode->obj=x;
			current=newnode;
			}

	
}
/*@brief : This Function will increments curret position*/
bool DoublyLinkedList::next()
{

	if(current->next!=NULL)
	{current=current->next; return 1;}
	else
		return 0;
}

/*@brief : This Function will decrement current position*/
bool DoublyLinkedList::prev()
{
	if(current->back!=NULL)
	{current=current->back;
	return 1;}
	else
		return 0;
	
}

/*@brief : This Function will remove perticular node from list*/
void DoublyLinkedList::remove(std::string &s)
{
	node *tempnode,*tempbox;
	tempnode=head;
	while(tempnode!=NULL)
	{
		if(!(tempnode->obj->chkData().compare(s)))
		{
			if(tempnode->back==NULL && tempnode->next==NULL) 	//Removing Single Node
			{
				delete (tempnode);
				head=NULL;
				current=NULL;
				tail=NULL;
				break;
			}
			if(tempnode->back == NULL)  			//Check if it is Head node
			{
				tempbox=tempnode;
				tempnode=tempnode->next;
				tempnode->back=NULL;
				head=tempnode;
				delete(tempbox);
					current=tempnode;
					break;
			}
			if(tempnode->next==NULL)               //Check if it is Tail Node
			{
				tempbox=tempnode;
				tempnode=tempnode->back;
				tempnode->next=NULL;
				tail=tempnode;
				delete(tempbox);
					current=tempnode;
					break;
			}
			if (tempnode->next !=NULL && tempnode->back !=NULL)   //Deleting Middle Node;
			{
				tempbox=tempnode;
				tempnode=tempnode->back;
				tempnode->next=tempbox->next;
				tempbox->next->back=tempnode;
				delete(tempbox);
				current=tempnode->next;
			}
			
		}

			tempnode=tempnode->next;
      }

}