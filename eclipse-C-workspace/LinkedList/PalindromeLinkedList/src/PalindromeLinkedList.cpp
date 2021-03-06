//============================================================================
// Name        : Palindrome Linked List.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
234. Palindrome Linked List

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
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

int getLength(ListNode *head) {
	int count = 0;
	while (head != NULL) {
		head = head->next;
		count ++;
	}
	return count;
}


ListNode* getMiddleNode(ListNode *head) {

	int length = getLength(head);
	int middle = 0;

	if(length%2 == 0)	{
		middle = length/2;
	}
	else
		middle = length/2+1;

	for(int i = 0; i < middle; i++) {
		head = head->next;
	}

	return head;
}

bool isPalindromeRec(ListNode** nodeSurfer, ListNode* otherSide) {
	if(otherSide == NULL)
		return true;


	bool result = isPalindromeRec(nodeSurfer,otherSide->next);
	((*nodeSurfer)->val == otherSide->val)?  : result=false ;
	*nodeSurfer = ((*nodeSurfer)->next);
	return result;

}
bool isPalindrome(ListNode* head) {
	ListNode *middle =  getMiddleNode(head);
	ListNode* nodeSurfer = head;
	bool result = isPalindromeRec(&nodeSurfer, middle);
	return result;
}

int main() {


	ListNode *head = new ListNode(1);
	ListNode *tmp = new ListNode(2);
	head->next=tmp;

	tmp->next =  new ListNode(3);
	tmp->next->next =  new ListNode(2);
	tmp->next->next->next =  new ListNode(1);

	isPalindrome(head);

	return 0;
}
