#include "stdafx.h"

/*
Given a m x n grid filled with non-negative numbers, 

find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

namespace MinimumPathSum {
	class Solution {
	public:
		int minPathSum(vector<vector<int>>& grid) {
			int m = grid.size(), n = grid[0].size();
			vector<vector<int>> records(m, vector<int>(n, -1));
			records[0][0] = 0;
			int ans =  findMinSum(grid, records, m - 1, n - 1);
			return ans;
		}
	private:
		int findMinSum(vector<vector<int>>& grid, vector<vector<int>>& records, int x, int y) {
			if (records[x][y] >= 0)
				return records[x][y];

			if (x + y == 1) {
				records[x][y] = grid[x][y];
				return records[x][y];
			}

			int path1 = INT_MAX, path2 = INT_MAX;
			if (x - 1 >= 0)
				path1 = findMinSum(grid, records, x - 1, y) + grid[x - 1][y];
			if (y - 1 >= 0)
				path2 = findMinSum(grid, records, x, y - 1) + grid[x][y - 1];

			records[x][y] = min(path1, path2);
			return records[x][y];
		}
	};
	TEST_CLASS(minPathSum) {
	public:
		TEST_METHOD(MinimumPathSum) {
			test({ {1,3,1}, {1,5,1},{4,2,1} }, 7);
		}
	private:
		void test(vector<vector<int>> grid, int expected) {
			Solution sln;
			int actual = sln.minPathSum(grid);
			Assert::AreEqual(expected, actual);
		}
	};
}