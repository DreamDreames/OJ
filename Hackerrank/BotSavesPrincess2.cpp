#include <iostream>
#include <vector>
#include <string>
using namespace std;
void nextMove(int n, int r, int c, vector <string> grid){
	int px, py;
	for (int i = 0; i < n; ++i){
		const auto &g = grid[i];
		py = g.find_first_of('p');
		if (py != string::npos){
			px = i;
			break;
		}
	}
	if (r < px)
		cout << "DOWN" << endl;
	else if (r > px)
		cout << "UP" << endl;
	else if (c < py)
		cout << "RIGHT" << endl;
	else if (c > py)
		cout << "LEFT" << endl;
}
int main2(void) {

	int n, r, c;
	vector <string> grid;

	cin >> n;
	cin >> r;
	cin >> c;

	for (int i = 0; i<n; i++) {
		string s; cin >> s;
		grid.push_back(s);
	}

	nextMove(n, r, c, grid);
	nextMove(3, 1, 1, { "---", "-m-", "p--" });
	nextMove(3, 1, 1, { "---", "-m-", "-p-" });
	nextMove(3, 1, 1, { "---", "-mp", "---" });

	getchar();
	return 0;
}