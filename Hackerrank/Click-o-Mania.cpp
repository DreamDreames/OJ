#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace ClickMania{
	void nextMove(int x, int y, int color, vector <string> grid){
		//your logic here
	}
}
int main(void) {

	int x, y, k;
	cin >> x >> y >> k;
	vector <string> grid;

	for (int i = 0; i<x; i++) {
		string s; cin >> s;
		grid.push_back(s);
	}

	ClickMania::nextMove(x, y, k, grid);

	return 0;
}