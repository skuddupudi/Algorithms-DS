#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Solution {
public :
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) {
			return "";
		}
		else {
			string pref = strs[0];
			for (int i = 1; i < strs.size(); i++) {
				if (pref.length() > strs[i].length()) {
					string temp = strs[i];
					strs[i] = pref;
					pref = temp;
				}
				if (pref.length() == 0) {
					return "";
				}
				if (strs[i].find(pref) != 0) {
					for (int j = pref.length() - 1; j >= 0; j--) {
						pref = pref.substr(0, j);
						if (strs[i].find(pref) == 0) {
							break;
						}
					}
				}
			}
			return pref;
		}
	}
};

int main() {
	vector<string> inp = { "pref1", "pref2" };
	Solution s;
	cout<<"Longest common prefix : "<<s.longestCommonPrefix(inp) << endl;
}