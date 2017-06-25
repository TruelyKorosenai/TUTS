#pragma once
#include "MitchellsExceptionalExceptions\tkException.h"
#include <iostream>

class BinaryTree{
public:
    BinaryTree();
    ~BinaryTree();

    /* ---- Add Leaf ----
    Public: 
    Calls the private addleaf function.
    @param (key) - (int)
    @return (void) - (NULL)*/
    void AddLeaf(int key);

    /* ---- Print In Order ----
    Public: 
    Calls the private Print in Order function.
    @param - (Null)
    @return (void) - (NULL)*/
    void PrintInOrder();

    /* ---- RETURN ROOT KEY ----
    Public:
    Returns the roots key value
    @param - (Null)
    @return (int) - (Throw exception or return key value)*/
    int ReturnRootKey();

    /* ---- Get Return Node ----
    Public:
    Calls the Return Node private 1 function.
    @param  (key) - (int) 
    @return (void) - NULL*/
    void GetReturnNode(int key);

    /* ---- Print Children ----
    Public:
    Prints inserted key and its children.
    @param - (Null)
    @return (void) - (NULL)*/
    void PrintChildren(int key);

    /* ---- Find Smallest ----
    Public: 
    Calls the private Find Smallest function.
    @param - (Null)
    @return (int) - (findsmallestprivate)*/
    int FindSmallest();

    /* ---- Remove Node ----
        Public: 
    Calls the private Find Smallest function.
    Removes a node from the tree
    @param (int) - (key)
    @return (void) - (Null)*/
    void RemoveNode(int key);

//*********************************************************************************************************************
//********************************************PRIVATE******************************************************************
//*********************************************************************************************************************
private:
    struct node{
        int key;
        node* left;
        node* right;
    };
    /* node*, referencing the trees root*/
    node* root; 

    /* ---- Create Leaf ----
    Creates a leaf node
    @param (int) - (key)
    @return (node*)*/
    node* CreateLeaf(int key);

    /* ---- Add Leaf Private ----
    Places the leaf in the correct position 
    @param (int) - (key), (node*) - (Ptr) 
    @return (void) - (NULL)*/
    void AddLeafPrivate(int key, node* Ptr);

    /* ---- Print In Order ----
    Prints list in order
    @param - (Null)
    @return (void) - (NULL)*/
    void PrintInOrderPrivate(node* Ptr);

    /* ---- Return Node ----
    returns a node* referencing the key value
    @param (int) - (key)
    @return (node*)*/
    node* ReturnNodePrivate1(int key);

    /* ---- Return Node Private ----
    returns a node* referencing the key value
    @param (int) - (key), (node*) - (Ptr)
    @return (node*)*/
    node* ReturnNodePrivate2(int key, node* Ptr);
    
    /* ---- Find Smallest Private ----
    Finding the smallest value from the root
    @param (node*) - (Ptr)
    @return (int) - (findsmallestprivate)*/
    int FindSmallestPrivate(node* Ptr);

    /* ---- Remove Node Private ----
    Deletes a node from the tree
    @param (int) - (key), (node*) - (parent).
    @void - (Null)*/
    void RemoveNodePrivate(int key, node* parent);

    /* ---- Remove Root Match ----
    Deletes the root node
    @param - (Null)
    @void - (Null)*/
    void RemoveRootMatch();

    /* --
    -- Remove Match ----
   Removes a Match  node.
   @param - (node*) parent, (node*) match, (bool) left:
   match: will be the one we want to delete.
   parent: will be the parent of the one we want to delete
   left: will indicate the relationship between the matching node and his parent,
   true = left, false = right.
   @void - Null*/
    void RemoveMatch(node* parent, node* match, bool left); 

/* ---- Remove Subtree ----
    Removes a node and its chidlren 
    @param - (node*) - (Ptr)
    @void - (Null)*/
    void RemoveSubtree(node* Ptr);
};