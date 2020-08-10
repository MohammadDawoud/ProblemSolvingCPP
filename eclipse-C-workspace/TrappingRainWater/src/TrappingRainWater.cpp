//============================================================================
// Name        : TrappingRainWater.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) {

	int leftMax = 0;
	int rightMax = 0;
	int leftIndex = 0;
	int rightIndex = height.size()-1;
	int totalWater = 0;

	while(leftIndex <= rightIndex) {

			leftMax = max(leftMax, height[leftIndex]);  // comparing with height is just to avoid negative value in line #29
			rightMax = max(rightMax, height[rightIndex]);

			if(leftMax <= rightMax) {
				totalWater += leftMax-height[leftIndex];
				leftIndex++;
			}
			else if(leftMax > rightMax) {
				totalWater += rightMax-height[rightIndex];
				rightIndex--;
			}

	}

	return totalWater;

}

int main() {
	cout << "" << endl; // prints 
	return 0;
}
