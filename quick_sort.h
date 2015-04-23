#include <iostream>
#include <list>

template <typename T>
class QuickSort
{
    public:

        static std::list<T> * sort(std::list<T> * list)
        {
            // If 1 or less elements, return list as it is sorted
            if(list->size() <= 1) {
                return list;
            }

            // Choose pivot value (off end of list)
            T pivot = list->back();
            list->pop_back();

            // Split list into 3 lists: less_than, equal_to, greater_than
            std::list<T> * less_than = new std::list<T>();
            std::list<T> * equal_to = new std::list<T>();
            std::list<T> * greater_than = new std::list<T>();

            // Add pivot to equal_to list
            equal_to->push_back(pivot);

            while(!list->empty()) {
                if(list->front() < pivot) {
                    less_than->push_back(list->front());
                }
                else if(list->front() == pivot) {
                    equal_to->push_back(list->front());
                }
                else {
                    greater_than->push_back(list->front());
                }
                list->pop_front();
            }

            // Recurse on the less_than and greater_than list
            less_than = sort(less_than);
            greater_than = sort(greater_than);

            std::list<T> * sorted_list = new std::list<T>();

            // Concatenate the lists
            sorted_list = concat_lists(less_than, equal_to);
            sorted_list = concat_lists(sorted_list, greater_than);

            // clean up temporary lists
            delete less_than;
            delete equal_to;
            delete greater_than;
            
            // Return sorted list
            return sorted_list; 
        }
        
    private:
        static std::list<T> * concat_lists(std::list<T> * list_front, std::list<T> * list_back)
        {

            std::list<T> * concatenated_list = new std::list<T>();
            
            while(!list_front->empty()) {
                concatenated_list->push_back(list_front->front());
                list_front->pop_front();
            }

            while(!list_back->empty()) {
                concatenated_list->push_back(list_back->front());
                list_back->pop_front();
            }

            return concatenated_list;
        }
};
