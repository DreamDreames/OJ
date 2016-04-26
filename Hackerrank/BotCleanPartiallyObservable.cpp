#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;
namespace BotCleanPartiallyObservable{
	void next_move(int posr, int posc, vector <string> board) {
		if (board[posr][posc] == 'd'){
			cout << "CLEAN" << endl;
			return;
		}
		int r = board.size(), c = board[0].length(), minstep = 100000, minx = -1, miny = -1;
		for (int i = 0; i < r; ++i){
			const auto& b = board[i];
			for (int j = 0; j < c; ++j){
				if (b[j] == 'd'){
					int step = abs(posr - i) + abs(posc - j);
					if (step < minstep){
						minx = i; miny = j;
					}
				}
			}
		}
		if (minx == -1){
			int left = posc, right = c - posc, top = posr, bottom = r - posr;
			string move;
			if (left <= 1){
				if (top <= 1)
					move = "RIGHT";
				else
					move = "UP";
			}
			else{
				if (right <= 1){
					if (bottom <= 1)
						move = "LEFT";
					else
						move = "DOWN";
				}
				else{
					if (bottom <= 1){
						if (left <= 1)
							move = "UP";
						else
							move = "LEFT";
					}
					else{
						if (top <= 1){
							if (right <= 1)
								move = "DOWN";
							else
								move = "RIGHT";
						}
						else
							move = "UP";
					}
				}
			}
			cout << move << endl;
			return;
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
}
int main6(void) {
	int pos[2];
	vector <string> board;
	cin >> pos[0] >> pos[1];
	for (int i = 0; i < 5; i++) {
		string s; cin >> s;
		board.push_back(s);
	}
	BotCleanPartiallyObservable::next_move(pos[0], pos[1], board);
	return 0;
}