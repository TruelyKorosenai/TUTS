#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

    /*This is a Hash Table Class
    - It only operates with strings (std::string)
    @Param string (Key)
    @Param string (value)  */
class HashTable{
//*********************************************************************************************************************
//************************************************PUBLIC***************************************************************
//*********************************************************************************************************************
public:
    /*---- Constructor----
    @Param int (tablesize)*/
    HashTable(int tablesize);

    int Size(){ return m_tableSize; }

    /*---- Add Item ----
    @param (key, value) - (std:string)
    @return (void) - (null)*/
    void AddItem(std::string key, std::string value);

    /*---- Find Value----
    searches for a key (*string*), if found hash table,
    returns that keys value
    @param - string (key)
    @return void - NULL*/
    void FindValue(std::string key);


    /*---- Print Table ----
    @param - (NULL)
    @return (void) - (NULL)*/
    void PrintTable();


    /*---- Print Items in Index ----
    *Example*: passing in the value 8, will cause a printout of the
    stored keys in the list of (node)/(value) 8
    @param (int) - (index)
    @return (int) - returns true or false.
    boundries on tablesize array applied, (Throws an error)*/
    int PrintItemsInIndex(int index);

    /*---- RemoveItem----
    Removes an item from the hash table
    @Param (string) - (key)
    @return (void) - (Null)*/
    void RemoveItem(std::string key);

    /* ---- Hash ----
    Evaluates the (key) value, Casts to an integer of the hash table.
    returns the integer value that represents the location 
    of the stored key in the hash table.    
    @param (addData) - (key) passes in a string variable
    @return (int) - (index) value*/
    int HashFunc(std::string key);

//*********************************************************************************************************************
//******************************************//PRIVATE//****************************************************************
//*********************************************************************************************************************
private:
    int m_tableSize;

    /*---- NumberOfItemsInIndex ----
    @param (int) - (index)
    @return (int) - (index) value*/
    int NumberOfItemsInIndex(int index);
    // ---- Items that we want to store in our hash table, consists of 2 strings and 1 pointer ---- 
        struct item { 
        std::string key; //person
        std::string value; //persons favourite drink
        item* next; //Points to the next item
    };

    /*---- has x amount of index's,
    ----@Param <int*> - (index) points to an item*/
    std::vector<item*> m_HashTable;  
};
    
