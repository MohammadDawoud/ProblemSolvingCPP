//============================================================================
// Name        : BinaryTreeLevelOrderTraversalII.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 * 107. Binary Tree Level Order Traversal II

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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

void levelOrderBottomRecursive(vector<TreeNode*> &lvl, vector<vector<int>> &results) {
	//base case
	if(lvl.size() == 0)
	{
		return;
	}

	vector<int> levelData;
	levelData.reserve(lvl.size());


	vector<TreeNode*> nextLevel;
	nextLevel.reserve(lvl.size()*2);

	for(TreeNode* node : lvl) {
		levelData.push_back(node->val);
        if(node->left != NULL)
		    nextLevel.push_back(node->left);
		if(node->right != NULL)
            nextLevel.push_back(node->right);
	}


	levelOrderBottomRecursive(nextLevel, results);
	results.push_back(levelData);

}

vector<vector<int>> levelOrderBottom(TreeNode* root) {

	vector<TreeNode*> level(1,root);
	vector<vector<int>> results;

	if(root == NULL)
		return results;

	levelOrderBottomRecursive(level, results);
	return results;
}

int main() {

	TreeNode *left= new TreeNode (15);
	TreeNode *right = new TreeNode(7);

	right = new TreeNode(20, left, right);
	left = new TreeNode(9);

	TreeNode *root =new  TreeNode(3, left, right);

	levelOrderBottom(root);

	cout << "" << endl; // prints 
	return 0;
}
