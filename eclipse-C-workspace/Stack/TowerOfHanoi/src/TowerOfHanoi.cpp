//============================================================================
// Name        : TowerOfHanoi.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


void move (int n, char src, char helper, char dest) {

	// base case
	if (n == 0) {
		return;
	}

	//rec case
	move(n-1, src, dest, helper);
	cout << "Moving ring " << n << " from " << src << " to "<< dest << endl;
	move(n-1, helper,  src, dest);
	return;
}

int main() {

	int n ;
	cin >> n;
	move(n, 'A', 'B', 'C');
	return 0;
}
