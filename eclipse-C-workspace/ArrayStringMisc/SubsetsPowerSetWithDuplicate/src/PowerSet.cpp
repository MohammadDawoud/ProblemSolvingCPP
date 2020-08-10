//============================================================================
// Name        : spriral_print.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
//============================================================================

#include <iostream>
#include <vector>
#include <cstddef>

using namespace std;

void getSet (vector<pair<int, int>> uniqueList, vector<int> buffer , int currentIndex, vector<vector<int>> & results  ) {

	if(currentIndex == (int)uniqueList.size()) {
		results.push_back(buffer);
		return;
	}

	int val = uniqueList[currentIndex].first;
	if(uniqueList[currentIndex].second > 1) {
		uniqueList[currentIndex].second -= 1;
		getSet(uniqueList, buffer, currentIndex+1, results); // Adding one to insure I will skip the duplicate element when it is absent case
		buffer.push_back(val);
		getSet(uniqueList, buffer, currentIndex, results);
	}
	else {
		getSet(uniqueList, buffer, currentIndex+1, results);
		buffer.push_back(val);
		getSet(uniqueList, buffer, currentIndex+1, results);
	}



}


vector<pair<int, int>>  consolidate (const vector<int>& nums) {

	vector <pair<int, int>> data;
	//data.reserve(5);
	cout << "the size of the vector " <<data.size() << endl;

	bool found = false;
	for(int val : nums) {
		found=false;
		for(uint i=0; i< data.size(); i++) {
		  if (data[i].first== val) {
			  found = true;
			  data[i].second+=1 ;
			  break;
		  }
		}
		if (!found)
			data.push_back(make_pair(val,1));

	}

	return data;

}

vector<vector<int>>
  subsets(vector<int>& nums) {
	vector<vector<int>> result(4);

	vector<pair<int, int>> uniqueList = consolidate ( nums);
	vector<vector<int>> results;
	vector<int>buffer;
	getSet(uniqueList, buffer , 0, results);


	return results;
}


int main() {

	vector <int> input{1,2,2};

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





