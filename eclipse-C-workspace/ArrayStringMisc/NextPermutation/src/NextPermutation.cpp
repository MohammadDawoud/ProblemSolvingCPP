//============================================================================
// Name        : NextPermutation.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void getPivotReplacement(int pivotIndex, vector<int>&  nums) {

	for(uint i=nums.size()-1; i>pivotIndex; i--)	{
		if(nums[pivotIndex] < nums[i]) { // pivot found
			swap(nums[pivotIndex] , nums[i]);
			break;
		}
	}

}

void nextPermutation(vector<int>& nums) {
	int pivotIndex = -1;
	for(uint i=nums.size()-1; i>0; i--)	{
		if(nums[i-1] < nums[i] ) { // pivot found
			pivotIndex=i-1;
			break;
		}
	}

	if(pivotIndex == -1) {
		reverse(nums.begin(), nums.end());
        return;
    }


	getPivotReplacement(pivotIndex, nums);

	reverse(nums.begin()+pivotIndex+1,nums.end());

}

int main() {

	vector <int> input {6,2,1,5,4,3,0};
	nextPermutation(input);
	return 0;
}
