#include<iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
	vector <string> numLetters;
	vector<string> comb;
	int x;
public:
	Solution() {
		numLetters = { " ", "", "abc", "def", "ghi","jkl" ,"mno" ,"pqrs" ,"tuv","wxyz" };
		x = 0;
	}
	vector<string> letterCombinations(string digits) {
		numLetters.clear();
		if (x< digits.length()) {
			char ch = digits[x];
			string numStr = numLetters[ch - '0'];
			vector<string> newCombs;
			if (comb.size() == 0) {
				for (int i = 0; i < numStr.length(); i++) {
					string num = numStr.substr(i,1);
					comb.push_back(num);
				}
			}
			else {
				for (int i = 0; i < comb.size(); i++) {
					for (int j = 0; j < numStr.length(); j++) {
						newCombs.push_back(comb[i] + numStr[j]);
					}
				}

				comb = newCombs;
			}
			x++;
			return letterCombinations(digits);
		}
		else
			return comb;

	}
};

int main() {
	Solution s;
	vector<string> ans = s.letterCombinations("235");
	cout << "Solution : " << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}