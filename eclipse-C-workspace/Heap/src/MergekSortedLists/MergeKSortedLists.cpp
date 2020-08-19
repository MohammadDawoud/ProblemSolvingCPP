//============================================================================
// Name        : KthSmallestElementSortedMatrix.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 378. Kth Smallest Element in a Sorted Matrix

Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.
 */


int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int> heap =  priority_queue<int>();

    int size = matrix.size();
    for(int r=0; r<size;r++) {
        for(int c=0; c<size  ;c++) {

            if(heap.size() < k) {
                heap.push(matrix[r][c]);
            }
            else if(matrix[r][c] < heap.top() ) {
                heap.pop();
                heap.push(matrix[r][c]);
            }
        }
    }

    return heap.top();
}
int main() {
	cout << "" << endl; // prints 
	return 0;
}
