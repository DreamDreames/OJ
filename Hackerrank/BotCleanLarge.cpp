#include<iostream>
#include<vector>
#include<string>
using namespace std;
void next_move(int posr, int posc, int dimh, int dimw, vector <string> board) {
	if (board[posr][posc] == 'd'){
		cout << "CLEAN" << endl;
		return;
	}
	int minstep = 100000, minx, miny;
	for (int i = 0; i < dimh; ++i){
		const auto& b = board[i];
		for (int j = 0; j < dimw; ++j){
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

int main5(void) {
	int pos[2];
	int dim[2];
	vector <string> board;
	cin >> pos[0] >> pos[1];
	cin >> dim[0] >> dim[1];
	for (int i = 0; i<dim[0]; i++) {
		string s; cin >> s;
		board.push_back(s);
	}
	next_move(pos[0], pos[1], dim[0], dim[1], board);
	return 0;
}