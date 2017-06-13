#include "binaryTree.h"
#include <iostream>

/****************************************/
/*******Constructors/Deconstructor*******/
/****************************************/

binaryTree::binaryTree() {  
    int key_value = NULL;
    node *left = NULL;
    node *right = NULL;
    root = NULL;
}

binaryTree::~binaryTree() {
}
/****************************************/
/****************Functions***************/
/****************************************/

void binaryTree::destroy_tree(node* leaf) {
    if (leaf != NULL) {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void binaryTree::insert(int key, node* leaf) {
    if (key < leaf->key_value) {
        if (leaf->left != NULL)
            insert(key, leaf->left);
        else {
            leaf->left = new node;
            leaf->left->key_value = key;
            leaf->left->left = NULL;    //Sets the left child of the child node to NULL
            leaf->left->right = NULL;   //Sets the right child of the child node to NULL
        }
    }
    else if (key >= leaf->key_value) {
        if (leaf->right != NULL)
            insert(key, leaf->right);
        else {
            leaf->right = new node;
            leaf->right->key_value = key;
            leaf->right->left = NULL;  //Sets the left child of the child node to  NULL
            leaf->right->right = NULL; //Sets the right child of the child node to NULL
        }
    }
}

binaryTree::node * binaryTree::search(int key, node* leaf) {

    if (leaf != NULL) {

        if (key == leaf->key_value)
            return leaf;
        if (key<leaf->key_value)
            return search(key, leaf->left);
        else
            return search(key, leaf->right);
    }
    else return NULL;
}


void binaryTree::insert(int key) {

    if (root != NULL)
        insert(key, root);
    else {
        root = new node;
        root->key_value = key;
        root->left = NULL;
        root->right = NULL;
    }
}

binaryTree::node * binaryTree::search(int key) {
    return search(key, root);
}

void binaryTree::destroy_tree() {
    destroy_tree(root);
}

