//============================================================================
// Name        : CountingBits.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * array in which all numbers are repeated twice except 2 numbers
 * find 2 numbers that have one 1 occurence in the array
 *
 * */
#include "iostream"
using namespace std;


void uniqueII(int input[], int n) {
	int xorValue = input[0];
	int var =0;
	for(int i=1; i<n; i++) {
		xorValue = xorValue ^ input[i];
	}

	// get mask. the first set bit in xorValue
	int mask = 1;
	while ((xorValue & mask) == 0) {
		mask = mask << 1;
	}

	// xop  with all

	int firstUnique = -1;

	for(int i=0; i<n; i++) {

		if(mask &input[i]) {
			if(firstUnique == -1) {
				firstUnique = input[i];
			} else {
				firstUnique = firstUnique ^ input[i];
			}
		}

	}

	cout << firstUnique << " " << (firstUnique^xorValue); // firstUnique^xorValue second unique



}


int main(int argc, char* argv[])
{
    int n;
    cin>>n;
    int input [1000] = {0};

    int i = 0;
    while (i < n) {

    	cin>>input[i];
    	i++;
    }

    uniqueII(input, n);

    return 0;
}

