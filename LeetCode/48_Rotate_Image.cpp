#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
//#include "gtest/gtest.h"

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
			flip(matrix);
			fold(matrix);
        }
	private:
		void flip(vector<vector<int>>& matrix) {
			int n = matrix.size() - 1;
			for (int i = 0; i <= n; ++i) {
				int middle = n / 2;
				for (int j = 0; j <= middle; ++j) {
					swap(matrix[i][j], matrix[i][n - j]);
				}
			}
		}
		void fold(vector<vector<int>>& matrix) {
			int n = matrix.size() - 1;
			for (int i = 0; i <= n; ++i) {
				for (int j = 0; j < n - i; ++j) {
					swap(matrix[i][j], matrix[n - j][n - i]);
				}
			}
		}
    };
    class helper{
    public:
        void test(vector<vector<int>> matrix){
			Solution sln;
			sln.rotate(matrix);
            for(auto & row : matrix){
                for(int n : row){
                    cout << n << " ";
                }
                cout << endl;
            }
        }
    };
	TEST_CLASS(Rotate) {
	public:
		TEST_METHOD(RotateImage) {
			helper h;
			h.test({ {1, 2, 3}, {4, 5, 6}, {7, 8 ,9} });
			h.test({ {1} });
			h.test({ {1, 2}, {3, 4} });
		}
	};
}
