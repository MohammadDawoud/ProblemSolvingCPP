//============================================================================
// Name        : DeleteNodeInBST.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
450. Delete Node in a BST
Medium

1861

84

Add to List

Share
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
 */
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* deleteNode(TreeNode* node, int key) {
     
        //base case
        if(node == NULL) {
            return node;
        }
        
        if(node-> val == key) {  
            // leaf
            if(node -> left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            }
            // one child            
            else if(node->left == NULL || node->right == NULL) {
               TreeNode* tmp = NULL;
                if(node ->left != NULL) {
                    tmp = node->left;
                }
               else if(node ->right != NULL) {
                     tmp = node->right;
                }
                delete node;
                return tmp;
             }
            // two children
            else if (node -> left != NULL && node->right != NULL) {
                // replace with the minimum value on the right
                TreeNode * replacedNode = node->right;
            //    cout<< "replacedNode=" << replacedNode->val <<endl;

                while(replacedNode->left != NULL) {
                    replacedNode = replacedNode->left;
                }
                
               // cout<< "replacedNode=" << replacedNode->val <<endl;
                node->val = replacedNode->val;
                node->right = deleteNode(node->right, replacedNode->val);
                return node;
            }
            
            
        }
      else if( key < node->val) {
          node->left = deleteNode(node->left, key);
          return node;
       }
        else if( node->right != NULL) {
            node->right = deleteNode(node->right, key);
            return node;
            
        }
        
            return node;
            
        
    }


int main() {
	cout << "" << endl; // prints 
	return 0;
}
