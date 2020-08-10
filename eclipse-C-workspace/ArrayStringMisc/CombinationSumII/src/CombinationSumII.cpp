//============================================================================
// Name        : CombinationSumII.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


/*
40. Combination Sum II



Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combinationSumRec(vector<int>& candidates, int target, int index, vector<int> buffer, vector<vector<int>>& results) {
	//base
	if(target == 0) {
		results.push_back(buffer);
		return;
	}

	if (candidates.size() == index)
		return;

	//recursion
	combinationSumRec(candidates, target, index+1, buffer, results);
	if (target >=  candidates[index]) {
        // to skip duplicate e.g. [1,1,7] I don't want to consider 1,7 and 1,7 twice.
        if( index >=1   && candidates[index] == candidates[index-1] && ( buffer.size() == 0 || buffer[buffer.size()-1] !=candidates[index]))
            return;
		buffer.push_back(candidates[index]);
		combinationSumRec(candidates, target-candidates[index], index+1, buffer, results);
	}

	return;

}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>>  results;
	vector<int> buffer;
    sort(candidates.begin(), candidates.end());
	combinationSumRec(candidates, target, 0, buffer, results);
	return results;
}

int main() {
	vector<int> candidates  {10,1,2,7,6,1,5};
	vector<int> candidates2  {10,1,2,7,6,1,5};

	if(candidates == candidates2) {
		cout << "true"<< endl;
	}

	vector<vector<int>> result = combinationSum2(candidates, 8);
	for(uint i=0; i <  result.size(); i++) {

		cout << "[";
		for(uint j = 0; j< result[i].size(); j++) {
			cout << result[i][j] << ',';
		}
		cout << "]\n";
	}
	return 0;
}
