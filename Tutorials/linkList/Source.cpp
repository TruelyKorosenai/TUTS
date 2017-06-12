#include "List.h"
#include <stdlib.h>



int main() {



    List init;

    init.AddNode(3);
    init.AddNode(5);
    init.AddNode(7);
    init.PrintList();
    init.DeleteNode(3);
    init.PrintList();

	



    system("pause>nul");
    return 0;
}