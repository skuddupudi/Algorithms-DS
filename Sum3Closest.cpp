#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public :
	int threeSumClosest(vector<int>& nums, int res) {
		if (nums.size() > 3) {
			sort(nums.begin(), nums.end());
			int sum = nums[0] + nums[2] + nums[3];
			int mindiff = abs(sum - res);
			for (int i = 0; i < nums.size() - 2; i++) {
				int j = i + 1;
				int k = nums.size() - 1;
				while (j < k) {
					int diff = abs(nums[i] + nums[j] + nums[k] - res);
					if (diff == 0) {
						return res;
					}
					if (diff < mindiff) {
						sum = nums[i] + nums[j] + nums[k];
						mindiff = diff;
						if (nums[i] + nums[j] + nums[k]>res) {
							k--;
						}
						else j++;
					}
					else if (nums[i] + nums[j] + nums[k]>res) {
						k--;
					}
					else
						j++;
				}
			}
			return sum;
		}
		else {
			int sum = 0;
			for (int i = 0; i < nums.size(); i++) {
				sum = sum + nums[0];
			}
			return sum;
		}
	}
};

int main() {
	int res = 82;
	vector<int> v = { 1,2,4,8,16,32,64,128};
	Solution s;
	cout<<"The closest sum is : "<<s.threeSumClosest(v, res)<<endl;
}