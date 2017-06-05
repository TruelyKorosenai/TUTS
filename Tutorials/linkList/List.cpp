#include <iostream>

#include "List.h"
/****************************************/
/*******Constructors/Deconstructor*******/
/****************************************/
List::List (){
	head = NULL;
	curr = NULL;
	temp = NULL;
}

List::~List (){
}
/****************************************/
/****************Functions***************/
/****************************************/

// Function called when adding a new node
void List::AddNode (int addData){
	nodePtr n = new node;
	n->next = NULL;
	n->data = addData;

	if (head != NULL){
		curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = n;
	}
    else {
        head = n;
    }
}

void List::DeleteNode (int delData){
    nodePtr delPtr = NULL;
    temp = head;
    curr = head;
    
    while (curr != NULL && curr->data != delData) {
        temp = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        
        std::cout << delData << " was not found " << std::endl;
    }
    else {
        delPtr = curr;
        curr = curr->next;
        temp->next = curr;
        if (delPtr == head) {
            head = head->next;
            temp = NULL;

        }
        delete delPtr;
        std::cout << "The value " << delData << " was deleted" << std::endl;
    }
}

void List::PrintList (){
    curr = head;
    while (curr != NULL) {
        std::cout << curr->data << std::endl;
        curr = curr->next;

    }
    
}


