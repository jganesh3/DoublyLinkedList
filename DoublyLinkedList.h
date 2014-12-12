/*
*	Author  : Ganesh Vijay Joshi
*	Subjecy : CSCI 311 
*			  Assignment Number 1
*   Date	: 02/07/2013
*	Version : 1.0.0
*/

#include <iostream>
#include <string>
using namespace std;

class data
{
	string music;             
	
    public:
    void add(string &x);
	string* getdata();
	string chkData();
};




class DoublyLinkedList
{


public:

	class node
       {
         public: 
	     data* obj;
	     node* next;
	     node* back;
		 node()
		 {
			obj=NULL;
			next=NULL;
			back=NULL;
		 }
		 ~node()
		 {

		 }

       };

		DoublyLinkedList()
		{
			head=NULL;
			tail=NULL;
			current=NULL;
		}
		~DoublyLinkedList()
		{
		
		}
		bool empty();
		void append(string  &s);
		void insertBefore(string& s);
		void insertAfter(string& s);
		void remove(string &s);
		void begin();
		void end();
		bool next();
		bool prev();
		bool find (string& s);
		const string& getData();

private:
	node* head;
	node* tail;
	node* current;

		
};
