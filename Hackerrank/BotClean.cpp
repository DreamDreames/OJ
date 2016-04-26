#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

void next_move(int posr, int posc, vector <string> board) {
	if (board[posr][posc] == 'd'){
		cout << "CLEAN" << endl;
		return;
	}
	int minstep = 1000, minx, miny;
	for (int i = 0; i < 5; ++i){
		const auto& b = board[i];
		for (int j = 0; j < 5; ++j){
			if (b[j] == 'd'){
				int curstep = abs(j - posc) + abs(i - posr);
				if (curstep < minstep){
					minx = i; miny = j;
					minstep = curstep;
				}
			}
		}
	}
	if (posr < minx)
		cout << "DOWN" << endl;
	else if (posr > minx)
		cout << "UP" << endl;
	else if (posc < miny)
		cout << "RIGHT" << endl;
	else if (posc > miny)
		cout << "LEFT" << endl;
}

int main3(void) {
	//int pos[2];
	//vector <string> board;
	//cin >> pos[0] >> pos[1];
	//for (int i = 0; i<5; i++) {
	//	string s; cin >> s;
	//	board.push_back(s);
	//}
	//next_move(pos[0], pos[1], board);
	next_move(1, 1, { "-----", "-m---", "-d---", "-----", "-----" });
	next_move(1, 1, { "-----", "-m-d-", "-----", "-----", "-----" });
	next_move(1, 1, { "-----", "-d---", "-----", "-----", "-----" });
	getchar();
	return 0;
}