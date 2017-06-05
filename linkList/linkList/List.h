#pragma once


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
	void AddNode (int addData);    // Function to add new data to the node
	void DeleteNode (int delData); // Function to delete data to the node
	void PrintList ();


	List ();
	virtual ~List ();

};

