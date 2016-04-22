#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <iterator>
#include <sys/types.h>
#include <cctype>
using namespace std;



class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> charPos;
		int i = 0;
		if (s.length() == 0)
			return 0;
		int imax = 0, jmax = 0;
		int max_diff = jmax - imax +1;
		pair<char, int> p(s.at(0), 0);
		charPos.insert(p);
		for (int ictr = 1; ictr < s.length(); ictr++) {
			char ch = s.at(ictr);
			
			map<char, int>::iterator it = charPos.find(ch);
			if (it == charPos.end()) {
				int diff = ictr - i + 1;
				charPos[s.at(ictr)] = ictr;
				if (diff > max_diff) {
					imax = i;
					jmax = ictr;
					max_diff = jmax - imax + 1;
				}
			}
			else {
				int iprev = i;
				i = it->second + 1;
				for (int a = iprev; a < i; a++) {
					charPos.erase(s.at(a));
				}
				charPos[s.at(ictr)] = ictr;
			}

		}
		return max_diff;
	}

};



int main() {
	 
	Solution s;
	cout<<"Max length of non rep substring : ejtdfngsdnnkgpkvtigsq : "<<s.lengthOfLongestSubstring("ejtdfngsdnnkgpkvtigsq");
	
}
//(2 -> 4 -> 3) + (5 -> 6 -> 4)