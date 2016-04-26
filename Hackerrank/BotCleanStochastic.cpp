#include<iostream>
#include<vector>
#include<string>
using namespace std;

void nextMove(int posr, int posc, vector <string> board) {
	if (board[posr][posc] == 'd'){
		cout << "CLEAN" << endl;
		return;
	}

	int dx, dy;
	for (int i = 0; i < 5; ++i){
		const auto &b = board[i];
		dy = b.find('d');
		if (dy != string::npos){
			dx = i; 
			break;
		}
	}
	if (posr < dx)
		cout << "DOWN" << endl;
	else if (posr > dx)
		cout << "UP" << endl;
	else if (posc < dy)
		cout << "RIGHT" << endl;
	else if (posc > dy)
		cout << "LEFT" << endl;
}

int main4(void) {
	int pos[2];
	vector <string> board;
	cin >> pos[0] >> pos[1];
	for (int i = 0; i<5; i++) {
		string s;
		cin >> s;
		board.push_back(s);
	}
	nextMove(pos[0], pos[1], board);
	return 0;
}
