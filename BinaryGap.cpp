// you can use includes, for example:
// #include <algorithm>
#include <vector>
#include <iostream>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

using namespace std;

int solution(int N) {
	// write your code in C++11 (g++ 4.8.2)
	vector<int> gaps;
	bool encountered0 = false;
	bool encountered1 = false;
	int length = 0;
	while (N>0) {
		int i = N % 2;
		if ((i == 0) && encountered1) {
			length++;
			encountered0 = true;
		}
		else if (i == 1) {
			encountered1 = true;
			if (encountered0) {
				gaps.push_back(length);
				length = 0;
				encountered0 = false;
			}
		}
		N /= 2;
	}
	return gaps.size();
}

int main() {
	cout << solution(1041) << endl;
}