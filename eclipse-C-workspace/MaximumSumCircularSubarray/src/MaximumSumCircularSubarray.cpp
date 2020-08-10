//============================================================================
// Name        : MaximumSumCircularSubarray.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <climits>
using namespace std;



int minSubArray(vector<int>& nums) {

	int minIndex = 0;

	int startIndex = 0;
	int currentStartIndex = 0;
	if(nums.size() == 0)
		return 0;
	int currentSum = nums[0];
	int minSum = nums[0];

	for(uint i = 1; i < nums.size(); i++) {

		currentSum += nums[i];  // handle special case e.g. starting with negative number. or having a very small negative number in the middle
		if(nums[i] < currentSum) {
			currentStartIndex = i;
			currentSum = nums[i];
		}

		if(currentSum <= minSum) {
			startIndex = currentStartIndex;
			minIndex = i;
			minSum = currentSum;
		}
	}

	return startIndex;
}


int maxSubarraySumCircular(vector<int>& nums) {

	if(nums.size() == 0)
		return 0;

	int minIndex = minSubArray(nums);


	int currentSum = nums[(minIndex+1)%nums.size()];
	int maxSum = nums[(minIndex+1)%nums.size()];

	for(int i = minIndex+2; i < 2*nums.size(); i++) {

		currentSum += nums[i%nums.size()];  // handle special case e.g. starting with negative number. or having a very small negative number in the middle
		if(nums[i%nums.size()] > currentSum) {
			currentSum = nums[i%nums.size()];
		}

		if(currentSum > maxSum)
			maxSum = currentSum;

		if(minIndex == i%nums.size())
			break;
	}

	return maxSum;
}



int main() {
	//vector<int> A = {-9,14,24,-14,12,18,-18,-10,-10,-23,-2,-23,11,12,18,-9,9,-29,12,4,-8,15,11,-12,-16,-9,19,-12,22,16};
	//vector<int> A = {5,-3,5,-2,5};
	//vector<int> A = {1,0,-1,-2,-3,-2};
	vector<int> A ={88,-35,50,-38,-60,-31,-2,-8,-8,91,-14,50,-25,-26,1,71,-91,-64,-40,46,30,-97,9,-55,-36,-75,71,99,90,-53,-68,-20,-73,89,-14,74,-8,72,82,48,45,2,-42,12,77,22,87,56,73,-21,78,15,
			-6,-75,24,46,-11,-70,-90,-77,57,43,-66,10,-30,-47,91,-37,-4,-67,-88,
			19,66,29,86,97,-4,67,54,-92,-54,71,-42,-17,57,-91,-9,-15,-26,56,-57,-58,-72,91,-55,35,-20,29,51,70};
	cout << "value is "<< maxSubarraySumCircular(A) << endl; // prints


	return 0;
}
