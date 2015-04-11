#ifndef DS_DL_NODE_H_
#define DS_DL_NODE_H_

#include <stdlib.h>

template <class T>
class DLNode
{
    private:
        DLNode<T> * next_;
        DLNode<T> * prev_;
        T * data_;

    public: 
        DLNode()
        {
            data_ = nullptr;
            next_ = nullptr;
            prev_ = nullptr;
        }

        DLNode(T data)
        {
            data_ = static_cast<T*>(malloc(sizeof(T)));
            (*data_) = data;

            next_ = nullptr;
            prev_ = nullptr;
        }

        ~DLNode()
        {
            free(data_);
        };
        
        DLNode<T> * next() const { return next_; }
        DLNode<T> * prev() const { return prev_; }
        T * data() const { return data_; }

        void set_next(DLNode<T> * next) { next_ = next; }
        void set_prev(DLNode<T> * prev) { prev_ = prev; }

        void print()
        {

        };
};

#endif

