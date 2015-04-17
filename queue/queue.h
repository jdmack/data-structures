/* I wanted to be able to return nullptr when queue is empty, so this list weirdly stores 
   T data values as pointers and then returns the pointer. Definitely not good but just the
   way I'm doing it. It could be easily changed. */


#ifndef DS_QUEUE_H_
#define DS_QUEUE_H_

template <class T>
class Queue
{
    const unsigned int kDefaultSize = 100;
    private:
        T  ** elements_;

        unsigned int max_size_;
        unsigned int front_;
        unsigned int back_;
        unsigned int size_;
        
    public:
        Queue()
        {
            elements_ = new T*[kDefaultSize];
            max_size_ = kDefaultSize;
            front_ = 0;
            back_ = 0;
            size_ = 0;
        }

        Queue(unsigned int max_size)
        {
            elements_ = new T*[max_size];
            max_size_ = max_size;
            front_ = 0;
            back_ = 0;
            size_ = 0;
        }

        T * dequeue()
        {
            if(size_ == 0) {
                return nullptr;
            }

            T * data = elements_[front_];
            elements_[front_] = nullptr;

            --size_;
            // Don't move front_ if list is empty now
            if(size_ != 0) {
                ++front_;

                // Circle around
                if(front_ >= max_size_) {
                    front_ -= max_size_;
                }
            }
            
            return data;
        }

        void enqueue(T data)
        {
            // Store data
            T * d_ptr = new T;
            *d_ptr = data;

            if(size_ == 0) {
                elements_[front_] = d_ptr;
                ++size_;
            }
            else {
                // If full, return
                if(size_ >= max_size_ ) {
                    return;
                }

                ++back_;

                if(back_ >= max_size_) {
                    back_ -= max_size_;
                }
                elements_[back_] = d_ptr;
                
                ++size_;
            }
        }

        T * front()
        {
            if(size_ == 0) {
                return nullptr;
            }

            return (*elements_)[front_];
        }

        T * back() 
        {
            if(size_ == 0) {
                return nullptr;
            }

            return (*elements_)[back_];
        }

        unsigned int size() const { return size_; }
        int ** elements() const { return elements_; }   // for debug printing only
        unsigned int front_i() const { return front_; }
        unsigned int back_i() const { return back_; }
        unsigned int max_size() const { return max_size_; }


};

#endif

