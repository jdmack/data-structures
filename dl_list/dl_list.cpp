#include "dl_node.h"

template <class T>
class DLList
{
    private:
        DLNode * head_;
        DLNode * tail_;
        int size_;

    public: 
        DLList();
        ~DLList();
        
        bool insert(T data);
        bool delete(T data);
        bool contains(T data);

        DLList head() { return head_; }
        DLList tail() { return tail_; }
        int size() const { return size_; }

        void print();
}
