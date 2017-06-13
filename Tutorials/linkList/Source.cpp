#include "List.h"
#include "binaryTree.h"
#include <iostream>



int main() {
    List init;

    init.AddNode(3);
    init.AddNode(5);
    init.AddNode(7);
    init.PrintList();
    init.DeleteNode(3);
    init.PrintList();

    binaryTree init2;

    init2.insert(1);
    init2.insert(2);
    init2.insert(3);
    init2.insert(4);
    init2.insert(5);
    init2.search(4);
    std::cout << init2.search(4)->m_keyValue <<  std::endl;
    init2.destroy_tree();
    
    system("pause>nul");

    return 0;
}