//============================================================================
// Name        : BinarySearch.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description :  Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int binarySearch(int input [], int start, int end, int target);

bool compare (int a, int b) {
	return a<b;
}

int main() {

	int input [10] = {1,2,4,3,5,8,7,9,6,0};
	int x = INT_MIN;
	cout << "value of " << x << endl;

	sort(input, input+10, compare);

	for (int i=0; i < 10; i++)
		cout << input [i] << ", ";

	cout << endl;
	int output = binarySearch(input, 0, 9, 1);

//	cout << sizeof(input) << endl;

	cout << "the index is " << output;
	return output;
}


int binarySearch(int input [], int start, int end, int target) {

	int median = 0;
	if ( sizeof(input) == 0 )
		return -1;

	while(start <= end) {
		median = (start+end)/2;
		if(target == input[median])
			return median;

		else if(target < input[median])
			end=median-1;

		else
			start=median+1;

	}
	return -1;
}
