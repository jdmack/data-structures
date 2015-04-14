#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "s_node.h"
#include "stack.h"

void print_stack(Stack<int> * stack);

int main()
{
    Stack<int> * stack = new Stack<int>(); 
    print_stack(stack);

    // Pop empty stack
    stack->pop();

    // Top empty stack
    stack->top();
    print_stack(stack);

    stack->push(0);
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    print_stack(stack);
    stack->pop();
    stack->pop();
    stack->push(-3);
    stack->push(-4);
    print_stack(stack);
    stack->pop();
    stack->pop();
    stack->pop();

    print_stack(stack);
}


void print_stack(Stack<int> * stack)
{
    SNode<int> * current = stack->top_node();
    std::cout << "{ ";
    while(current != nullptr) {
        std::cout << "[" << *current->data() << "] ";
        current = current->prev();
    }
    std::cout << "}" << std::endl;
}

