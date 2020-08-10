//============================================================================
// Name        : NumberofSubmatricesThatSumtoTarget.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 *
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
 * */

vector<vector<int>> getPrefixSum(vector<vector<int>> matrix) {


	vector<vector<int>> prefixSum (matrix) ;
    //vector<vector<int> > vec(5);


	for(uint i=0; i < prefixSum.size(); i++) {
		for(uint j=1; j < prefixSum[0].size(); j++) {
			prefixSum[i][j] += prefixSum[i][j-1];
		}
	}


	for(uint c=0; c < prefixSum[0].size(); c++) {
		for(uint r=1; r < prefixSum.size(); r++) {
			prefixSum[r][c] += prefixSum[r-1][c];
		}
	}

/*	for(uint i=0; i< prefixSum.size(); i++) {
		for(uint j=0; j < prefixSum[i].size(); j++)
			cout << prefixSum[i][j] << " ";
		cout << endl;
	}

	cout << endl;
	cout << endl;
*/
	return prefixSum;
}

int getSubmatricesCount2(vector<vector<int>> matrix, int target) {
	int ways = 0;
	vector<vector<int>> prefixSum = getPrefixSum(matrix);
	int upperLeftRow = 0;
	int upperLeftColumn = 0;
	int lowerRightRow = 0;
	int lowerRightColumn = 0;

	int sumOfAboveLowerLeft = 0;
	int sumOfLeftLowerLeft = 0;
	int sumOfDiagonalLowerLeft = 0;

	int sumOfCurrentLowerRight = 0;

	for(uint i=0; i< prefixSum.size(); i++) {
		upperLeftRow = i;
		for(uint j=0; j < prefixSum[i].size(); j++) {
			upperLeftColumn=j;
			for(uint r=i; r< prefixSum.size(); r++) {
				lowerRightRow = r;
				for(uint c=j; c < prefixSum[r].size(); c++) {
					lowerRightColumn=c;

					sumOfAboveLowerLeft = 0;
					sumOfLeftLowerLeft = 0;
					sumOfDiagonalLowerLeft = 0;

					if(upperLeftRow != 0)
						sumOfAboveLowerLeft = prefixSum[upperLeftRow-1][lowerRightColumn];
					if(upperLeftColumn != 0)
						sumOfLeftLowerLeft = prefixSum[lowerRightRow][upperLeftColumn-1];
					if(upperLeftColumn != 0 && upperLeftRow != 0)
						sumOfDiagonalLowerLeft = prefixSum[upperLeftRow-1][upperLeftColumn-1];

					sumOfCurrentLowerRight =
											  prefixSum[lowerRightRow][lowerRightColumn]
											 - sumOfAboveLowerLeft
											 - sumOfLeftLowerLeft
											 +sumOfDiagonalLowerLeft;
					if(sumOfCurrentLowerRight == target)
						ways++;




				}
			}
		}

	}


	return ways;

}



int getSubmatricesCount(vector<vector<int>> matrix, int target) {
	int ways = 0;
	vector<vector<int>> prefixSum (matrix) ;
    unordered_map<int, int> record;

    //vector<vector<int> > vec(5);


	for(uint r=0; r < prefixSum.size(); r++) {
		for(uint c=1; c < prefixSum[0].size(); c++) {
			prefixSum[r][c] += prefixSum[r][c-1];
		}
	}


	for(uint i=0; i< prefixSum.size(); i++) {
			for(uint j=0; j < prefixSum[i].size(); j++)
				cout << prefixSum[i][j] << " ";
			cout << endl;
		}

		cout << endl;

	int currentSum = 0;
	int leftSum = 0;

	for(uint c_start=0; c_start< prefixSum[0].size(); c_start++) {
		for(uint c_end=c_start; c_end < prefixSum[0].size(); c_end++) {
			currentSum = 0;
			leftSum = 0;
			record = {{0,1}};
			for(uint r=0; r< prefixSum.size(); r++) {

				if(c_start == 0)
					leftSum = 0;
				else
					leftSum = prefixSum[r][c_start-1];
				currentSum +=  prefixSum[r][c_end] - leftSum;

				if(record.find(currentSum - target) != record.end()) {
					ways += record[currentSum - target];
				}
				record[currentSum]++;


			}
		}

	}


	return ways;

}



int main() {

	vector<vector<int>> matrix = {
					  {0, 1, 0},
					  {1, 1, 1},
					  {0, 1, 0}		};

//	vector<vector<int>> matrix = {{0,1,1,1,0,1},{0,0,0,0,0,1},{0,0,1,0,0,1},{1,1,0,1,1,0},{1,0,0,1,0,0}};

	int target = 0;

	int ways = getSubmatricesCount(matrix, target);
	cout << "no of ways " << ways;
	return 0;
}
