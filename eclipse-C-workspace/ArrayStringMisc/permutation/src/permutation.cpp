//============================================================================
// Name        : permutation.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/**
 Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
 */
#include <iostream>
#include <vector>

using namespace std;

void permuteRecursion(vector<int> nums, int currentIndex, vector<int> staging, vector<vector<int>>& results) {
	//base case
	if(currentIndex == nums.size()) {
		results.push_back(staging);
		staging.clear();
		return ;
	}

	//recursion case
	for (uint i = currentIndex; i < nums.size(); i++) {
		staging[currentIndex]=nums[i];
		swap(nums[i], nums[currentIndex]);
	/*	cout << "nums\n";
		for(int x : nums)
			cout << x <<", ";
		cout << endl;
		cout << "staging\n";
		for(int x : staging)
			cout << x <<", ";
		cout << endl;
		cout << "currentIndex: "<< currentIndex << " I: " << i << endl;
		*/
		permuteRecursion(nums, currentIndex+1, staging, results);
	}

	return ;

}


vector<vector<int>> permute(vector<int>& nums) {

	vector<int> buffer(nums.size());
	buffer.reserve(nums.size());
	vector<vector<int>> results;

	permuteRecursion(nums, 0, buffer, results);

	return results;
}

int main() {

	vector <int> input{1,2,3};


	vector<vector<int>> results = permute(input) ;
	for(uint i=0; i <  results.size(); i++) {

		cout << "[";
		for(uint j = 0; j< results[i].size(); j++) {
			cout << results[i][j] << ',';
		}
		cout << "]\n";
	}	return 0;
}
