#include <iostream>
#include <stdlib.h>
#include <list>
#include <time.h>
#include "merge_sort.h"

void print_list(std::list<int> list);

int main()
{
    srand(time(NULL)); 

    int num_of_eles = 20;

    std::list<int> list = std::list<int>();
    
    for(int i = 0; i < num_of_eles; ++i) {
        int random_num = rand() % 99;
        list.push_back(random_num);
    }
    
    print_list(list);

    list = MergeSort<int>::sort(list);

    print_list(list);

}

void print_list(std::list<int> list)
{
    std::cout << "{";

    for(std::list<int>::iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << " [" << *it << "]";
    }
    std::cout << " }"  << std::endl;

}

