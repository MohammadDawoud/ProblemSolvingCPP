//============================================================================
// Name        : ConvertSortedArraytoBinarySearchTree.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 108. Convert Sorted Array to Binary Search Tree

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

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

    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end){

        // base case
        if(end==start) {
            return new TreeNode(nums[start]);
        } else if(start<0 || end >= nums.size()) //failsave condition
            return NULL;

        // recursion
       int mid = (end+start)/2;
       TreeNode *node = new TreeNode(nums[mid]);

        if (mid>start) {
            node->left = sortedArrayToBST(nums, start,mid-1);  // if difference between start and end is 1 only
        }

        node->right = sortedArrayToBST(nums, mid+1,end);

        return node;

    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
          return sortedArrayToBST(nums, 0,nums.size()-1);
    }


int main() {
	cout << "" << endl; // prints 
	return 0;
}
