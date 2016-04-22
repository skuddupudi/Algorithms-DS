#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int>A, vector<int> B) {
	if (A.size() == 0 || B.size() == 0)
		return -1;
	map<int, int> Amap;
	for (int i = 0; i < A.size(); i++) {
		if (Amap.find(A[i]) == Amap.end()) {
			Amap[A[i]] = 1;
		}
		else
			Amap[A[i]]++;
	}
	int min = -1;
	for (int i = 0; i < B.size(); i++) {
		if (Amap.find(B[i]) != Amap.end()) {
			if (min == -1 || min > B[i]) {
				min = B[i];
			}
		}
	}
	return min;
	/*sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int i = 0;
	int j = 0;
	while (i < A.size() && j < B.size()) {
		if (A[i] < B[j]) {
			i++;
		}
		else if (A[i] > B[j]) {
			j++;
		}
		else {
			return(A[i]);
		}
	}
	return -1;*/
}

int main() {
	vector<int> A = {1,3,2,1};
	vector<int> B = {4,2,5,3,2};
	cout << solution(A, B) << endl;
}