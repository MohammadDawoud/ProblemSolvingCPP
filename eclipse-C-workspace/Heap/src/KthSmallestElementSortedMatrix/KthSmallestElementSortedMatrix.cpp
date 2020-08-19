//============================================================================
// Name        : KthSmallestElementSortedMatrix.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
 */


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Comparator {
public:
	bool operator()(ListNode* a, ListNode* b) {
		return a->val > b->val;
	}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode *head = NULL;
    ListNode *tail = NULL;
    priority_queue<ListNode*, vector<ListNode*> , Comparator > minHeap ;


    for(auto node : lists) {
    	if(node != NULL) {
    		minHeap.push(node);
    	}
    }

    if(minHeap.empty() == false) {
        head = minHeap.top();
        tail = head;
        minHeap.pop();
    	if(tail->next != NULL) {
            minHeap.push(tail->next);
        }
    }
    while(minHeap.empty() == false) {
    	tail->next = minHeap.top();
        minHeap.pop();
    	tail = tail->next;
    	if(tail->next != NULL) {
    		minHeap.push(tail->next);
    	}
    }

    return head;

}


int main() {
	cout << "" << endl; // prints 
	return 0;
}
