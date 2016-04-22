/**
* Definition for singly-linked list.*/
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *res = NULL;
		ListNode *curNode = NULL;
		int count = 0;
		while (l1 != NULL || l2 != NULL) {
			if (l1 == NULL) {
				if (count == 0) {
					curNode = new ListNode(l2->val);
					count++;
					res = curNode;
					l2 = l2->next;
				}
				else {
					curNode->next = new ListNode(l2->val);
					curNode = curNode->next;
					l2 = l2->next;
				}
			}
			else if (l2 == NULL) {
				if (count == 0) {
					curNode = new ListNode(l1->val);
					count++;
					res = curNode;
					l1 = l1->next;
				}
				else {
					curNode->next = new ListNode(l1->val);
					curNode = curNode->next;
					l1 = l1->next;
				}
			}
			else {
				if (l1->val <= l2->val) {
					if (count == 0) {
						curNode = new ListNode(l1->val);
						count++;
						res = curNode;
						l1 = l1->next;
					}
					else {
						curNode->next = new ListNode(l1->val);
						curNode = curNode->next;
						l1 = l1->next;
					}
				}
				else {
					if (count == 0) {
						curNode = new ListNode(l2->val);
						count++;
						res = curNode;
						l2 = l2->next;
					}
					else {
						curNode->next = new ListNode(l2->val);
						curNode = curNode->next;
						l2 = l2->next;
					}
				}
			}
		}
		return res;
	}
};

int main() {
	ListNode *l1 = NULL;
	ListNode *l2 = new ListNode(0);
	Solution s;
	ListNode *res = s.mergeTwoLists(l1, l2);
	while (res != NULL) {
		cout << res->val;
		res = res->next;
	}
}