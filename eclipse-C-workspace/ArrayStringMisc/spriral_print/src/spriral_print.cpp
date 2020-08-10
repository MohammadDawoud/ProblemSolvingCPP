//============================================================================
// Name        : spriral_print.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

void spiralPrint (int input[][100], int r, int c) {

	int startRow = 0;
	int endRow = r-1;

	int startColumn = 0;
	int endColumn = c-1;




	while (startRow <= endRow && startColumn <= endColumn ) {

		// print first row
		for (int c = startColumn; c<= endColumn; c++) {
			cout << input[startRow][c] << " ";
		}
		startRow++;

		if(startRow > endRow  ) // it was only one row and it has been printed
			break;

		// print last column
		for (int r = startRow; r<= endRow; r++) {
			cout << input[r][endColumn] << " ";
		}
		endColumn--;

		if(startColumn > endColumn  ) // it was only one column and it has been printed
			break;


		// print last row
		for (int c = endColumn; c >= startColumn; c--) {
			cout << input[endRow][c] << " ";
		}
		endRow--;

		// print first column
		for (int r = endRow; r >= startRow; r--) {
			cout << input[r][startColumn] << " ";
		}
		startColumn++;

	}




}

int main() {

	int x[3][100]= {
				  {1, 2, 3, 4},
				  {5, 6, 7, 8},
				  {9,10,11,12}};

	spiralPrint(x, 3,4);
	return 0;
}
