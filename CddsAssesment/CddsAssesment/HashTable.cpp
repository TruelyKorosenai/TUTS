#include "HashTable.h"

HashTable::HashTable(int tablesize) : m_tableSize(tablesize){
    m_HashTable.resize(tablesize); //resize the vector
    for (int i = 0; i < (int)m_HashTable.size(); i++){ //initialise our table
        //create index at every new item
        m_HashTable[i] = new item; 
        m_HashTable[i]->key = "Empty";
        m_HashTable[i]->value = "Empty";
        m_HashTable[i]->next = nullptr;
    }
}

//----------------------------------------------------------------------------------------------------------------------
//----HASH FUNCTION----
//----calculates the hash value
int HashTable::HashFunc(std::string key){
    int hash_int = 0;
    int index;

    //add up all the asci key values 
    for (int i = 0; i < (int)key.length(); i++){ 
        hash_int +=  (int)key[i] * 33;
    }
    //hash int = the asci key values, for example, 529 / 10 (tablesize) = 52 'r' 9
    //the '%' mod sign will store us the remainder value. example 52 'r' 9. we will take the number 9.
    index = hash_int % m_HashTable.size(); 
    return index;                          
   
}

//----------------------------------------------------------------------------------------------------------------------
//----ADD ITEM----

void HashTable::AddItem(std::string key, std::string value){
    int index = HashFunc(key);//finds out the remainder number of the asci key name and stores into index.

    if (m_HashTable[index]->key == "Empty"){ //if empty, create.
    
        m_HashTable[index]->key = key;
        m_HashTable[index]->value = value;
    }
    else{ 
        //if section is full, link it onto the same section
        item* Ptr = m_HashTable[index];
        item* n = new item;

        n->key = key; 
        n->value = value;
        n->next = nullptr;
        //if pointer->next is not the lists end    
        while (Ptr->next != nullptr){ 
            Ptr = Ptr->next;
        }
        Ptr->next = n;
    }
}

//----------------------------------------------------------------------------------------------------------------------
//----NUMBER OF ITEMS IN INDEX

int HashTable::NumberOfItemsInIndex(int index){
    int count = 0;
    //look at first item in the index value
    if (m_HashTable[index]->key == "Empty"){return count;}

    else{
        count++;
        item* Ptr = m_HashTable[index]; 
        while (Ptr->next != nullptr){         
            count++;
            Ptr = Ptr->next;
        }
    }
    return count;
}

//----------------------------------------------------------------------------------------------------------------------
//----PRINT TABLE----

void HashTable::PrintTable(){
    int number; //total elements in each node
    for (int i = 0; i < (int)m_HashTable.size(); i++){
        number = NumberOfItemsInIndex(i);
        std::cout << "----------------\n";
        std::cout << "index = " << i << std::endl;
        std::cout << HashFunc( m_HashTable[i]->key ) << "\n";
        std::cout << m_HashTable[i]->value.c_str() << "\n";

        std::cout << "number of items = " << number << "\n";
        std::cout << "----------------\n";
    }
}

//----------------------------------------------------------------------------------------------------------------------
//----PRINT ITEMS IN INDEX----

int HashTable::PrintItemsInIndex(int index){
    item* Ptr = m_HashTable[index];
    if (index > (int)m_HashTable.size()){    
        std::cout << "Index value " << index << " is out of the range, MAX: " << m_HashTable.size() << "\n";
        std::cout << "ERROR: Line 133 file HashTable.cpp (index number is out-of-bounds)\n\n";
        throw ("ERROR: Line 134 file HashTable.cpp");
        //Throwing error if out-of-bounds
        return false;
    }
    if (Ptr->key == "Empty"){std::cout << "Index " << index << " is empty\n";}
    else{
        std::cout << "Index " << index << " contains the following items\n";

        while (Ptr != nullptr){
            std::cout << "-----------------------\n";
            std::cout << Ptr->key << "\n";
            std::cout << Ptr->value << "\n";
            std::cout << "-----------------------\n";
            Ptr = Ptr->next;
        }
    }
    return true;
}

//----------------------------------------------------------------------------------------------------------------------
//----FIND VALUE----

void HashTable::FindValue(std::string key){
    /*int index = HashFunc(key);
    bool foundName = false;
  
    std::string value;
    int count = 0;
    item* Ptr = m_HashTable[0];
    while (count < m_tableSize - 1){
        count++;
        if (Ptr->key == key){
            foundName = true;
            value = Ptr->value;
            std::cout << "The value associated with " << key.c_str() << " = " << value.c_str() << "\n";
            return;
        }
        Ptr = m_HashTable[count];
    }*/
    int index = HashFunc(key);
    item* Ptr = m_HashTable[index];

    std::cout << "The value associated with " << HashFunc(Ptr->key) << " = " << Ptr->value.c_str() << "\n";

    //if(foundName == false){
    //    std::cout << "The key -> " << key.c_str() << " Was not found in the Hash Table\n";
    //}
        
}


//----------------------------------------------------------------------------------------------------------------------
//----REMOVE ITEM----

void HashTable::RemoveItem(std::string key){
    int index = HashFunc(key);

    item* delPtr;
    item* P1;
    item* P2;

    if (m_HashTable[index]->key == "Empty"){std::cout << key << " Was not found in the hash table\n";}

    // 1 match contained in the list--
    else if (m_HashTable[index]->key == key && m_HashTable[index]->next == nullptr){
        m_HashTable[index]->key = "Empty";
        m_HashTable[index]->value = "Empty";
        std::cout << key << " was removed from the Hash Table\n";
    }

    // More than one contained within the list
    else if (m_HashTable[index]->key == key){
        delPtr = m_HashTable[index];
        m_HashTable[index] = m_HashTable[index]->next;
        delete delPtr;

        std::cout << key << " was removed from the Hash Table\n";
    }

    // The node contains items but not the first item
    else{
        P1 = m_HashTable[index]->next;
        P2 = m_HashTable[index];

        while (P1 != nullptr && P1->key != key){
            P2 = P1;
            P1 = P1->next;
        }
        // No match
        if (P1 == nullptr){
            std::cout << key << " was not found in the Hash Table\n";
        }
        // Match
        else{
            delPtr = P1;
            P1 = P1->next;
            P2->next = P1;

            delete delPtr;
            std::cout << key << " was removed from the Hash Table\n";
        }
    }

}