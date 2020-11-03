/*
 * longestIncreasing Sequence.cpp
 *
 *  Created on: Oct 31, 2020
 *      Author: david
 */

/*
300. Longest Increasing Subsequence
Medium

5770

130

Add to List

Share
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

*/

#include <iostream>
#include<vector>
#include <algorithm>
#include<limits.h>



using namespace std;

class Solution {
public:

	// n2
    int lengthOfLIS2(vector<int>& nums) {

        if(nums.empty()) {
            return 0;
        }

        vector <int> dp (nums.size(),0);
        dp[0] =1;
        int maxResult = 1;

        for(int i=1; i < nums.size(); i++) {
            int maxSequence = 0;
            for(int j=0; j< i; j++) {
                if(nums[j] < nums[i]) {
                    maxSequence = max(maxSequence, dp[j]);
                }
            }
            dp[i] = maxSequence+1;
            maxResult = max(maxResult, dp[i]);
        }

        return maxResult;


    }

    //     nlogn
    // dp index represnts the sequence length
    // value represent the  item that represnt the sequence
        int lengthOfLIS(vector<int>& nums) {

            if(nums.empty()) {
                return 0;
            }

            vector <int> dp (nums.size()+1,INT_MAX);
            dp[0] =INT_MIN;
            int maxResult = 1;

            for(int i=0; i < nums.size(); i++) {
                vector<int>::iterator up=std::upper_bound (dp.begin(), dp.end(), nums[i]);
                int index = up - dp.begin();
                if( nums[i] < dp[index] && nums[i] > dp[index-1] ) {
                    dp[index] = nums[i];
                    maxResult = max(maxResult,index);
                }

    /*           for (int x : dp) {
                   cout << x << ", ";
               }
                cout << endl;
     */
            }

            return maxResult;


        }

};
