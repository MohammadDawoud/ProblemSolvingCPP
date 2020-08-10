//============================================================================
// Name        : AllNodesDistanceKinBinaryTree.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 863. All Nodes Distance K in Binary Tree

We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.



Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation:
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.



Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.

 */
#include <iostream>
#include <vector>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void getNodesFromTarget( TreeNode* node, int current, int k, vector<int> & result) { // current represents the discount from the target for the children
        // check for null
        if(node == NULL)
            return;

        if(k== current) {
            result.push_back(node->val);
            return;
        }

        if(current>k) //failsave condition
            return;


        // recursion
        getNodesFromTarget(node->left, current+1, k, result);
        getNodesFromTarget(node->right, current+1, k, result);

        return;
    }


   int distanceK(TreeNode* node, TreeNode* target, int k ,vector<int> & result) { // return the discount from the target for the ancestor, default = -1 (unknown)
       // base case
       // if target is found call getNodesFromTarget and go back with current zero

       if(node == NULL)
           return -1;
       if(node== target) {
           getNodesFromTarget(node, 0, k,result);
           return 0;
       }

       // recursion case
       int leftDistance =  distanceK(node->left, target, k ,result);
       int rightDistance =  distanceK(node->right, target, k ,result);

       if(leftDistance != -1)  {  // target is found on child node
           // print the childred in the right side
           if (leftDistance+1 < k) {
               getNodesFromTarget(node->right, leftDistance+2, k, result);
           }

           if(leftDistance+1 == k) {  // the itself ancestor is at distance k  of the target
               result.push_back(node->val);
           }

           leftDistance++;
           return leftDistance;
       } else if(rightDistance != -1)  { // target is found on child node
           // print the childred in the right side
           if (rightDistance < k) {
               getNodesFromTarget(node->left, rightDistance+2, k, result);
           }

           if(rightDistance+1 == k) {  // the itself ancestor is at distance k  of the target
               result.push_back(node->val);
           }
           rightDistance++;
           return rightDistance;
       }

       return -1;


   }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int>  result;
        distanceK(root, target, K, result);
        return result;
    }

int main() {
	cout << "" << endl; // prints 
	return 0;
}
