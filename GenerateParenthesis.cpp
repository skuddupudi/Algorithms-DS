#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> soln;
		for (int i = 0; i< n; i++) {
			string str = "";
			string strl = "";
			string strr = "";
			for (int x = 0; x <= i; x++) {
				strl = strl + "(";
			}
			for (int x = 0; x <= i; x++) {
				strr = strr + ")";
			}
			if (i < n - 1) {
				vector<string> soln1 = generateParenthesis(n - (i+1));
				if (soln1.size()>0) {
					for (string str1 : soln1) {
						str = strl + str1 + strr;
						soln.push_back(str);
						str = strl + strr + str1;
						soln.push_back(str);
					}
				}
			}
			else {
				soln.push_back(strl+strr);
			}

		}
		return soln;
	}
};

int main() {
	Solution s;
	vector<string> sol = s.generateParenthesis(8);
	for (string str : sol) {
		cout << str << endl;
	}
}