#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int amax = 0;
		int i = 0;
		int j = height.size() - 1;
		while (i<j) {
			int area = 0;
			if (height[i] * height[j]>0) {
				if (height[i]<0) {
					height[i] = -height[i];
					height[j] = -height[j];
				}
				if (height[i]<height[j]) {
					area = (j - i)*height[i];
					i++;
				}
				else {
					area = (j - i)*height[j];
					j--;
				}
				if (area>amax) {
					amax = area;
				}
			}
		}
		return amax;
	}
};

int main() {
	vector <int> v = { 1,1 };
	Solution s;
	cout<<"MAX area : "<<s.maxArea(v)<<endl;
}