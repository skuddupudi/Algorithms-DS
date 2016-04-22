
/**
* Definition for singly-linked list.*/
#define NULL 0

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *endNode = head;
		ListNode *removeNextNode = NULL;
		ListNode *nodeToBeRemoved = NULL;
		for (int i = 0; i< n; i++) {
			if (endNode == NULL) {
				return head;
			}
			else {
				endNode = endNode->next;

			}
		}

		removeNextNode = head;
		if (endNode == NULL) {
			head = removeNextNode->next;
			removeNextNode->next = NULL;
			removeNextNode = NULL;
			return head;
		}
		while (endNode->next != NULL) {
			endNode = endNode->next;
			removeNextNode = removeNextNode->next;
		}
		if (removeNextNode != NULL) {
			nodeToBeRemoved = removeNextNode->next;
			removeNextNode->next = nodeToBeRemoved->next;
			nodeToBeRemoved->next = NULL;
			removeNextNode = NULL;
		}
		if (head == NULL) {
			return NULL;
		}
		return head;
	}
};

int main() {
	ListNode* head = new ListNode(1);
	Solution s;
	s.removeNthFromEnd(head,1);
}