#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
	vector<vector<int>> Soln;
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		Soln.clear();
		int m = 0;
		int n = nums.size() - 1;
		if (nums.size()>0) {
			getFourSum(nums, target, m, n);
			while (n - m > 2) {

			}
			return Soln;
		}
		else {
			return{};
		}
	}

	void getFourSum(vector<int> nums, int target, int m, int n) {
		int i = m + 1;
		int j = n - 1;
		cout << m << n << endl;
		if ((n - m)>2) {
			while(i<j) {
				int sum = nums[m] + nums[i] + nums[j] + nums[n];
				if (sum > target) {
					j--;
				}
				else if (sum<target) {
					i++;
				}
				else {
					Soln.push_back({ nums[m], nums[i], nums[j], nums[n] });
					i++;
					j--;
				}
			}
			
			getFourSum(nums, target, m+1, n);
			
			getFourSum(nums, target, m, n-1);
		}
		
	}
};

int main() {
	Solution s;
	vector<int> nums = { 1, 0, -1, 0, -2, 2 };
	vector<vector<int>>ans = s.fourSum(nums, 0);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << " " << ans[i][j]<<" ";
		}
		cout << endl;
	}

}