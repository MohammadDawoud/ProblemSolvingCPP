//============================================================================
// Name        : HashMap.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 560. Subarray Sum Equals K

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2


Constraints:

The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int count =0;
    int sum = 0;
    unordered_map<int,int> prefixSum; //  key is the sum, value is the count of occurrences
    prefixSum[nums[0]] = 1;
    sum += nums[0];

    if(nums[0] == k) {
    	count++;
    }

    for(uint i=1; i < nums.size(); i++) {
    	sum += nums[i];
    	// if sum is the target increment the count
    	if (sum == k) {
    		count ++;
    	}

    	// check for occurrences of k-sum
    	if(prefixSum.count(sum-k) > 0 ) {
    		count += prefixSum[sum-k];
    	}

    	// add the new sum to the the prefix sum
    	prefixSum[sum] = prefixSum[sum]+1;
    }



	return count;
}

int main() {
	cout << "" << endl; // prints 
	return 0;
}
