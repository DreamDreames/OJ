#include "shared.h"

namespace Algorithms {
    class Sort{
    public:
        void insertSort(vector<int>& arr){
            for(int i = 1; i < arr.size(); ++ i){
                int key = arr[i];
                int j = i - 1;
                while(j >= 0 && arr[j] > key){
                    swap(arr[j], arr[j + 1]);
                    j --;
                }
                arr[j + 1] = key;
            }
        }
        void insertSort(int arr[], int length){
            for(int i = 1; i < length; ++ i){
                int key = arr[i];
                int j = i - 1;
                while(j >= 0 && arr[j] > key){
                    swap(arr[j], arr[j + 1]);
                    j --;
                }
                arr[j + 1] = key;
            }
        }
    };
    class helper{
    public:
        void test(vector<int> original, vector<int> expected){
            Sort s;
            auto temp = original;
            s.insertSort(temp);
            ASSERT_EQ(temp, expected);
            auto temp2 = original;
            s.insertSort(&temp2[0], (int)temp2.size());
            ASSERT_EQ(temp2, expected);
        }
    };
    TEST(Sort, sort) {
        helper h;
        h.test({5, 4, 3, 2, 1}, {1, 2, 3, 4, 5});
        h.test({1}, {1});
        h.test({2, 1}, {1, 2});
        h.test({1, 2}, {1, 2});
    }
}
