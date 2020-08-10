//============================================================================
// Name        : stringSubsequences.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 * Take as input str, a string. We are concerned with all the possible subsequences of str. E.g.

a. Write a recursive function which returns the count of subsequences for a given string. Print the value returned.

b. Write a recursive function which prints all possible subsequences for a “abcd” has following subsequences “”, “d”, “c”, “cd”, “b”, “bd”, “bc”, “bcd”, “a”, “ad”, “ac”, “acd”, “ab”, “abd”, “abc”, “abcd”.given string (void is the return type for function).
Note: Use cin for input for C++

Input Format
Enter a string

Constraints
None

Output Format
Print all the subsequences in a space separated manner and isplay the total no. of subsequences.

Sample Input
abcd
Sample Output
 d c cd b bd bc bcd a ad ac acd ab abd abc abcd
16
Explanation
Print all possible subsequences of the given string.
 */
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


void getSubsequences (string input, int index, char buffer[], int bufferIndex, vector<string>& results) {

	if(index == input.length()) {
		results.push_back(buffer);
/*		for(int i=bufferIndex; i < sizeof(buffer); i++) { // clear the buffer
			buffer[i] = '\0';
		}
		*/
		return;
	}

	getSubsequences(input, index+1, buffer, bufferIndex,results);
	buffer[bufferIndex] = input[index] ;
	getSubsequences(input, index+1, buffer, bufferIndex+1, results);
	buffer[bufferIndex] = '\0' ; 	   // for back tracking and remove what is in the buffer from previous calls, it is better to have it as a vector

}



int main() {
	string s;
	cin >> s;
	vector <string> results;
	char buffer[s.length()+1] = {'\0'};
	getSubsequences (s, 0, buffer, 0,results);

	for(auto s : results) {
		cout << s << " ";
	}
	cout << endl << results.size() << endl;

	return 0;
}
