#include <iostream>
#include <string>
#include <vector>

using namespace std;

string LCS(string s1, string s2) {
	const int m = s1.size();
	const int n = s2.size();

	int **R;
	R = new int *[m + 1];
	for (int i = 0; i <= m ; i++) {
		R[i] = new int[n + 1];
		for (int j = 0; j <= n; j++) {
			R[i][j] = 0;
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s1.at(i-1) == s2.at(j-1))
				R[i][j] = R[i - 1][j - 1] + 1;
			else if (R[i - 1][j] >= R[i][j - 1])
				R[i][j] = R[i - 1][j];
			else
				R[i][j] = R[i][j - 1];
		}
	}
	string str = "";
	int i = m;
	int j = n;
	while ((i > 0) && (j > 0)) {
		if (s1.at(i-1) == s2.at(j-1)) {
			str += s1.at(i - 1);
			i--;
			j--;
		}
		else if (R[i - 1][j] >= R[i][j - 1]) {
			i--;
		}
		else
			j--;
	}
	
	
	return str;
}

string LongestPalindrome(string &s1);
int funPal(string s) {
	string pal1 = LongestPalindrome(s);
	string pal2 = LongestPalindrome(s);
	cout << pal1 << endl;

	cout << pal2 << endl;
	int res = pal1.length()*pal2.length();
	int res2 = 0;

	if (pal1.length() % 2 == 1) {
		res2 = (pal1.length() / 2)*(pal1.length() / 2 + 1);
	}
	else {
		res2 = (pal1.length() / 2)*(pal1.length() / 2);
	}
	if (res2>res)
		return res2;
	else return res;
}


string LongestPalindrome(string &s1) {
	string s2 = string(s1.rbegin(), s1.rend());
	int m = s1.size();
	int n = s2.size();

	int **R;
	R = new int *[m + 1];
	for (int i = 0; i <= m; i++) {
		R[i] = new int[n + 1];
		for (int j = 0; j <= n; j++) {
			R[i][j] = 0;
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s1.at(i - 1) == s2.at(j - 1))
				R[i][j] = R[i - 1][j - 1] + 1;
			else if (R[i - 1][j] >= R[i][j - 1])
				R[i][j] = R[i - 1][j];
			else
				R[i][j] = R[i][j - 1];
		}
	}
	string str = "";
	string str2 = "";
	int i = m;
	int j = n;
	while ((i > 0) && (j > 0)) {
		if (s1.at(i - 1) == s2.at(j - 1)) {
			str += s1.at(i - 1);
			i--;
			j--;
		}
		else if (R[i - 1][j] >= R[i][j - 1]) {
			i--;
		}
		else {
			j--;
		}

	}
	int x = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == str[j]) {
			j++;
		}
		else
			str2 += s1[i];
	}

	s1 = str2;
	return str;
}
int maxXor(int l, int r) {
	int x = l^r;
	int res = 0;
	while (x>0) {
		res <<=1;
		res++;
		x /= 2;
	}
	return res;
}

int main() {
	//string s1 = "acdapmpomp";
	//string s2 = string(s1.rbegin(),s1.rend());
	//cout << "Max palindrome : " << funPal(s1)<<" : "<<s1;
	//cout <<endl<< tolower(s1[0]) << endl;
	int res;
	int _l;
	cin >> _l;

	int _r;
	cin >> _r;

	res = maxXor(_l, _r);
	cout << res;

	return 0;
}