//============================================================================
// Name        : quickSort.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int partition (int in[], int start, int end) {


	int pivot =  in[(start+end) /2]; // pick middle value

	while (start <= end) {

		while(in[start] < pivot)
			start++;
		while(in[end] > pivot)
			end--;

		if(start <= end) {
			swap(in[start], in[end]);
			start++;
			end--;
		}

	}

	return start;  // the new mid point. the value in the start-1 is in its correct location
}


void quickSort(int in[], int start, int end) {

	int mid =  partition(in,  start,  end);
	if(start < mid-1) {
		quickSort(in, start, mid-1);
	}
	if(end > mid) {
		quickSort( in, mid, end);
	}
}

int main() {

	int in [] = {3,5,2,6,7,6,2,5,9,1,9,9};

	quickSort(in, 0,11);

	for(auto i : in)
		cout << i<<", ";
	return 0;
}
