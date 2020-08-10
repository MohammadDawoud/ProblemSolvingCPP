//============================================================================
// Name        : LetterCombinationsofPhoneNumber.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


/*
 *
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
 * */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void letterCombinationsRecursion(vector<string> input, int inputIndex,vector<string> &results, char buffer [], int buffIndex) {

	// base case
	if (inputIndex == input.size()) {
		results.push_back(buffer);
		return;
	}

	string inputElement = input[inputIndex];

	for(char ch : inputElement) {
		buffer[buffIndex] = ch;
		letterCombinationsRecursion(input, inputIndex+1, results, buffer, buffIndex+1);

	}


}


vector<string> letterCombinations(string digits) {
	vector<string> results;
	const char *lookup [] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

	char buffer [10] = {'\0'} ;
	int buffIndex = 0;

	int index = 0;
	char * lookupElement = nullptr ;
	vector<string> input; // list of string of each digit

	for(char d : digits) {
		int index = d-'0';
		input.push_back(lookup[index]);

	}

	if(digits.size() == 0)
		return results;

	letterCombinationsRecursion(input, 0 ,results, buffer, 0);


	return results;
}


int main() {

	vector<string> results =  letterCombinations("23");

	for(string s : results)
		cout << s << endl;


	return 0;
}
