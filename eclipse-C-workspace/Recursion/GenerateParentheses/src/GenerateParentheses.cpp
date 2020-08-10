//============================================================================
// Name        : GenerateParentheses.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


/*
 * Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 */


#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

void generateParenthesisRecursion(vector <string> & results, int open, int close, char *buffer, int bufIndex){

	//base cases
	if(close < open)
		return; // invalid case

	if(close == 0 && open == 0) {
		results.push_back(buffer);
		return;
	}


	// rec case
	if(open > 0) {
		buffer[bufIndex] = '(';
		generateParenthesisRecursion(results, open-1, close, buffer, bufIndex+1);
	}

	if(close>0) {
		buffer[bufIndex] = ')';
		generateParenthesisRecursion(results, open, close-1, buffer, bufIndex+1);
	}
}


vector<string> generateParenthesis(int n) {
   int open = n;
   int close = n;
   char buffer[1000]= {'\0'};

   vector <string> results ;
   generateParenthesisRecursion(results, open, close, buffer, 0);

   return results;
}


int main() {
	 vector <string> results  = generateParenthesis(3);
	for(string s : results)
	   cout << s << endl;
	return 0;
}
