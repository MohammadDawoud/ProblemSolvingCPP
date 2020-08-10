//============================================================================
// Name        : SearchRotatedSortedArray.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


/*
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
 *
 * */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool search(vector<int>& nums, int target) {

    if (nums.size() == 0)
        return false;


    int start =  0;
    int end =  nums.size()-1;
    int middle = 0;

    while (start <= end && start >= 0 && end <  nums.size()) {

        middle = (start+end)/2;

        // case 1 target found
        if (nums[middle] == target)
            return true;

        if (nums[start] < nums[middle]) {

            // normal binary search on the left side, target between start and middle
            if ( target < nums[middle] && target >= nums[start]) {
                end =  middle-1;
            }
            else
                start = middle +1;
        }
        else if (nums[end] > nums[middle]){
            // normal binary search on the right side
            if (target > nums[middle] &&  target <= nums[end]) {
                start =  middle+1;
            }
            else
                end = middle-1;
        }
        else if (nums[start] == target)
        	return true;
        else
        	start++;
    }
    return false;

}


int main() {

	vector<int> nums {1,3,1,1,1};
	bool result = search(nums,3);
	cout << "resutl::" << result<< endl;
	return 0;
}
