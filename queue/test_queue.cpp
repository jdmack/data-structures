#include <iostream>
#include <stdio.h>
#include "queue.h"

void print_queue(Queue<int> * queue);

int main()
{
    int * data;
    Queue<int> * queue = new Queue<int>(10);
    //print_queue(queue);

    for(int j = 0; j < 100; ++j) {
        print_queue(queue);
        for(int i = 0; i < 10; ++i) {
            queue->enqueue(i);
            //print_queue(queue);
        }
        print_queue(queue);
        for(int i = 0; i < 10; ++i) {
            queue->dequeue();
            //print_queue(queue);
        }
    }
    //queue->dequeue();

    
    print_queue(queue);

    //data = queue->dequeue();
    //std::cerr << "dequeued: " << *data << std::endl;
    //std::cerr << "size: " << queue->size() << std::endl; 

}

void print_queue(Queue<int> * queue)
{
    int ** elements = queue->elements();
    unsigned int front = queue->front_i();
    unsigned int back = queue->back_i();
    unsigned int max_size = queue->max_size();
    unsigned int size = queue->size();

    std::cerr << "front: " << front;
    std::cerr << "  back: " << back;
    std::cerr << "  max: " << max_size;
    std::cerr << "  size: " << size;

    std::cerr << "  {";

    unsigned int index = front;

    for(unsigned int i = 0; i < size; ++i) {
        
        std::cerr << "(" << index << ")";
        std::cerr << " [" << *elements[index] << "]";

        index++;
        if(index >= max_size) {
            index -= max_size;
            //std::cerr << "(" << index << ")";
        }
    }

    std::cerr << " }" << std::endl;



}

