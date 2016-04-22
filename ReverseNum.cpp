#include <iostream>
using namespace std;


class Solution {
public:
	int reverse(int x) {
		//int max = 134217728;
		double num = 0;
		bool isNeg = false;
		if (x<0) {
			isNeg = true;
			x = 0 - x;
		}
		while (x>0) {
			
			int r = x % 10;
			num = num * 10 + r;
			x /= 10;
		}
		if (num != (int)num)
			return 0;
		if (isNeg)
			num = 0 - num;
		return num;
	}
};

int main() {
	Solution s;
	cout << "Reversing "<< (int)-2147483412 <<" : "<< s.reverse(-2147483412) << endl;
}