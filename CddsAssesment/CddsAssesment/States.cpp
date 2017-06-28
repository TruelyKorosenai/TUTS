#include "StateManager.h"
#include "List.h"
#include "binaryTree.h"
#include "HashTable.h"


void ListTestState::onEnter(g_States fromState) {
	//*********************************************************************************************************************
	//******************************************LIST LINKS****************************************************************
	//*********************************************************************************************************************
	std::cout << "State:ListTest" << std::endl;

	std::cout << "*LINK LISTS*\n\n";
	List init;
	for (int i = 0; i < 100; i++) {
		init.AddNode(i);
	}
	for (int i = 0; i < 100; i++) {
		init.DeleteNode(i);
		if (init.SearchList(i) == true) {
			std::cout << "TEST FAILED:" << i << "was not correctly removed";
			break;
		}
		if (i == 99) {
			std::cout << "Test Passed" << std::endl;
		}
	}
	init.PrintList();
	
	std::cout << "----------------------" << std::endl;
	system("pause");
	StateMachine::GetStateMachine().setState(g_States::BinaryTest);
}

 void BinaryTestState::onEnter(g_States fromState) {
	std::cout << "State:BinaryTest" << std::endl;

	//*********************************************************************************************************************
	//******************************************BINARY TREE****************************************************************
	//*********************************************************************************************************************
	std::cout << "----------------------" << std::endl;
	std::cout << "*BINARY TREES*\n\n";
	BinaryTree btree;

	for (int i = 0; i < 100; i++) {
		btree.AddLeaf(i);
	}
	if (btree.FindSmallest() != 0)
	{
		std::cout << "Test failed the smallest number should be '0'" << std::endl;
	}
	for (int i = 0; i < 100; i++) {
	btree.PrintChildren(i);
		btree.RemoveNode(i);
		if (btree.SearchTree(i) == true) {
			std::cout << "TEST FAILED:" << i << "was not correctly removed";
			break;
		}
		if (i == 99) {
			std::cout << "Test Passed" << std::endl;
		}
	}
	btree.PrintInOrder();
	std::cout << std::endl;
	std::cout << "----------------------" << std::endl;
	system("pause");
	StateMachine::GetStateMachine().setState(g_States::HashTableTest);
}
 void HashTableTestState::onEnter(g_States fromState) {
	std::cout << "State:HashTables" << std::endl;
	//*********************************************************************************************************************
	//******************************************HASH TABLES****************************************************************
	//*********************************************************************************************************************
	std::cout << "----------------------" << std::endl;
	std::cout << "*HASH TABLES*\n\n";
	HashTable hash(100);
	std::string input, key;

	for (int i = 0; i < 100; i++) {
		input = i + rand() % 255;
        input += i + rand() % 255;
        input += i + rand() % 255;
        key = i;
		hash.AddItem(key.c_str(), input);
        //std::cout << "Key: "<< key << "Value: " << input;
	}
	//std::cout << "-------------------------------------\n\n\n";
	hash.PrintTable();
	//std::cout << "-------------------------------------\n\n\n";

    key = "";
	for (int i = 0; i < 100; i++) {
        key = i;
		hash.FindValue(key);
	}
	//std::cout << "-------------------------------------\n\n\n";
    system("pause >nul");
 }