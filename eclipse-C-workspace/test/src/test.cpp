//============================================================================
// Name        : test.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;



int main() {

	int  matrix [3][3] = {
	   { 1,  5,  9},
	   {10, 11, 13},
	   {12, 13, 15}
};
// diagonal iteration
	int n=3;
    for(int i=0; i<n;i++) {
        int c = i; // column
        for(int r=0; (r<=i && c>=0) ;r++) {
            cout<< matrix[r][c]<<",";
            c--;
        }

        cout<< endl;
    }


    for(int i =1; i< n; i++) {
    	int c = n-1;
    	int r = i;
    	for(;r < n; r++) {
            cout<< matrix[r][c]<<",";
    		c--;
    	}
        cout<< endl;
    }

    /*	  cout<< matrix[r][c]<<",";
		  c--;
		}
    */


/*
	for(int i=k-1; i>=0;i++) {
		int c = i; // column
		for(int r=c; (r<=i && c>=0) ;r++) {
			cout<< matrix[r][c]<<",";
			c--;
		}
    }
*/
	return 0;
}



