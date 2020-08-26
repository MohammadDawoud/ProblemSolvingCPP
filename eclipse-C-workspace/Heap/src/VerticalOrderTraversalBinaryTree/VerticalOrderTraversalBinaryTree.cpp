/*
 * VerticalOrderTraversalBinaryTree.cpp
 *
 *  Created on: Aug 26, 2020
 *      Author: MOhamed Dawoud
 *
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };



class Point {
public:
    int x,y,val;
    Point(int x, int y, int val) {
        this->x = x;
        this->y = y;
        this->val = val;
    }
};

class Compare {
public:
    bool operator()(Point a, Point b) {

        return (a.x > b.x || (a.x == b.x && a.y < b.y ) || (a.x == b.x && a.y == b.y && a.val > b.val ) );

    }
};


class Solution {
public:

   void  verticalTraversal(TreeNode* node, int x, int y , priority_queue <Point, vector<Point>, Compare> &heap) {
        if(node == NULL)
            return;
       int v = node->val;
        Point p = Point(x,y, v);
        heap.push(p);

        verticalTraversal(node->left, x-1, y-1 , heap);
        verticalTraversal(node->right, x+1, y-1 , heap);

    }


    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }


        priority_queue <Point, vector<Point>, Compare> heap ;
        verticalTraversal(root, 0, 0 , heap);

        int currentX = heap.top().x;
        vector<int> level = vector<int> ();

        while(heap.empty() == false) {

            Point p = heap.top();
            heap.pop();

            if(p.x != currentX) {
                result.push_back(level);
                currentX = p.x;
                level = vector<int> ();
            }

            level.push_back(p.val);

        }
        result.push_back(level); // last level

        return result;

    }
};

