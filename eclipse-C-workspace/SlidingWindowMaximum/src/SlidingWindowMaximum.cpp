//============================================================================
// Name        : SlidingWindowMaximum.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque <int> sliding; // indexes of sliding window
    result.reserve(nums.size());

    // calculate for the first sliding window for K steps get the max
    uint i=0;
    sliding.push_back(0);
    for(i=1; i < k; i++) {
    	while(sliding.empty() == false && nums[i] > nums[sliding.back()]){
    			sliding.pop_back();
    	}
    	sliding.push_back(i);
    }

    result.push_back(nums[sliding.front()]);


    // calculate for the rest for each step. get the max
    for(; i < nums.size(); i++) {
    	while( sliding.empty() == false && sliding.front() <= i-k) {
    		sliding.pop_front();
    	}
    	while(sliding.empty() == false && nums[i] > nums[sliding.back()]){
			sliding.pop_back();
    	}
    	sliding.push_back(i);

    	result.push_back(nums[sliding.front()]);
    }


	return result;

}
int main() {

	vector<int> v {1};
	 v = maxSlidingWindow(v,1);


	 for(int i =0; i< v.size(); i++) {
		 cout << v[i] << ", ";
	 }
	return 0;
}
