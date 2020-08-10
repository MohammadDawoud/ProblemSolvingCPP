//============================================================================
// Name        : array_rotation.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void rotate(vector<vector<int>>& matrix) {
	int layer =  matrix.size()/2;

	for(int l =0; l < layer; l++)	{

		int startIndex = l;
		int lastIndex  = matrix.size()-1-l;


		for (int i=startIndex; i < lastIndex; i++) {
			int offset = i-startIndex;

			// copy first row of the layer
			int tmp =  matrix[startIndex][i] ;

			// first row
			matrix[startIndex][i] = matrix[lastIndex-offset][startIndex];

			//first column
			matrix[lastIndex-offset][startIndex] = matrix[lastIndex][lastIndex-offset];

			//last row
			matrix[lastIndex][lastIndex-offset] =  matrix[startIndex+offset][lastIndex] ;

			// last column
			matrix[startIndex+offset][lastIndex] = tmp;


			for(uint i=0; i< matrix.size(); i++) {
				for(uint j=0; j < matrix[i].size(); j++)
					cout << matrix[i][j] << " ";
				cout << endl;
			}

			cout << endl;
			cout << endl;

		}


	}




}

int main() {


	vector<vector<int>> matrix = {
				  {17, 18, 19, 20},
				  {21, 22, 23, 24},
				  {25, 10, 11, 12},
				  {13, 14, 15, 16}
	};


	rotate(matrix);




	return 0;
}
