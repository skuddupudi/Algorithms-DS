#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int num = 0;
		bool isNeg = false;
		str = MyTrim(str);
		for (int i = 0; i< str.size(); i++) {
			if ((str.at(i) == '-') && (i == 0)) {
				isNeg = true;
				continue;
			}
			else if ((str.at(i) == '+') && (i == 0)) {
				continue;
			}

			else if ((str.at(i) <= '9') && (str.at(i) >= '0')) {
				num = num * 10 + (str.at(i) - '0');
			}
			else {
				return 0;
			}
		}
		if (isNeg)
			num = 0 - num;
		return num;
	}
	string MyTrim(string str) {
		int rad = str.find(" ");
		while(rad>=0) {
			string s1 = str.substr(0, rad);
			string s2 = str.substr(rad + 1);
			str = s1 + s2;
			rad = str.find(" ");
		}
		return str;
	}
};

int main() {
	Solution s;
	cout << "My Ato I :    010" << " : " << s.myAtoi("    010") << endl;
}