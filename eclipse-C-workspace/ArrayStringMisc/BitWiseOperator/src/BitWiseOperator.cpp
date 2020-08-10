//============================================================================
// Name        : BitWiseOperator.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


bool getIthBit(int n, int i) {

	int sh = 1 << i;
	return ((n&sh) > 0 )?  (n&sh) : 0;

}

int setIthBit(int n, int i) {

	int sh = 1 << i;
	return n|sh;

}

int clearBit(int n, int i) {
	int mask = 1 << i;
	mask = ~mask;

	return n&mask;
}

int updateBit(int n, int i, int v) {

	if(v != 0 || v != 1)
		return 0;

	int mask = ~(1 << i);

	n = n & mask; //clear it

	mask = v << i;
	return n|mask;
}


int clearRange (int n, int i, int j) {

	int mask = (~0) << j+1;
	int rightrRange =  (1<<i)-1;

	mask = mask | rightrRange;

	return mask&n;


}


int main() {

	int input,i;

	cin >> input >>i;
	cout <<"getIthBit "<< getIthBit(input, i);
	cout << "" << endl; // prints

	cout << "clearbit " << clearBit(input, i);
	cout << "" << endl; // prints

	cout <<"clearRange"<< clearRange(127, 1,2);
	cout << "" << endl; // prints

	cout << ~0;

	cout << "" << endl; // prints 
	return 0;
}
