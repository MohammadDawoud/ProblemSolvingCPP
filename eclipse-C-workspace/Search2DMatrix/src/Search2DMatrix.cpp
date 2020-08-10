//============================================================================
// Name        : Search2DMatrix.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//=============================================

/*===============================
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 *
*/

#include <iostream>
#include <vector>
using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int rows = matrix.size();
	int columns = matrix[0].size();
	int length = rows*columns;

	int start =0;
	int end = length-1;
	int median = 0;
	while(start <= end) {
		median = (start+end)/2;
		int r = median/columns;
		int c = median%columns;
		if(matrix[r][c] == target)
			return true;
		else if(matrix[r][c] < target) {
			start = median+1;
		}
		else if(matrix[r][c] > target) {
			end = median-1;
		}

	}
	return false;
}

int main() {
	cout << "" << endl; // prints 
	return 0;
}
