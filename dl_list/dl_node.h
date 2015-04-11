
template <class T>
class DLNode
{
    private:
        DLNode<T> * next_;
        DLNode<T> * prev_;
        T * data_;

    public: 
        DLNode();
        DLNode(T data);
        ~DLNode();
        
        DLNode<T> * next() const { return next_; }
        DLNode<T> * prev() const { return prev_; }
        T * data() const { return data_; }

        void print();
};
template class DLNode<int>;
