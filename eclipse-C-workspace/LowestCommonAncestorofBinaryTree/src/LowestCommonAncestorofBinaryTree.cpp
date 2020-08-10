//============================================================================
// Name        : LowestCommonAncestorofBinaryTree.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 *236. Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]




Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

 */
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    //base case
    if(root == NULL) {
        return NULL;
    }

    if(root->val == p->val || root->val == q->val) {
    //    cout << root->val;
        return root;
    }

    //recursive case
    TreeNode* leftSide  = lowestCommonAncestor(root->left, p,q);
    TreeNode* rightSide = lowestCommonAncestor(root->right, p,q);


    if(leftSide != NULL && rightSide != NULL) {
      //  cout << "true " <<  rightSide->val;
        return root;
    }

    if(leftSide != NULL)
        return leftSide;

    return rightSide;

}


int main() {
	cout << "" << endl; // prints 
	return 0;
}
