#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
	int turn = 0;
	void changeturn() {
		if (turn == 0)
			turn++;
		else
			turn--;
	}
public:
	Solution() {
		turn = 0;
	}
	string GetWinnerOfGame(unsigned long long int num) {
		string s1 = "Louise";
		string s2 = "Richard";
		if (num>1) {
			bool istwopow = false;
			if(!istwopow)
				istwopow = isPowOfTwo(num);
			if (istwopow) {
				num = num>>1;
			}
			else {
				int ishift = 64 - (int)log2(num);
				num = num << ishift;
				num = num >> ishift;
			}
			changeturn();
			return GetWinnerOfGame(num);
		}
		if (turn == 1)
			return s1;
		else 
			return s2;
	}

	bool isPowOfTwo(long long int num) {
		bool ret = true;
		while (num > 1) {
			if ((num & 1)==1) {
				return false;
			}
			else {
				num = num >> 1;
			}
		}
		return ret;
	}

};


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int T;
	cin >> T;
	for (int i = 0; i< T; i++) {
		unsigned long long int game;
		cin >> game;
		Solution s;
		cout << s.GetWinnerOfGame(game).c_str() << endl;
	}
	return 0;
}
