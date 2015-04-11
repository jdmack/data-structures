#ifndef DS_DL_LIST_H_
#define DS_DL_LIST_H_

#include "dl_node.h"

template <class T>
class DLList
{
    private:
        DLNode<T> * head_;
        DLNode<T> * tail_;
        int size_;

    public: 
        DLList()
        {
            size_ = 0;
            head_ = nullptr;
            tail_ = nullptr;
        }
        ~DLList()
        {

        }
        
        bool insert(T data)
        {
            DLNode<T> * node = new DLNode<T>(data);
            if(head_ == nullptr) {
                head_ = node; 
                tail_ = head_;
            }
            else {
                tail_->set_next(node);
                node->set_prev(tail_);
                tail_ = node;
            }
            ++size_;

            return true;
        }

        bool remove(T data)
        {
            DLNode<T> * current = head_;
            
            // Cycle through list
            while(current != nullptr) {

                // Check if current is the node we want
                if(*current->data() == data) {

                    // if it's the head and tail
                    if((current->next() == nullptr) && ((current->prev() == nullptr))) {
                        head_ = nullptr;
                        tail_ = nullptr;
                    }
                    // It's the head node
                    else if(current->prev() == nullptr) {
                        head_ = current->next();
                        head_->set_prev(nullptr);
                    }
                    // It's the tail node
                    else if(current->next() == nullptr) {
                        tail_ = current->prev();
                        tail_->set_next(nullptr);
                    }
                    // It's in the middle of the list
                    else {
                        current->prev()->set_next(current->next());
                        current->next()->set_prev(current->prev());
                    }
                    delete current;
                    --size_;
                    return true;
                }
                current = current->next();
            }

            return false;
        }

        DLNode<T> * lookup(T data)
        {
            DLNode<T> * current = head_;

            while(current != nullptr) {
                if(*current->data() == data) {
                    return current;
                }
            }

            return nullptr;
        }

        DLNode<T> * head() { return head_; }
        DLNode<T> * tail() { return tail_; }
        int size() const { return size_; }

        void print()
        {

        }
};

#endif

