/*
 * uniquePaths.cpp
 *
 *  Created on: Nov 3, 2020
 *      Author: david


62. Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?



Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
Example 3:

Input: m = 7, n = 3
Output: 28
Example 4:

Input: m = 3, n = 3
Output: 6


Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 109.

*/

#include <iostream>

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[100][100]  = {{0}};
       return uniquePaths(m, n, 0, 0, dp);

    }

    int uniquePaths(int r, int c, int current_r, int current_c, int dp[100][100] ) {

        int waysCount = 0;
        // base case if current is the target
        if(current_r ==  r-1 && current_c ==  c-1 ) {
            return 1;
        }

        if(dp[current_r][current_c] != 0) {
            return dp[current_r][current_c];
        }

        //  recursion
        if(current_r+1 < r)  //row is there
            waysCount += uniquePaths(r, c, current_r+1, current_c, dp);
        if(current_c+1 < c) // coulmn is there
            waysCount += uniquePaths(r, c, current_r, current_c+1, dp);

        dp[current_r][current_c] = waysCount;
        return waysCount;
    }
};
