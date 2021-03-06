//============================================================================
// Name        : IntersectionofTwoLinkedL.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * 160. Intersection of Two Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

begin to intersect at node c1.

Example 1:


Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
 */

#include <iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

int getLength(ListNode *head) {
	int count = 0;
	while (head != NULL) {
		head = head->next;
		count ++;
	}
	return count;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
 // get the length  of A and B
	int lengthA = getLength(headA);
	int lengthB = getLength(headB);



	while(lengthA > lengthB) {
		headA = headA->next;
		lengthA--;
	}

	while(lengthB > lengthA) {
		headB = headB->next;
		lengthB--;
	}


	while(headA != NULL && headB != NULL && headA != headB) {
		headA = headA->next;
		headB = headB->next;
	}

	return headA;

}

int main() {
	cout << "" << endl; // prints 
	return 0;
}
