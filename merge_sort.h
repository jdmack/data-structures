#include <list>

template <typename T>
class MergeSort
{
    public:
        std::list<T> sort(std::list<T> list)
        {
            // 1 or less elements, return
            if(list.size() <= 1) {
                return list;
            }

            // Split list in half
            std::list<T> list1 = std::list<T>();
            std::list<T> list2 = std::list<T>();
                
            int size = list.size();

            for(int i = 0; i < size / 2; ++i) {
                list2.insert(list.front());
                list.pop_front();
            }

            // recurse on each sublist
            list1 = sort(list1);
            list2 = sort(list2);

            list1 = merge(list1, list2);
            
            return list1;
        }

    private:
        std::list<T> merge(std::list<T> list1, std::list<T> list2)
        {
            std::list<T> sorted_list = std::list<T>();

            while(!list1.empty() && !list2.empty()) {

                // A <= B, add A to sorted_list
                if(list1.front() <= list2.front()) {
                    sorted_list.push_back(list1.front());
                    list1.pop_front();
                }
                // A > B, add B to sorted_list
                else {
                    sorted_list.push_back(list2.front());
                    list2.pop_front();
                }
            }

            while(!list1.empty()) {
                sorted_list.push_front(list1.front());
                list1.pop_front();
            }
            while(!list2.empty()) {
                sorted_list.push_back(list2.front());
                list2.pop_front();
            }

            return sorted_list;
        }
};
