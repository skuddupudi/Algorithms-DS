#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public :
	int lonelyInteger(vector < int > arr) {
		map<int, int> intMap;
		for (int i = 0; i < arr.size(); i++) {
			if (intMap.find(arr[i]) == intMap.end()) {
				intMap[arr[i]] = 1;
			}
			else {
				intMap[arr[i]]++;
			}
		}
		map<int, int>::iterator iter;
		for (iter = intMap.begin(); iter != intMap.end(); iter++) {
			if ((iter->second % 2) == 1)
				return iter->first;
		}
	}
};