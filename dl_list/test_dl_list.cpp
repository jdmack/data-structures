#include "dl_node.h"
#include <stdio.h>

int main()
{
    DLNode<int> * node1 = new DLNode<int>();
    printf("node1: %d\n", *(node1->data()));
}
