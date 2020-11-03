/*
 64. Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        if(grid.empty()) {
            return 0;
        }

        vector<vector<int>> dp = vector<vector<int>>(grid.size(), vector<int> (grid[0].size(), 0));
        dp[0][0] = grid[0][0];
        int result = minPathSum( grid, dp);
        return result;
    }

    int minPathSum(vector<vector<int>>& grid, vector<vector<int>>& dp) {


        for(uint r=0; r < grid.size(); r++) {
            for(uint c=0; c < grid[0].size(); c++) {

                // first row
                if(r==0 && c != 0) {
                  dp[r][c] += grid[r][c] + dp[r][c-1];
                }
                // first column
                else if(c == 0 && r !=0) {
                    dp[r][c] += grid[r][c] +dp[r-1][c];
                }

                // other cells
                else if (r != 0 && c != 0) {
                    dp[r][c] += grid[r][c] + min(dp[r][c-1],dp[r-1][c]);
                }
            }
        }

        return dp[dp.size()-1][dp[0].size()-1];
    }

};
