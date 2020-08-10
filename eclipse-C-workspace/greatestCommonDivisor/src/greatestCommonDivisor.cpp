//============================================================================
// Name        : greatestCommonDivisor.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;




int gcd(int x, int y) {
	return (x==0) ? y : gcd(y%x,x);
}

int lcm(int x, int y) {
	return (x*y/gcd(x,y));
}

int main() {

	int x,y;
	cin >> x>>y ;

	int result = lcm(min(x,y),max(x,y));

	cout << result;
	return 0;
}
