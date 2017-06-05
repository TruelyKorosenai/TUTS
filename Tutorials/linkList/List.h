#pragma once

/****************************************/
/*           Linked List Class.

Allowing easy creation of Lists and nodes in the list*/
/****************************************/
class List{


private: 
	typedef struct node{
		int data;
		node* next;
	}*nodePtr;

	nodePtr head;
	nodePtr curr;
	nodePtr temp;

public:
	void AddNode (int addData);    // Function That add new data to the node
	void DeleteNode (int delData); // Function That deletes the data in the node
	void PrintList (); // Function That Prints the Full List to screen


	List ();
	virtual ~List ();

};

