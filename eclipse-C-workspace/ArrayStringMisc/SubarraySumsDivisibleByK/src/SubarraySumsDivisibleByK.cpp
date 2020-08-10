//============================================================================
// Name        : SubarraySumsDivisibleByK.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 *
 * Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.



Example 1:

Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]


Note:

1 <= A.length <= 30000
-10000 <= A[i] <= 10000
2 <= K <= 10000
 *
 * */
#include <iostream>
#include <vector>

using namespace std;


int subarraysDivByK(vector<int>& A, int K) {

	vector<int> mods (A.size()) ;  // just for debug
	vector<int> occurance(K,0)  ;
	occurance[0] = 1; // zero is special case. not for empty case as explained.
	int mod = 0;
	int sum = 0;

	for(uint i =0 ; i <  A.size(); i++) { // get all mods for the accumulated sum
		sum += A[i];
		mod = (sum%K+K)%K;
		mods[i]= mod;
		occurance[mod]++;
	}

	int result = 0;
	for(uint i = 0; i < occurance.size(); i++) {
		int count = occurance[i];
		result += count*(count-1)/2;   // count of combinations of 2
	}
	return result;
}


int main() {
	 /* prints leet code 974. Subarray Sums Divisible by K
	Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.



	Example 1:

	Input: A = [4,5,0,-2,-3,1], K = 5
	Output: 7
	Explanation: There are 7 subarrays with a sum divisible by K = 5:
	[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
	*/


	vector<int> in = {4,5,0,-2,-3,1};
	int k = 5;

   cout << subarraysDivByK(in, k);

	return 0;
}
