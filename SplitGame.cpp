#include<iostream>
#include<vector>
#include<string>

using namespace std;


string solution(vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	string ans = "NO SOLUTION";
	bool isSumSet = false;
	int sum = 0;
	int l = 0;
	int r = 0;
	for (int i = 0; i< A.size(); i++) {
		if (A[i] % 2 == 1 && i<A.size() - 1) {
			if (A[i + 1] % 2 == 1) {
				if (!isSumSet) {
					sum = A[i] + A[i + 1];
					l = i;
					r = i + 1;
					isSumSet = true;
				}
				else {
					if (A[i] + A[i + 1]<sum) {
						sum = A[i] + A[i + 1];
						l = i;
						r = i + 1;
					}
				}
				
			}
		}
		else if (i<A.size() - 1) {
			if (A[i + 1] % 2 == 0) {
				if (!isSumSet) {
					sum = A[i] + A[i + 1];
					l = i;
					r = i + 1;
					isSumSet = true;
				}
				else {
					if (A[i] + A[i + 1]<sum) {
						sum = A[i] + A[i + 1];
						l = i;
						r = i + 1;
					}
				}
			}
		}
	}
	if (l != 0 || r != 0) {
		ans = "";
		ans += l;
		ans += ",";
		ans += r;
	}
		
	return ans;
}

int main() {
	vector<int> A = { 4, 5, 3, 7, 2 };
	cout << solution(A);
}