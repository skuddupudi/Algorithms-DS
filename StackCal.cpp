#include<stack>
#include <iostream>


#define MUL1(x,y) x*y
#define MUL2(x,y) (x*y)
#define MUL3(x,y) (x)*(y)

using namespace std;

class sNode {
public:
	int val;
	sNode *next;
	sNode(int v) {
		val = v;
		next = NULL;
	}
};

class MyStack {
	sNode *head;
	int count;
public :
	MyStack() {
		count = 0;
		head = NULL;
	}
	void push(int i) {
		sNode *newNode = new sNode(i);
		if (head != NULL) {
			newNode->next = head;
			head = newNode;
			count++;
		}
		else {
			head = newNode;
			count++;
		}
	}
	int pop() {
		if (count > 0) {
			
			sNode* curNode = head;
			head = head->next;
			curNode->next = NULL;
			count--;
			return curNode->val;
		}
		else {
			return -1;
		}
	}
};

int Solution(string &s) {
	int res = -1;
	MyStack stck;
	for (int i = 0; i < s.length(); i++) {
		if (s[i]<='9' && s[i]>='0') {
			stck.push(s[i] - '0');
		}
		else {
			if (s[i] == '+') {
				int x = stck.pop();
				int y = stck.pop();
				if (x == -1 || y == -1) {
					return -1;
				}
				else {
					int res = x + y;
					stck.push(res);
				}
			}else if (s[i] == '*') {
				int x = stck.pop();
				int y = stck.pop();
				if (x == -1 || y == -1) {
					return -1;
				}
				else {
					int res = x * y;
					stck.push(res);
				}
			}
		}
	}
	return stck.pop();
}


int main() {
	string str = "13+62*7+*";
	//cout << Solution(str);
	int x = 10;
	cout << "MUL1 : " << MUL1(x - 1, x + 2) <<endl;
	cout << "MUL2 : " << MUL2(x - 1, x + 2) << endl;
	cout << "MUL3 : " << MUL3(x - 1, x + 2) << endl;
	cin >> x;
}