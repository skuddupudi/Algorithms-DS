#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct MyListNode {
	int val;
	MyListNode* next;
	MyListNode* prev;
	MyListNode() {
		val = 0;
		prev = NULL;
		next = NULL;
	}
};
class MyStack{
	MyListNode *tos;
	MyListNode *bottom;
	int count; 
	MyListNode* Iter;

public :
	MyStack() {
		bottom = NULL;
		tos = NULL;
		count =  0;
	}
	void push(int num) {
		MyListNode *newNode = new MyListNode();
		newNode->val = num;
		if (count == 0) {
			bottom = newNode;
		}
		else {
			newNode->next = tos;
			tos->prev = newNode;
		}
		tos = newNode;
		count++;
		print();
		
	}

	int pop() {
		MyListNode *cur = tos;
		tos = tos->next;
		if (count == 0) {
			cout << "STACK EMPTY" << endl;
			return 0;
		}
		else if (count == 1) {
			bottom=NULL;
		}
		else
			tos->prev = NULL;
		cur->next = NULL;
		count--;
		print();
		return cur->val;
	}
	void print() {
		if (count == 0) {
			cout << "EMPTY" << endl;
		}
		else {
			cout << tos->val << endl;
		}
	}

	void inc(int d, int n) {
		MyListNode *cur = bottom;
		Iter = bottom;

		for (int i = 0; i < d; i++) {
			if (i == count) {
				break;
			}
			Iter->val += n;
			cur = Iter->prev;
			Iter = cur;
		}
		print();
	}
	
};

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	cin >> n;
	string s;
	cout << "";
	 
	MyStack m;
		for (int i = 0; i<n; i++) {
			string in;
			cin >> in;
			if (in.compare("push")==0) {
				int num;
				cin >> num;
				m.push(num);
			}
			else if (in.compare("pop")==0) {
				m.pop();
			}
			else if (in.find("inc")==0) {
				int d, n;
				cin >> d >> n;
				m.inc(d,n);
			}
			
		}
	return 0;
}