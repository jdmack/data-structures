#ifndef DS_STACK_H_
#define DS_STACK_H_

#include "s_node.h"

template <class T>
class Stack
{
    private:
        SNode<T> * top_; 
        int size_;

    public:
        Stack()
        {
            top_ = nullptr;
            size_ = 0;
        }

        ~Stack()
        {
            empty();
        }

        T top()
        { 
            if(top_ == nullptr) {
                return 0;
            }
            else {
                return *top_->data(); 
            }
        }

        SNode<T> * top_node() const { return top_; }    // For test printing only
        int size() const { return size_; }

        void push(T data)
        {
            SNode<T> * node = new SNode<T>(data);

            node->set_prev(top_); 
            top_ = node;
            ++size_;
        }

        T pop()
        {
            if(top_ == nullptr) {
                return 0;
            }
            
            SNode<T> * node = top_;
            top_ = node->prev();
            T data = *node->data();

            delete node;
            --size_;

            return data;
        }

        void empty()
        {
            while(top_ != nullptr) {
                pop();
            }
        }

};

#endif

