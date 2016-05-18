#include <vector>
using namespace std;

namespace Algorithms {
    class heap{
    public:
        void heap_sort(vector<int>& arr){
            build_max_heap(arr);
            int size = (int)arr.size();
            for(int i = size - 1; i > 0; -- i){
                swap(arr[i], arr[0]);
                max_heapify(arr, 0, -- size);
            }
        }
        void build_max_heap(vector<int>& arr){
            int size = (int)arr.size();
            for(int i = parent(size - 1); i >= 0; -- i){
                max_heapify(arr, i, size);
            }
        }

    private:
        void max_heapify(vector<int>& arr, int i, int size){
            int l = left(i);
            int r = right(i);
            int largest = i;
            if(l < size && arr[l] > arr[i])
                largest = l;
            
            if(r < size && arr[r] > arr[largest])
                largest = r;
            
            if(i != largest){
                swap(arr[i], arr[largest]);
                max_heapify(arr, largest, size);
            }
            
        }

        int left(int i){
            return 2 * (i + 1) - 1;
        }
        int right(int i){
            return 2 * (i + 1);
        }
        int parent(int i){
            return (i + 1) / 2 - 1;
        }
    };
}
