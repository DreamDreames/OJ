#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;


int findNext(int N, char ** grid, int i, int j){
	if (i < 0 || i >= N || j < 0 || j >= 10 )
		return -1;
	if (grid[i][j] != 'd')
		return -1;

	findNext(N, grid, i - 1, j);
	findNext(N, grid, i + 1, j);
	findNext(N, grid, i, j + 1);
	findNext(N, grid, i, j - 1);
}

int main7() {
	int N, i, j;
	int ships[] = { 0, 2, 2, 1, 1, 1 };
	cin >> N;
	char** grid = new char*[N + 1];
	for (i = 0; i < N; ++i){
		grid[i] = new char[10];
		for (j = 0; j < 10; ++j){
			cin >> grid[i][j];
		}
	}
	for (i = 0; i < N; ++i){
		for (j = 0; j < 10; ++j){
			if (grid[i][j] == 'h'){

			}
		}
	}
	return 0;
}
