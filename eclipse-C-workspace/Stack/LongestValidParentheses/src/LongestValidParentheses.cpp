//============================================================================
// Name        : LongestValidParentheses.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 32. Longest Valid Parentheses

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
 */
#include <iostream>
#include <stack>
using namespace std;

int longestValidParentheses(string s) {
 int maxCount = 0;


 stack <int> st;

 for(uint i=0; i<s.size(); i++){

	 // whenever there is ( push zero
	 // when we meet ) we increment the first zero and add it to the fist buffer
	 // the stack eventually will look like that 0,4,0,0,5,0,0,1  max is 5
	 if(s[i] == ')') {
		 bool consumed = false;
		 if(st.empty() == true) {
			 // invalid don't count
		 }
		 else { //valid case, increment running Count
			 int validCount = 0;
			 while( st.empty() == false && st.top() != 0 && st.top() != -1) {
				 validCount += st.top();
				 st.pop();
			 }

			 if(st.empty() == false && st.top() == 0) {
				 st.pop();
				 validCount++;
				 consumed = true;
			 }

			 st.push(validCount);

			 if (consumed == false) {
				 st.push(-1);
			 }
		 }
	 } else if(s[i] == '(')  {
		 st.push(0);
	 }
 }

 int runningCount = 0;
 while(st.empty()==false) {
     if(st.top() == 0 || st.top() == -1 ) {
		 maxCount = max(runningCount, maxCount);
		 st.pop();
		 runningCount = 0;
		 continue;
     }
     else {
    	 runningCount += st.top();
		 maxCount = max(runningCount, maxCount);
    	 st.pop();
     }

 }



 return maxCount*2;
}

int main() {
	int count = longestValidParentheses("(()()(");
	cout << count << endl; // prints
	return 0;
}
