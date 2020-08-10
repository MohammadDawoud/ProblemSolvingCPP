//============================================================================
// Name        : LinkedListCycle.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
142. Linked List Cycle II

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.



Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.



*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode *detectCycle(ListNode *head) {
	ListNode* slow = head;
	ListNode* fast = head;

	 do {
		 if(fast != NULL)
			 fast = fast->next;
		if(fast != NULL) {
			fast = fast->next;
			slow = slow->next;
		}
	} while(fast != NULL && fast != slow) ;

	if(fast == NULL)
		return NULL;

	// fast == slow
	// set slow to head and move both one step at a time until they meet.

	slow = head;
	while(fast!= slow) {
		slow =  slow-> next;
		fast = fast->next;
	}
	return slow;
}

int main() {
//[3,2,0,-4]
//	1
	ListNode *head = new ListNode(3);
	head->next = new ListNode(2);
	head->next->next = new ListNode(0);
	head->next->next->next = new ListNode(-4);
	head->next->next->next->next = head->next;

	ListNode* cycle = detectCycle (head);
	cout<< cycle->val;
	return 0;
}
