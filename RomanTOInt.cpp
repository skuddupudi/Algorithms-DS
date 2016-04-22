#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int num = 0;

		for (int i = s.size()-1; i >= 0; i--) {
			char ch = s.at(i);
			ch = toupper(ch);
			switch (ch) {
			case 'I':
				if (num<3) {
					num = num + 1;
				}
				else if ((num == 5) || (num == 10)) {
					num = num - 1;
				}
				else {
					return 0;
				}
				break;
			case 'V':
				if (num<4) {
					num += 5;
				}
				break;
			case 'X':
				if (num<30) {
					num += 10;
				}
				else if (((num>49) && (num<60)) || ((num>99) && (num<110))) {
					num -= 10;
				}
				else {
					return 0;
				}
				break;
			case 'L':
				if (num<40) {
					num += 50;
				}
				break;
			case 'C':
				if (num<300) {
					num += 100;
				}
				else if (((num>499) && (num<600)) || ((num>999) && (num<1100))) {
					num -= 100;
				}
				else {
					return 0;
				}
				break;
			case 'D':
				if (num<400) {
					num += 500;
				}
				break;
			case 'M':
				if (num<3000) {
					num += 1000;
				}
				else {
					return 0;
				}
				break;
			}
		}
		return num;
	}
};

int main() {
	Solution s;
	cout << "VIII : " << s.romanToInt("VIII") << endl;
	cout << "DCXXI : " << s.romanToInt("DCXXI") << endl;
	cout << "IDCXXI : " << s.romanToInt("IDCXXI") << endl;
}