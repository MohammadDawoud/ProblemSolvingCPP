//============================================================================
// Name        : NQueens_recursion.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

/*
51. N-Queens

Share
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.

*/
bool validPosition(int row, int column, vector<int> columnList) ;
vector<string> generate2DGrid(vector<int> columnList);

void solveNQueensRecursion(int n, int currentRow, vector<int> columnList, vector<vector<string>>& results) {
	//base case
	if(currentRow == n) {
		vector<string> sol = generate2DGrid(columnList);  // convert array to 2d array
		results.push_back(sol);
	}

	// recursion case
	for(int c=0; c < n; c++) { // loop through columns
		if(validPosition(currentRow, c, columnList)) {
			columnList[currentRow]=c;
			solveNQueensRecursion(n, currentRow+1, columnList, results);
		}
	}

}

bool validPosition(int row, int column, vector<int> columnList) {


	// check column &diagonal
	for(uint r=0; r< columnList.size(); r++) {
		if(columnList[r] == -1) // we did not visit that row yet
			break;
		if (column == columnList[r])
			return false;             // same column


		int rowDistance = abs((int)(row-r));
		int columnDistance = abs(column-columnList[r]);
		if (rowDistance== columnDistance)  // on diagonal
			return false;
	}

	return true;

}

vector<string> generate2DGrid(vector<int> columnList) {
	vector<string> grid;
	int n=columnList.size();
	grid.reserve(n);
	char rowStr [n+1] = {'\0'};
	for(int r=0; r < n; r++) {
		for(int c=0; c < n; c++) {
			if(columnList[r] == c)
				rowStr[c]= 'Q';
			else
				rowStr[c]= '.';
		}
		string s(rowStr);
		grid.push_back(s);
	}


	return grid;
}

vector<vector<string>> solveNQueens(int n) {
//	vector<string> grid = generateGrid(n);
	vector<int> columnList(n,-1);
	vector<vector<string>> results;
	solveNQueensRecursion( n, 0, columnList, results );
	return results;
}

int main() {

	vector<vector<string>> results = solveNQueens(4);

	for(vector<string> v : results) {
		for(string s : v) {
			cout << s;
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}
