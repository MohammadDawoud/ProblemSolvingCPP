//============================================================================
// Name        : ReverseLinkedListII.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 92. Reverse Linked List II

Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
 */

#include <iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* reverseBetween(ListNode* head, int m, int n) {
	ListNode *beforeReverse = NULL;
	ListNode *subHead = NULL;
	ListNode *subTail = NULL;
	ListNode *afterReverse = NULL;
	ListNode *previous = NULL;
	ListNode *next = NULL;

	ListNode *node = head;


	if(m==n) {
		return head;
	}

	int i= 1;
	while(node != NULL) {
		if(i == m-1) {
			beforeReverse = node;
		}
		if(i == m) {
			subTail = node;
		}

		if(i == n+1) {
			afterReverse = node;
		}

		if(i == n) {
			subHead = node;
		}

		next = node->next;

		if(i >= m && i <= n) {
			node->next = previous;

		}
		previous =  node;
		node = next;

		i++;

	}

    if(beforeReverse != NULL) {
        beforeReverse->next = subHead;
    } else {
        head = subHead;
    }

	subTail->next = afterReverse;

	return head;
}

int main() {

/*
	ListNode *head = new ListNode(1);
	ListNode *tmp = new ListNode(2);
	head->next=tmp;

	tmp->next =  new ListNode(3);
	tmp->next->next =  new ListNode(4);
	tmp->next->next->next =  new ListNode(5);

	reverseBetween(head, 5,5);
*/

	ListNode *head =  new ListNode(3);
	head->next =  new ListNode(5);

	reverseBetween(head, 1,2);

	return 0;
}
