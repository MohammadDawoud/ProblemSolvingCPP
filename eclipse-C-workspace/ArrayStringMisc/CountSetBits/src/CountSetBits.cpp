//============================================================================
// Name        : CountSetBits.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "iostream"
using namespace std;


void countSetBits(int input[], int n) {
	int bitCount = 0;
	int var =0;
	for(int i=0; i<n; i++) {
		var = input[i];
		bitCount = 0;

		while (var>0) {
			var = var & (var-1);
			bitCount++;
		}

		cout << bitCount<< endl;


	}

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

    countSetBits(input, n);

    return 0;
}
