#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int k;
	cin >> k;
	int *h = new int[k];
	for (int i = 0; i< k; i++) {
		cin >> h[i];
	}
	long *a = new long[k];
	int amax = 0;
	for (int i = 0; i<k; i++) {
		a[i] = 0;
		int hmin = h[i];
		for (int j = i; j >= 0; j++) {
			if (h[j]<hmin) {
				hmin = h[j];
			}
			long area = hmin * (i - j + 1);
			if (a[i]<area) {
				a[i] = area;
			}
		}
		if (amax < a[i]) {
			amax = a[i];
		}
	}
	cout << amax << endl;
	return 0;
}
