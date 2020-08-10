//============================================================================
// Name        : spriral_print.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
//============================================================================

#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

vector<int> getSet(int i, vector<int>& nums) {


	vector<int> set;
	set.reserve(3);
	int firstBit =0;
	int c = 0;
	while (i>0) {
		firstBit = (i&1);
		if(firstBit == 1) {
			set.push_back(nums[c]);
		}
		c++;
		i = i >> 1;

	}
	return set;

}
vector<vector<int>> subsets(vector<int>& nums) {

	uint size = nums.size();
	uint numberOfSets = (1<<size)-1;
	vector<vector<int>> result;
	result.reserve(size);

	vector<int> set;
	//set.reserve(3);

	for(uint i=0; i<= numberOfSets ; i++) {
		set =  getSet(i, nums);
		result.push_back(set);
	}
	return result;
}


int main() {

	vector <int> input{1,2,3};

	subsets(input);

	vector<vector<int>> result = subsets(input) ;

	for(uint i=0; i <  result.size(); i++) {

		cout << "[";
		for(uint j = 0; j< result[i].size(); j++) {
			cout << result[i][j] << ',';
		}
		cout << "]\n";
	}

	return 0;
}
