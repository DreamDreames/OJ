#include "stdafx.h"

/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
[0,0,0],
[0,1,0],
[0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/


namespace UniquePaths2 {
	class Solution {
	public:
		int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
			int m = obstacleGrid.size();
			if (m == 0 || obstacleGrid[0][0] == 1)
				return 0;
			int n = obstacleGrid[0].size();
			vector<vector<int>> records(m, vector<int>(n, -1));
			records[0][0] = 1;
			return countPaths(obstacleGrid, records, m - 1, n - 1);
		}
	private:
		int countPaths(vector<vector<int>>& obstacleGrid, vector<vector<int>>& records, int x, int y) {
			if (x < 0 || y < 0)
				return 0;
			if (records[x][y] >= 0)
				return records[x][y];

			if (obstacleGrid[x][y] == 1) {
				records[x][y] = 0;
				return 0;
			}
			if (x + y == 1) {
				records[x][y] = 1;
				return 1;
			}

			records[x][y] = countPaths(obstacleGrid, records, x - 1, y) + countPaths(obstacleGrid, records, x, y - 1);
			return records[x][y];
		}
	};
}