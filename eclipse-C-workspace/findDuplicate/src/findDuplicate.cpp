//============================================================================
// Name        : findDuplicate.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 287. Find the Duplicate Number

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
 */
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;



int findDuplicate(vector<int>& nums) {
	int value = -1;
	for(uint i=0; i < nums.size(); i++) {
		if(nums[abs(nums[i])] < 0 ) {
			value = abs(nums[i]);
			break;
		}
		nums[abs(nums[i])] *= -1;
	}

	for(uint i=0; i < nums.size(); i++) {
		nums[i] = abs(nums[i]);
	}
	return value;

}
int main() {


	return 0;
}
