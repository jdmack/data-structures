#include <iostream>
#include <list> 
template <typename T>
class MergeSort
{
    public:
        static std::list<T> * sort(std::list<T> * list)
        {
            // 1 or less elements, return
            if(list->size() <= 1) {
                return list;
            }

            // Split list in half
            std::list<T> * list1 = new std::list<T>();
            std::list<T> * list2 = new std::list<T>();
                
            int size = list->size();

            for(int i = 0; i < size; ++i) {
                if(i < size / 2) {
                    list1->push_back(list->front());
                }
                else {
                    list2->push_back(list->front());
                }
                list->pop_front();
            }

            // recurse on each sublist
            list1 = sort(list1);
            list2 = sort(list2);

            std::list<int> * sorted_list = merge(list1, list2);
            delete list1;
            delete list2;
            
            return sorted_list;
        }

    private:
        static std::list<T> * merge(std::list<T> * list1, std::list<T>  * list2)
        {
            std::list<T> * sorted_list = new std::list<T>();

            while((!list1->empty()) && (!list2->empty())) {

                // A < B, add A to sorted_list
                if(list1->front() < list2->front()) {
                    sorted_list->push_back(list1->front());
                    list1->pop_front();
                }
                // A > B, add B to sorted_list
                else {
                    sorted_list->push_back(list2->front());
                    list2->pop_front();
                }
            }

            while(!list1->empty()) {
                sorted_list->push_back(list1->front());
                list1->pop_front();
            }
            while(!list2->empty()) {
                sorted_list->push_back(list2->front());
                list2->pop_front();
            }

            return sorted_list;
        }
};
