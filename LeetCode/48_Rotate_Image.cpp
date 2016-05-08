#include <stdio.h>
#include <vector>
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

/*
 You are given an n x n 2D matrix representing an image.
 
 Rotate the image by 90 degrees (clockwise).
 
 Follow up:
 Could you do this in-place?
 
  1, 2, 3
  4, 5, 6,
  7, 8, 9
  
  
  7, 4, 1
  8, 5, 2
  9, 6, 3
     
*/

namespace RotateImage {
    class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            
        }
    };
    class helper{
    public:
        void test(vector<vector<int>> matrix){
            for(auto & row : matrix){
                for(int n : row){
                    cout << n << " ";
                }
                cout << endl;
            }
        }
    };
    TEST(RotateImage, rotate){
        helper h;
        h.test({{1, 2, 3}, {4, 5, 6}, {7, 8 ,9}});
    }
    /*
    */
}
