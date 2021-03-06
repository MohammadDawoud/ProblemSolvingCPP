//============================================================================
// Name        : PrimePalindrome.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<long> primeSieve () {

	const long n = pow(10,8);
	vector<bool> p(n,false);
	vector<long> primes;

	p[2] = true;
	for(int i=3; i<n; i=i+2)  // set all odd number to true
		p[i] = true;

	for(long i=3; i<n; i = i+2) {
		if(p[i]) {
			for(long j = i*i; j < n; j=j + 2*i) {
				p[j]=false;
			}
		}
	}

	for(long i =0; i < n; i++) {
		if(p[i]) {
			primes.push_back(i);
	//		cout << i << " ,";
		}
	}



	return primes;



}


int main() {
	cout << "" << endl; // prints 
	primeSieve();
	return 0;
}
