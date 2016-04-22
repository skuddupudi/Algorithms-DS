#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		int digitsp = 1;
		string res = "";
		while (num > 0) {
			int dig = num % 10;
			if (dig>0) {
				string curNum = "";
				switch (digitsp) {
				case 1:
					if (dig<4) {
						for (int i = 0; i<dig; i++) {
							curNum = curNum + "I";
						}
					}
					else if (dig == 4)
						curNum = "IV";
					else if (dig<9) {
						curNum = "V";
						dig = dig - 5;
						for (int i = 0; i< dig; i++)
							curNum = curNum + "I";
					}
					else if (dig == 9) {
						curNum = "IX";
					}
					break;
				case 10:
					if (dig<4) {
						for (int i = 0; i<dig; i++) {
							curNum = curNum + "X";
						}
					}
					else if (dig == 4)
						curNum = "XL";
					else if (dig<9) {
						curNum = "L";
						dig = dig - 5;
						for (int i = 0; i< dig; i++)
							curNum = curNum + "X";
					}
					else if (dig == 9) {
						curNum = "XC";
					}
					break;
				case 100:
					if (dig<4) {
						for (int i = 0; i<dig; i++) {
							curNum = curNum + "C";
						}
					}
					else if (dig == 4)
						curNum = "CD";
					else if (dig<9) {
						curNum = "D";
						dig = dig - 5;
						for (int i = 0; i< dig; i++)
							curNum = curNum + "C";
					}
					else if (dig == 9) {
						curNum = "CM";
					}
					break;
				case 1000:
					if (dig<4) {
						for (int i = 0; i<dig; i++) {
							curNum = curNum + "M";
						}
					}
					break;
				}
				res = curNum + res;
			}
			digitsp *= 10;
			num = num / 10;
		}
		return res;
	}
};

int main() {
	int x;
	Solution s;
	cin >> x;
	cout<<s.intToRoman(x)<<endl;
}