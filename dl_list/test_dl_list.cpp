#include "dl_node.h"
#include "dl_list.h"
#include <stdio.h>

void print_list(DLList<int> list);

int main()
{
    DLList<int> list = DLList<int>();

    for(int x = 0; x < 10000; ++x) {
        for(int i = 0; i < 10; ++i) {
            list.insert(i);
            //print_list(list);
        }


        for(int i = 0; i < 10; ++i) {
            //list.remove(i);
            //print_list(list);
        }
    }
}

void print_list(DLList<int> list) 
{
    printf("{");
    DLNode<int> * current = list.head();

    while(current != nullptr) {
        printf(" [%d] ", (*current->data()));
        current = current->next();
    }
    printf("}\n");
}
