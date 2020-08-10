//============================================================================
// Name        : BalancedBinaryTree.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 110. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.



Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
 */


#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool heightDiff(TreeNode *node, int& height) {


    // base case
    if(node == NULL) {
        height =0;
        return true;
    }

    // recursion

    int leftHeight = 0;
    int rightHeight = 0;

    bool isLeftBalanced = heightDiff(node->left, leftHeight);
    bool isRightBalanced = heightDiff(node->right, rightHeight);
    height = max(leftHeight,rightHeight) +1;
    return isLeftBalanced & isRightBalanced & (abs(leftHeight-rightHeight) <= 1);

}

bool isBalanced(TreeNode* root) {
    int height = 0;
    return heightDiff(root, height);
}
int main() {
	cout << "" << endl; // prints 
	return 0;
}
