#include <iostream>

using namespace std;

template <typedef T> class Node {
	int degree;
	int *subTreeIndexes;
	T* elem;
	Node *subtrees;
public :
	Node(int deg) {
		this->degree = deg;
		elem = new T[deg - 1];
		subTreeIndexes = new int[deg];
		subtrees = new Node[deg];
	}
	
};

template <typedef T>class BTree{

	void Insert(T elem) {

	}
	T Delete() {

	}
	BTree() {
		
	}
};

int main() {

}