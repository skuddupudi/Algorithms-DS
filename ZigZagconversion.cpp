#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		vector<char> *v;
		string str = "";
		v = new vector<char>[numRows];
		if (!s.empty()) {
			v[0].push_back(s.at(0));
			for (int i = 1; i < s.size(); i++) {
				int r = i % (numRows - 1);
				int q = i / (numRows - 1);
				if (r == 0) {
					q = q - 1;
					r = numRows - 1;
				}
				if (q % 2 == 0) {
					v[r].push_back(s.at(i));
				}
				else {
					v[numRows - r - 1].push_back(s.at(i));
				}
			}
			for (int i = 0; i < numRows; i++) {
				for (int j = 0; j < v[i].size(); j++) {
					str += v[i][j];
				}
			}
		}
		return str;
	}
};

int main() {
	Solution s;
	cout<<"Converting (\"PAYPALISHIRING\", 3) : "<<s.convert("PAYPALISHIRING", 3)<<endl;
}