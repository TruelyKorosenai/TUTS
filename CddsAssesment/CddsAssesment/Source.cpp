#include "List.h"
#include "binaryTree.h"
#include "HashTable.h"
#include <iostream>
#include "StateManager.h"

int main() {
    StateMachine sm;
    sm.setState(g_States::INIT);
    
    //*********************************************************************************************************************
    //*******************************************LINK LISTS****************************************************************
    //*********************************************************************************************************************
    std::cout << "*LINK LISTS*\n\n";
    List init;

    init.AddNode(3);
    init.AddNode(5);
    init.AddNode(7);
    init.PrintList();
    init.DeleteNode(3);
    init.PrintList();
    std::cout << "----------------------" << std::endl;
    system("pause");


    //*********************************************************************************************************************
    //******************************************BINARY TREE****************************************************************
    //*********************************************************************************************************************
    std::cout << "----------------------" << std::endl;
    std::cout << "*BINARY TREES*\n\n";
  BinaryTree btree;

    btree.AddLeaf(1);
    btree.AddLeaf(2);
    btree.AddLeaf(3);
    btree.AddLeaf(4);
    btree.AddLeaf(5);
    btree.RemoveNode(2);
    btree.PrintInOrder();
    std::cout << std::endl;
    std::cout << "----------------------" << std::endl;
    system("pause");
    
    //*********************************************************************************************************************
    //******************************************HASH TABLES****************************************************************
    //*********************************************************************************************************************
    std::cout << "----------------------" << std::endl;
    std::cout << "*HASH TABLES*\n\n";
    HashTable hash(100);
    std::string input;

    for (int i = 0; i < 100; i++) {
        input += rand() % 255;

        hash.AddItem(input, "Value");
        std::cout << input;
    }
    std::cout << "-------------------------------------\n\n\n";
    hash.PrintTable();
    std::cout << "-------------------------------------\n\n\n";

    for (int i = 0; i < 100; i++) {
        hash.FindValue(input);
    }
    std::cout << "-------------------------------------\n\n\n";

    HashTable hashObject(1000);
    std::string name = "";
    std::string AorS = "";
    std::string number = "";

    hashObject.AddItem("P1", "11111");
    hashObject.AddItem("P1", "2222");
    hashObject.AddItem("P3", "3333");
    hashObject.AddItem("P4", "4444");
    hashObject.AddItem("P5", "5555");
    hashObject.AddItem("P6", "6666");
    hashObject.AddItem("P7", "7777");
    hashObject.AddItem("P8", "8888");
    hashObject.AddItem("P9", "9999");
    hashObject.AddItem("P10", "10101010");
    hashObject.AddItem("P11", "11111111");
    hashObject.AddItem("P12", "12121212");

    while (name != "exit") {
        std::cout << "----A to add user, S to search for user, P to print list, PI to print items in index. R - remove item.----\n";
        std::cin >> AorS;
        //add
        if (AorS == "A") {
            system("cls");
            std::cout << "\n Add user = ";
            std::cin >> name;
            std::cout << "\n Add users serial code = ";
            std::cin >> number;
            hashObject.AddItem(name, number);
            std::cout << "\n---------User and serial code has been added------\n";
        }

        //search 
        else if (AorS == "S") {
            system("cls");
            std::cout << "\nSearch for: ";
            std::cin >> name;
            hashObject.FindValue(name);
        }

        //print table
        if (AorS == "P") {
            system("cls");
            hashObject.PrintTable();
        }

        //print index
        if (AorS == "PI") {
            system("cls");
            std::cout << " Pass in value: \n";
            int value;
            std::cin >> value;
            hashObject.PrintItemsInIndex(value);
        }

        //remove item
        if (AorS == "R") {
            system("cls");
            std::cout << " Pass in value: \n";
            std::cin >> name;
            hashObject.RemoveItem(name);
        }
    }
    system("pause");

    return 0;
}