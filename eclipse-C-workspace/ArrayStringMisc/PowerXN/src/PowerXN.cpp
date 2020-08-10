//============================================================================
// Name        : PowerXN.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * mplement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
 *
 * */

#include <iostream>
using namespace std;

double myPow(double x, int n) {

	if( n < 0)
	{
		n = -1*n;
		x=1/x;
	}
	if(n==0)
		return 1;

	double result =1;
	double currentBase = x;
	while(n>0) {
		if(n&1) {
			result *= currentBase;
		}
		currentBase *= currentBase;

		n = n>>1;

	}

	return result;

}


int main() {
	double x;
	int n;
	cin >> x >> n;

	cout << myPow(x,n);

 return 0;
}
