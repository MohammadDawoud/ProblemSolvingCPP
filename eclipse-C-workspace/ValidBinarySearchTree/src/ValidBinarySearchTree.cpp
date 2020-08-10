//============================================================================
// Name        : ValidBinarySearchTree.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
98. Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 */


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

bool validBSTRecursion(TreeNode* n, long max, long min) {
	if(n == nullptr)
		return true;

	if (n->val >= max || n->val < min) {
		return false;
	}

	bool leftStatus = validBSTRecursion(n->left, n->val, min);

	bool rightStatus = validBSTRecursion(n->right, max,n->val);

	return leftStatus & rightStatus;


}

bool isValidBST(TreeNode* root) {
    return validBSTRecursion(root, LONG_MAX, LONG_MIN);
}



int main() {

	TreeNode root(2147483647);
	TreeNode left(1);
	TreeNode right(1, new TreeNode(3), new TreeNode(6));

	//root.left = &left;
	//root.right = &right;


	cout << isValidBST(&root);
	return 0;
}
