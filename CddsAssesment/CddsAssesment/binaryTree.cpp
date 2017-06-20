#include "BinaryTree.h"

    //----Constructor----
    BinaryTree::BinaryTree(){
        root = nullptr;
    }
    
//-------------------------------------------------------------------------------------------------------------------------------
    //----Deconstructor----
    BinaryTree::~BinaryTree(){
        RemoveSubtree(root);
    }

//-------------------------------------------------------------------------------------------------------------------------------
    //----AddLeaf----
    void BinaryTree::AddLeaf(int key){
        AddLeafPrivate(key, root);
    }

//-------------------------------------------------------------------------------------------------------------------------------
    //----PRINT IN ORDER----
    void  BinaryTree::PrintInOrder(){
            PrintInOrderPrivate(root);
    }

//-------------------------------------------------------------------------------------------------------------------------------
    //----RETURN ROOT KEY----
    
    int BinaryTree::ReturnRootKey(){
        if (root != nullptr){
            return root->key;
        }
        else{ 
            TK_EXCEPTION("the root key is equal to NullPtr");
        }
    }

//-------------------------------------------------------------------------------------------------------------------------------
    //----GET RETURN NODE----
    void BinaryTree::GetReturnNode(int key){
        ReturnNodePrivate1(key);
    }

    //-------------------------------------------------------------------------------------------------------------------------------
    //----PRINT CHILDREN----
    void BinaryTree::PrintChildren(int key){
        // Point to the return value of the return node function
        node* Ptr = ReturnNodePrivate1(key); 

        if (Ptr != nullptr){
            std::cout << "Parent Node = " << Ptr->key << "\n";

            //---LEFT CHILD---// 
            Ptr->left == NULL ?
            std::cout << "Left Child = NullPtr\n"://True print child
            std::cout << "Left Child = " << Ptr->left->key << "\n";//False print null

            //---RIGHT CHILD---//
            Ptr->right == NULL ? //true or false value,
            std::cout << "right Child = NullPtr\n" : //True print child
            std::cout << "right Child = " << Ptr->right->key << "\n";//False print null
        }
        else{
            TK_EXCEPTION("The key is not in the list");
        }
    }
        
//-------------------------------------------------------------------------------------------------------------------------------
    //----FindSmallest----
    int BinaryTree::FindSmallest(){
       return FindSmallestPrivate(root);
    }

//-------------------------------------------------------------------------------------------------------------------------------
    //----REMOVE NODE----
    void BinaryTree::RemoveNode(int key){
        RemoveNodePrivate(key, root); 
    }

//-------------------------------------------------------------------------------------------------------------------------------
    //----CreateLeaf----
    BinaryTree::node * BinaryTree::CreateLeaf(int key){
        node* n = new node;
        n->key = key;
        n->left = nullptr;
        n->right = nullptr;
        return n;
    }
    
//-------------------------------------------------------------------------------------------------------------------------------
    //----AddLeafPrivate----
    void BinaryTree::AddLeafPrivate(int key, node * Ptr){
     
        if (root == NULL){
            root = CreateLeaf(key);
        }

        // value < root
        else if (key < Ptr->key){

            // if value found, continue left until null
            if (Ptr->left != nullptr){ 
                AddLeafPrivate(key, Ptr->left);
            }
            //if null, create leaf
            else{
                Ptr->left = CreateLeaf(key);
            }
        }

        // value > root
        else if (key > Ptr->key){

            if (Ptr->right != nullptr){
                AddLeafPrivate(key, Ptr->right);
            }

            else{
                Ptr->right = CreateLeaf(key);
            }
        }
        //duplicate value.
        else{
            TK_EXCEPTION("The Key you entered has already been added to the tree");
        }
    }

//-------------------------------------------------------------------------------------------------------------------------------
    //----PRINT IN ORDER PRIVATE----
    void BinaryTree::PrintInOrderPrivate(node * Ptr){

        if (root != nullptr){

            //Can go left?
            if (Ptr->left != nullptr){ 
                //if True
                PrintInOrderPrivate(Ptr->left);
            }
            //print key
            std::cout << Ptr->key << " "; 

            //Can go Right?
            if (Ptr->right != nullptr){ 
                PrintInOrderPrivate(Ptr->right);
            }
        }

        else{
            std::cout << "The tree is empty\n";
        }
    }

//-------------------------------------------------------------------------------------------------------------------------------
    //----RETURN NODE PRIVATE 1----
    BinaryTree::node * BinaryTree::ReturnNodePrivate1(int key){
        return ReturnNodePrivate2(key, root);
    }

//-------------------------------------------------------------------------------------------------------------------------------
    //----RETURN NODE PRIVATE 2----
    BinaryTree::node * BinaryTree::ReturnNodePrivate2(int key, node * Ptr){
        if (Ptr != nullptr){

            if (Ptr->key == key){
                return Ptr; 
            }
            else{

                if (key < Ptr->key){
                    // value < key
                    return ReturnNodePrivate2(key, Ptr->left);
                    
                }
                else{
                    // value > key
                    return ReturnNodePrivate2(key, Ptr->right);
                }
            }
        }
        else{
            return nullptr;
        }
    }
    
//-------------------------------------------------------------------------------------------------------------------------------
    //----Find Smallest Private----
    int BinaryTree::FindSmallestPrivate(node * Ptr){

        if (root == nullptr){
            std::cout << "Empty, Create a tree";
            TK_EXCEPTION("Empty, Create a tree");        }
        
        else{

            if (Ptr->left != nullptr){
                //std::cout << "\n CLICK\n"; //test time required.
                return FindSmallestPrivate(Ptr->left);
            }
            //Smallest value found
            else {
                return Ptr->key;
            }
        }
    }
    
//-------------------------------------------------------------------------------------------------------------------------------
    //----REMOVE NODE PRIVATE----
    void BinaryTree::RemoveNodePrivate(int key, node * parent)
    {
        if (root != nullptr){
            // is key present?
            if (root->key == key){
                 RemoveRootMatch();
            }
            //if found
            else{

                // if value < left child. 
                if (key < parent->key && parent->left != nullptr){
                   parent->left->key == key ? 
                  
                  /*if true*/
                  RemoveMatch(parent, parent->left, true): 
                  /*if false*/
                  RemoveNodePrivate(key, parent->left);
                }

                // if value > right child.
                else if (key > parent->key && parent->right != nullptr){
                    parent->right->key == key ? 
                        /*if true*/
                        RemoveMatch(parent, parent->right, false) :
                        /*if false*/
                        RemoveNodePrivate(key, parent->right);

                }
                //if key not found
                else{
                    TK_EXCEPTION("This node does not exist");
                }
            }
        }
        //if tree is empty
        else{
            TK_EXCEPTION("The Tree is empty");
        }
    }

//-------------------------------------------------------------------------------------------------------------------------------
    //----REMOVE ROOT MATCH----
    void BinaryTree::RemoveRootMatch(){
        
        if (root != nullptr){
            node* delPtr = root;
            int rootKey = root->key;
            int smallestInRightSubtree;

            //if 0 children
            if (root->left == nullptr && root->right == nullptr){
                root = nullptr;
                delete delPtr;
            }

            //if 1 child - RIGHT
            else if (root->left == nullptr && root->right != nullptr){
                root = root->right;
                delPtr->right = nullptr;
                delete delPtr;
                std::cout << "The root node with key " << rootKey << " was deleted\n";
                std::cout << "The new root contains the key " << root->key << "\n";
            }

            //if 1 child - LEFT
            else if (root->left != nullptr && root->right == nullptr){
                root = root->left;
                delPtr->left = nullptr;
                delete delPtr;
                std::cout << "The root node with key " << rootKey << " was deleted\n";
                std::cout << "The new root contains the key " << root->key << "\n";
            }

            //if 2 children
            else{
                smallestInRightSubtree = FindSmallestPrivate(root->right); 
                RemoveNodePrivate(smallestInRightSubtree, root); 
                root->key = smallestInRightSubtree;
                std::cout << "The root key containing the key " << rootKey << " was overwritten with the key " << root->right << "\n";
            }
        }
        else{
            TK_EXCEPTION("Tree is empty");
        }
    }

//-------------------------------------------------------------------------------------------------------------------------------
    
    //----REMOVE MATCH----

    void BinaryTree::RemoveMatch(node * parent, node * match, bool left){
        if (root != nullptr){
            node * delPtr;
            int matchKey = match->key; 
            int smallestInRightSubtree;

            //if 0 children
            if (match->left == nullptr && match->right == nullptr){
                delPtr = match; 
                left == true ? parent->left = nullptr : parent->right = nullptr;
                delete delPtr;
                std::cout << "The node containing the key " << matchKey << " was removed\n";
            }
            //if 1 child - RIGHT
            else if (match->left == nullptr && match->right != nullptr){
                left == true ? parent->left = match->right : parent->right = match->right;
                match->right = nullptr;
                delPtr = match;
                delete delPtr;
                std::cout << "The node containing the key " << matchKey << " was removed\n";
            }
            //if 1 child - LEFT
            else if (match->left != nullptr && match->right == nullptr){
                left == true ? parent->left = match->left : parent->right = match->left;
                match->left = nullptr;
                delPtr = match;
                delete delPtr;
                std::cout << "The node containing the key " << matchKey << " was removed\n";
            }

            //if 2 children
            else{
                smallestInRightSubtree = FindSmallestPrivate(match->right);
                RemoveNodePrivate(smallestInRightSubtree, match);
                match->key = smallestInRightSubtree;
            }

        }
        else{
            TK_EXCEPTION("Tree is empty\n");
        }
    }

//-------------------------------------------------------------------------------------------------------------------------------
    //----REMOVE SUBTREE----
    void BinaryTree::RemoveSubtree(node * Ptr){
        if (Ptr != nullptr){

            if (Ptr->left != nullptr){
                RemoveSubtree(Ptr->left);
            }
            if (Ptr->right != nullptr){
                RemoveSubtree(Ptr->right);
            }
            std::cout << "Deleting the node containing the key " << Ptr->key << "\n";
            delete Ptr;
        }
    }