#ifndef DS_S_NODE_H_
#define DS_S_NODE_H_

template <class T>
class SNode
{
    private:
        SNode<T> * prev_;
        T * data_;

    public:
        SNode()
        {
            data_ = static_cast<T *>(malloc(sizeof(T)));
            prev_ = nullptr;
        }

        SNode(T data)
        {
            data_ = static_cast<T *>(malloc(sizeof(T)));

            *data_ = data;
            prev_ = nullptr;
        }

        ~SNode()
        {
            free(data_);
        }
    
        SNode<T> * prev() { return prev_; }
        T * data() { return data_; }
        
        void set_prev(SNode<T> * prev) { prev_ = prev; }
        void set_data(T data) { *data_ = data; }
};

#endif

