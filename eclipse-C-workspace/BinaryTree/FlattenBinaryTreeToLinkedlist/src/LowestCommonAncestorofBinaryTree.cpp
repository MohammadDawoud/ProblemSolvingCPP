//============================================================================
// Name        : FlattenBinaryTreeToLinkedlist.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
114. Flatten Binary Tree to Linked List

Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
 */
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
  
    //flatten in pre-order
    // the function retrun the tail
    
TreeNode* flattenRecursion(TreeNode* node, TreeNode* tail) {
        
	// base case
	if(node == NULL) {
	    return tail;
	}


	// recursion case
	TreeNode* leftNode = node->left;
	TreeNode* rightNode = node->right;

	if(leftNode != NULL) {
		node->left=NULL;
		tail->right = leftNode;
		tail = leftNode;
		tail = flattenRecursion(leftNode, tail);
	}

	if(rightNode != NULL) {
		tail->right = rightNode;
		tail = rightNode;
		tail = flattenRecursion(rightNode,tail);
	}

	return tail;
}

void flatten(TreeNode* root) {
	flattenRecursion(root,root);
}
int main() {
	cout << "" << endl; // prints 
	return 0;
}
