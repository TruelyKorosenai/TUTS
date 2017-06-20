#include <iostream>

#include "List.h"
/****************************************/
/*******Constructors/Deconstructor*******/
/****************************************/
List::List (){
	m_head = NULL;
	m_curr = NULL;
	m_temp = NULL;
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

	if (m_head != NULL){
		m_curr = m_head;
        while (m_curr->next != NULL) {
            m_curr = m_curr->next;
        }
        m_curr->next = n;
	}
    else {
        m_head = n;
    }
}

void List::DeleteNode (int delData){
    nodePtr delPtr = NULL;
    m_temp = m_head;
    m_curr = m_head;
    
    while (m_curr != NULL && m_curr->data != delData) {
        m_temp = m_curr;
        m_curr = m_curr->next;
    }
    if (m_curr == NULL) {
        
        std::cout << delData << " was not found " << std::endl;
    }
    else {
        delPtr = m_curr;
        m_curr = m_curr->next;
        m_temp->next = m_curr;
        if (delPtr == m_head) {
            m_head = m_head->next;
            m_temp = NULL;

        }
        delete delPtr;
        std::cout << "The value " << delData << " was deleted" << std::endl;
    }
}

void List::PrintList (){
    m_curr = m_head;
    while (m_curr != NULL) {
        std::cout << m_curr->data << std::endl;
        m_curr = m_curr->next;

    }
    
}


