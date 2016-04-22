#include <iostream>
#include <vector>
using namespace std;


int sortPage(vector<int> &page, int lower, int upper);

int MultiwayMergeSort(vector<vector<int>> &A, int lower, int upper, int order) {
	if (lower == upper) {
		sortPage(A[lower], 0, A[lower].size() - 1);
		return 0;
	}
	int ilower = lower;
	int diff = (upper - lower+1) / order;
	if ((diff != 0) && ((upper - lower+1) % order != 0)) {
		diff++;
	}
	if (diff == 0)
		diff++;
	vector<vector<vector<int>>> pagesTobeSorted;
	while (ilower <= upper) {
		int iupper = 0;
		if ((ilower + diff -1) > upper)
			iupper = upper;
		else
			iupper = ilower + diff-1;

		MultiwayMergeSort(A, ilower, iupper, order);
		vector<vector<int>> currSortedBlock;
		for (int i = ilower; i <= iupper; i++) {
			currSortedBlock.push_back(A[i]);
		}
		pagesTobeSorted.push_back(currSortedBlock);
		
		ilower += diff;
	}
	vector<int> Curres;
	Curres.resize(A[lower].size());
	int walker = 0;
	int *bLockRefs = new int[pagesTobeSorted.size()];
	int *pageRefs = new int[pagesTobeSorted.size()];
	for (int i = 0; i < pagesTobeSorted.size(); i++) {
		bLockRefs[i] = 0;
		pageRefs[i] = 0;
	}
	vector<vector<int>>memBlock;
	for (int i = 0; i < pagesTobeSorted.size(); i++) {
		memBlock.push_back(pagesTobeSorted[i][0]);
	}
	int walker2 = lower;
	int minRef = 0;
	while (walker2 <= upper) {
		for (int i = 0; i < memBlock.size(); i++) {
			if (bLockRefs[i] < pagesTobeSorted[i].size()) {
				minRef = i;
				break;
			}
		}
		for (int i = 0; i < memBlock.size(); i++) {
			if (bLockRefs[i] < pagesTobeSorted[i].size()) {
				if (memBlock[i][pageRefs[i]] < memBlock[minRef][pageRefs[minRef]]) {
					minRef = i;
				}
			}
			
		}
		Curres[walker] = memBlock[minRef][pageRefs[minRef]];
		walker++;
		pageRefs[minRef]++;
		if (pageRefs[minRef] == memBlock[minRef].size()) {
			bLockRefs[minRef]++;
			if (bLockRefs[minRef] < pagesTobeSorted[minRef].size()) {
				memBlock[minRef] = pagesTobeSorted[minRef][bLockRefs[minRef]];
				pageRefs[minRef] = 0;
			}
				
		}
		if (walker == Curres.size()) {
			A[walker2] = Curres;
			walker2++;
			walker = 0;
		}
	}

	return 0;
}



int sortPage(vector<int> &page, int lower, int upper) {
	if (lower == upper) {
		return 0;
	}

	int mid = (lower + upper) / 2;
	sortPage(page, lower, mid);
	sortPage(page, mid + 1, upper);
	vector<int> left;
	vector<int> right;
	for (int a = lower; a <= mid; a++) {
		left.push_back(page[a]);
	}
	for (int a = mid + 1; a <= upper; a++) {
		right.push_back(page[a]);
	}
	//right.assign(page.at(mid + 1), page.at(upper));
	int x = lower;
	int i = 0;
	int j = 0;
	while (x <= upper) {
		if (i < left.size() && j < right.size()) {
			if (left[i] > right[j]) {
				page[x] = right[j];
				j++;
			}
			else {
				page[x] = left[i];
				i++;
			}
		}
		else if (i < left.size()) {
			page[x] = left[i];
			i++;
		}
		else if (j < right.size()) {
			page[x] = right[j];
			j++;
		}
		x++;
	}
	return 0;
}





int main() {
	int m, n, memPagesAvailable;
	cout << "Enter page size : ";
	cin >> m;
	cout << "Enter no of pages to be sorted : ";
	cin >> n;
	vector<vector <int>> A;
	A.resize(n);
	cout << "Random generated numbers are : " << endl;
	for (int i = 0; i < n; i++) {
		A[i].resize(m);
		for (int j = 0; j < m; j++) {
			A[i][j] = rand() % 5000;
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Enter the number of pages available in memory : ";
	cin >> memPagesAvailable;
	MultiwayMergeSort(A, 0, A.size() - 1, memPagesAvailable-1);
	cout << "After sorting numbers in "<< memPagesAvailable -1<<" way sort : " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}