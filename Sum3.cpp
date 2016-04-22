#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public :
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector <int>> res;

		vector<int> triplet;
		if (nums.size() >= 3) {
			sort(nums.begin(), nums.end());
			for (int i = 0; i < nums.size() - 2; i++) {
				int j = i + 1;
				int k = nums.size() - 1;
				if (nums[i] == nums[j] && nums[i] == 0) {
					continue;
				}
				while (j < k) {
					if (nums[i] + nums[j] + nums[k] == 0) {
						AddTriplet({ nums[i], nums[j], nums[k] }, res);
						k--;
					}
					else if (nums[i] + nums[j] + nums[k]>0) {
						k--;
					}
					else
					{
						j++;
					}
				}
			}
		}
		return res;
	}
private :
	void AddTriplet(vector<int> tri, vector<vector <int>>& res) {
		sort(tri.begin(), tri.end());
		bool ispresent = false;
		for (int i = 0; i < res.size(); i++) {
			if ((tri[0] == res[i][0]) && (tri[1] == res[i][1])) {
				ispresent = true;
				break;
			}
		}
		if (!ispresent)
			res.push_back(tri);
	}
	
};

int main() {
	vector<int> input = { 7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	Solution s;
	vector<vector<int>> result = s.threeSum(input);
	for (int i = 0; i < result.size(); i++) {
		cout << "{" << result[i][0] << ", " << result[i][1] << ", " << result[i][2] << "}" << endl;
	}
	
}