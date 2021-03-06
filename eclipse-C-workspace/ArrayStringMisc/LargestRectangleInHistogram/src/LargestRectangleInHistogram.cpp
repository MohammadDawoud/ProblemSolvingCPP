//============================================================================
// Name        : LargestRectangleInHistogram.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 84. Largest Rectangle in Histogram

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.




Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].




The largest rectangle is shown in the shaded area, which has area = 10 unit.



Example:

Input: [2,1,5,6,2,3]
Output: 10
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int area = 0;
    stack <int> st = stack<int>();
    // just to avoid special cases and make the code simpler
    // adding zero and beginning and at the end of the vector
    vector <int> v = heights;
    v.insert(v.begin(), 0);
    st.push(0);
    v.push_back(0);


    for(uint i =1; i < v.size(); i++) {
    	// if current height is greater than height in the stack
    	// push it into stack to calculate it late
    	// if current height is less height in the stack
    	// keep popping and calculate the area to each pop()
    	int topIndex = st.top();
    	if ( st.empty() || v[i] >= v[topIndex]) {
    		st.push(i);
    	} else {
    		while( st.empty()  == false && v[i] < v[topIndex]) {
    			// pop
    			// calculate area
    			int currentHieght = v[topIndex];
    			st.pop();
    			topIndex =  st.top();
    			int currentArea = currentHieght *(i-topIndex-1);
    			area = max(currentArea,area);

    		}
    		st.push(i);
    	}
    }
	return area;
}


int main() {
	vector <int> v {2,1,2};
	cout << largestRectangleArea(v);
	return 0;
}
