#pragma once

/****************************************/
/*           Linked List Class.

Allowing easy creation of Lists and nodes in the list*/
/****************************************/
class List{


private: 
    /* Node Struct 
    - Holds to value and points to the next*/
	typedef struct node{
		int data;
		node* next;
	}*nodePtr;

	nodePtr m_head;
	nodePtr m_curr;
	nodePtr m_temp;

public:
    /*---- Add Item ----
    @param (data) - (int)
    @return (void) - (null)*/
	void AddNode (int addData);    

    /*---- Delete Node----
    Deletes a node from the list
    @Param (data) - (int)
    @return (void) - (Null)*/
	void DeleteNode (int delData);
   
    /*---- Print List ----
    @return (void) - (NULL)*/
	void PrintList ();

	/*---- Search List ----
	@return (bool) - (int)*/
	bool SearchList(int data);


	List ();
	virtual ~List ();

};

