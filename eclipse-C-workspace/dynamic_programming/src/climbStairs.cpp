//============================================================================
// Name        : dynamic_programming.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 *
 * 70. Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step


Constraints:

1 <= n <= 45
 */
#include <iostream>
#include <unordered_map>
using namespace std;


int climbStairs_dp(int n, std::unordered_map<int, int> & dp) {
    int count = 0;


    // base case
    if(n <=0)
        return 1;
    if(n ==1)
        return 1;
    // recursion case

    if(dp.count(n) > 0 ) {
        return dp[n];
    }
    count = climbStairs_dp(n-1, dp) + climbStairs_dp(n-2, dp);
    dp[n] = count;
    return count;
}

 int climbStairs ( int n) {

     std::unordered_map<int, int> dp;
     return climbStairs_dp( n,  dp);

 }

int main() {
	cout << "" << endl; // prints 
	return 0;
}
