# data-structures
Implementation of various data structures in C++

## Doubly Linked List
Implemented with Nodes but with separate List object that holds the pointer to the head.

## Stack
Implemented via a linked list with Nodes.

## Queue
Implemented via an array of pointers, storing the index of the current front and back

## Building/Testing Commands
* valgrind --tool=memcheck --leak-check=yes ./a.out
* g++ test_dl_list.cpp -g -O0 -std=c++0x -Wall


