#include "binaryTree.h"
#include <iostream>

/****************************************/
/*******Constructors/Deconstructor*******/
/****************************************/

binaryTree::binaryTree() {  
    int key_value = NULL;
    node *left = NULL;
    node *right = NULL;
    m_root = NULL;
}

binaryTree::~binaryTree() {
}
/****************************************/
/****************Functions***************/
/****************************************/

void binaryTree::destroy_tree(node* leaf) {
    if (leaf != NULL) {
        destroy_tree(leaf->m_left);
        destroy_tree(leaf->m_right);
        delete leaf;
    }
}

void binaryTree::insert(int key, node* leaf) {
    if (key < leaf->m_keyValue) {
        if (leaf->m_left != NULL)
            insert(key, leaf->m_left);
        else {
            leaf->m_left = new node;
            leaf->m_left->m_keyValue = key;
            leaf->m_left->m_left = NULL;    //Sets the left child of the child node to NULL
            leaf->m_left->m_right = NULL;   //Sets the right child of the child node to NULL
        }
    }
    else if (key >= leaf->m_keyValue) {
        if (leaf->m_right != NULL)
            insert(key, leaf->m_right);
        else {
            leaf->m_right = new node;
            leaf->m_right->m_keyValue = key;
            leaf->m_right->m_left = NULL;  //Sets the left child of the child node to  NULL
            leaf->m_right->m_right = NULL; //Sets the right child of the child node to NULL
        }
    }
}

binaryTree::node * binaryTree::search(int key, node* leaf) {

    if (leaf != NULL) {

        if (key == leaf->m_keyValue)
            return leaf;
        if (key<leaf->m_keyValue)
            return search(key, leaf->m_left);
        else
            return search(key, leaf->m_right);
    }
    else return NULL;
}


void binaryTree::insert(int key) {

    if (m_root != NULL)
        insert(key, m_root);
    else {
        m_root = new node;
        m_root->m_keyValue = key;
        m_root->m_left = NULL;
        m_root->m_right = NULL;
    }
}

binaryTree::node * binaryTree::search(int key) {
    return search(key, m_root);
}

void binaryTree::destroy_tree() {
    destroy_tree(m_root);
}

