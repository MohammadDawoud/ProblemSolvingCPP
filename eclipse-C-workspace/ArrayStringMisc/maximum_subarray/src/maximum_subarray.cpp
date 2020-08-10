//============================================================================
// Name        : maximum_subarray.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>


using namespace std;

int maxSubArray(vector<int>& nums) ;

int main() {
	vector <int> A = {88,-35,50,-38,-60,-31,-2,-8,-8,91,-14,50,-25,-26,1,71,-91,-64,-40,46,30,-97,9,-55,-36,-75,71,99,90,-53,-68,-20,-73,89,-14,74,-8,72,82,48,45,2,-42,12,77,22,87,56,73,-21,78,15};

	cout << maxSubArray(A);
	return (0);
}


int maxSubArray(vector<int>& nums) {

	int lastIndex = 0;
	int maxstart = 0;
	if(nums.size() == 0)
		return 0;
	int currentSum = nums[0];
	int maxSum = nums[0];
	int currentStart =0;

	for(int i = 1; i < nums.size(); i++) {

		currentSum += nums[i];  // handle special case e.g. starting with negative number. or having a very small negative number in the middle
		if(nums[i] > currentSum) {
			currentStart = i-1;
			currentSum = nums[i];
		}

		if(currentSum > maxSum) {
			maxstart = currentStart;
			maxSum = currentSum;
			lastIndex =i;
		}
	}

	return maxSum;
}
