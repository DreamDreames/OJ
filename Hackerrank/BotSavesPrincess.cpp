#include <iostream>
#include <vector>
#include <string>
using namespace std;

void displayPathtoPrincess(int n, vector <string> grid){
	int botx, boty, princessx, princessy;
	botx = princessx = -1;
	for (int i = 0; i < n; ++i){
		const auto& row = grid[i];
		for (int j = 0; j < n; ++j){
			if (row[j] == 'p'){
				princessx = i; princessy = j;
				if (botx != -1)
					break;
			}
			else if (row[j] == 'm'){
				botx = i; boty = j;
				if (princessx != -1)
					break;
			}
		}
		if (botx != -1 && princessx != -1)
			break;
	}
	int diffx = botx - princessx, diffy = boty - princessy;
	string directionx = "UP", directiony = "LEFT";
	if (diffx < 0){
		diffx *= -1;
		directionx = "DOWN";
	}
	if (diffy < 0){
		diffy *= -1;
		directiony = "RIGHT";
	}
	while (diffx--){
		cout << directionx << endl;
	}
	while (diffy--){
		cout << directiony << endl;
	}
}

int main1(void) {

	//int m;
	//vector <string> grid;

	//cin >> m;

	//for (int i = 0; i < m; i++) {
	//	string s; cin >> s;
	//	grid.push_back(s);
	//}

	displayPathtoPrincess(3, {"---","-m-","p--"});

	getchar();
	return 0;
}
