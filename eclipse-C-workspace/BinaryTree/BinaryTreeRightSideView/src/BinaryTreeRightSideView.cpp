//============================================================================
// Name        : BinaryTreeRightSideView.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 199. Binary Tree Right Side View


Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

 */
#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void rightSideView(TreeNode* node, int currentDepth, int& maxDepth,  vector<int> & result) {
    //base case
    if(node == NULL) {
        return;
    }

    // recursion case
    if(currentDepth>maxDepth) {
        result.push_back(node->val);
        maxDepth = currentDepth;
    }

    rightSideView(node->right, currentDepth+1, maxDepth, result);
    rightSideView(node->left, currentDepth+1, maxDepth, result);


}
vector<int> rightSideView(TreeNode* root) {

    vector<int>  result;
    int tmp =0;
    rightSideView(root, 1,tmp, result);
    return result;
}

int main() {
	cout << "" << endl; // prints 
	return 0;
}
