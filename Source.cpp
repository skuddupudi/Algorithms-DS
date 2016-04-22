#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <thread>
#include <conio.h>
#include <fstream>

using namespace std;

float GetMedianVal(vector<int> v1, vector<int> v2, int L1, int R1, int L2, int R2, int targetpos, bool isEven);

float getmedian(vector<int> v1, vector<int> v2) {
	//Get the midian position
	int med = 0;
	if ((v1.size() + v2.size()) % 2 == 1) {
		int pos = (v1.size() + v2.size()) / 2;
		return GetMedianVal(v1, v2, 0, v1.size(), 0, v2.size(), pos, false);
	}
	else {
		int pos = (v1.size() + v2.size()) / 2 + 1;
		return GetMedianVal(v1, v2, 0, v1.size(), 0, v2.size(), pos, true);
	}
}


float GetMedianVal(vector<int> v1, vector<int> v2, int L1, int R1, int L2, int R2, int targetpos, bool isEven){
	float result = 0;
	if(L1==R1-1){
		if(v2[L2+targetpos-1]>v1[L1]){
			result = (float)v2[L2+targetpos-1];
			if(isEven){
				int res = (v2[L2+targetpos-2]>v1[L1])?v2[L2+targetpos-2] : v1[L1];
				result = (result + res)/2;
			}
		}else if(v2[L2+targetpos-1]<v1[L1]){
			result = (float)v1[L1];
			if(isEven){
				result = (result + v2[L2+targetpos-1])/2;
			}
		}
		else
			result = (float)v1[L1];
		return result;
	}
	if(L2==R2-1){
		if(v1[L1+targetpos-1]>v2[L2]){
			result = (float)v1[L1+targetpos-1];
			if(isEven){
				int res = (v1[L1+targetpos-2]>v2[L2])?v1[L1+targetpos-2] : v2[L2];
				result = (result + res)/2;
			}
		}else if(v1[L1+targetpos-1]<v2[L2]){
			result = (float)v1[L1];
			if(isEven){
				result = (result + v2[L2+targetpos-1])/2;
			}
		}
		else
			result = (float)v2[L2];
		return result;
	}
	
	int PosToCheck1 = L1 + targetpos/2;
	int PosToCheck2 = L2 + targetpos - targetpos/2;
	int originalTarget = L1+L2+ targetpos;
	if(targetpos > (R1+R2)-(L1+L2)){
		cout<<"THis should never happen..."<<endl;
		exit(0);
	}
	if(PosToCheck1 > R1){
		PosToCheck2 += PosToCheck1 - R1;
		PosToCheck1 = R1;
	}
	if(PosToCheck2 > R2){
		PosToCheck1 += PosToCheck2 - R2;
		PosToCheck2 = R2;
	}

	if(targetpos == 1){
		if(isEven)
			result = (float)(v1[L1]+v2[L2])/2;
		result = (v1[L1]>v2[L2])? (float)v1[L1]: (float)v2[L2];
		return result;
	}

	if(v1[PosToCheck1-1]>v2[PosToCheck2-1]){
		return GetMedianVal(v1, v2, L1, PosToCheck1, PosToCheck2, R2, (originalTarget - PosToCheck2), isEven);

	}
	else if(v1[PosToCheck1-1]<v2[PosToCheck2-1]){
		return GetMedianVal(v1, v2, PosToCheck1, R2, L2, PosToCheck2, (originalTarget - PosToCheck1), isEven);
	}
	else return (float)v1[PosToCheck1];
}



int main() {
	vector<int> v1 = { 1,2 };
	vector<int> v2 = { 3,4,5 }; 
	cout << "The median of v1 and v2 is : "<<getmedian(v1,v2) << endl; 
}