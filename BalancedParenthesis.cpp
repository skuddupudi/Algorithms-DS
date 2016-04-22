#include<iostream>
#include <string>
using namespace std;

template <class T> class Node {
public:
	Node(T newVal) {
		value = newVal;
		next = NULL;
	}
	T value;
	Node *next;
};

template <class T> class MyStack {
	//int tos;
	int count;
	Node <T> *head;
public:
	MyStack() {
		//this->tos = top;
		count = 0;
		head = new Node<T>(0);
	}
	T pop() {
		if (count == 0) {
			cout << "Can't pop empty stack" << endl;
			return NULL;
		}
		else {
			Node<T> *curr = head;
			head = curr->next;
			curr->next = NULL;
			count--;
			return curr->value;
		}
	}

	void push(T val) {
		/*if(count==tos){
		cout<<"TOS reached, remove some items in the stack..."
		}
		else*/ {
			Node<T> *newNode = new Node<T>(val);
			newNode->next = head;
			head = newNode;
			count++;
		}

	}
	void removeAll() {
		while (count>0) {
			pop();
		}
	}
	T peek() {
		if (count > 0)
			return head->value;
		else
			return -1;
	}
	int getcount() {
		return count;
	}

	~MyStack() {
		removeAll();
	}
};

int main() {
	int trials;
	cin >> trials;
	for (int i = 0; i< trials; i++) {
		string str;
		cin >> str;
		MyStack <char> s;
		bool isterminated = true;
		for (int j = 0; j<str.length(); j++) {
			if ((str[j] == '(') || (str[j] == '{') || (str[j] == '[')) {
				s.push(str[j]);
			}
			else {
				char ch = s.peek();
				if (ch == '(')
					ch = ')';
				if (ch == '{')
					ch = '}';
				if (ch == '[')
					ch = ']';
				if (ch == str[j] && ch != -1) {
					s.pop();
				}
				else {
					isterminated = false;
					break;
				}
			}
		}
		if (isterminated && s.getcount() == 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}