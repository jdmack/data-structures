#include "dl_node.h"
#include <stdlib.h>

template<class T>
DLNode<T>::DLNode()
{
    data_ = nullptr;
    next_ = nullptr;    
    prev_ = nullptr;    
}

template<class T>
DLNode<T>::DLNode(T data)
{
    data_ = static_cast<T*>(malloc(sizeof(T)));
    (*data_) = data;

    next_ = nullptr;    
    prev_ = nullptr;    
}

template<class T>
DLNode<T>::~DLNode()
{

}


template<class T>
void DLNode<T>::print()
{
}
