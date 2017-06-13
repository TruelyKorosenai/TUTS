#pragma once
/****************************************/
/*        Binary Tree Class.

Allowing easy creation of Binary Trees */
/****************************************/
class binaryTree {

private:
    struct node {
        int key_value;
        node *left;
        node *right;
    };

    void destroy_tree(node *leaf);// function that deletes nodes
    void insert(int key, node *leaf); // function that creates a new node at the correct position in the tree
    node *search(int key, node *leaf); // function that searches the tree until it finds a uninitialized node, or the searched value

    node *root; // root of the tree

public:
    

    binaryTree();
    ~binaryTree();

    void insert(int key); // function that alocates memory and instantiates to NULL
    node *search(int key);
    void destroy_tree(); // function that deletes the entire tree


};

