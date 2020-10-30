//============================================================================
// Name        : MinimumWindowSubstring.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 76. Minimum Window Substring

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
 */



#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


class Solution {
public:


    bool validate(unordered_map <char, int> frequancySource, unordered_map <char, int> frequancyTarget) {
        for( auto p : frequancyTarget) {
            if(frequancySource.find(p.first) == frequancySource.end())
                return false;
            if(frequancySource[p.first] < p.second)
                return false;

        }

        return true;
    }

    string minWindow(string s, string t) {

        string result =""; // empty is special case
        unordered_map <char, int> frequancyTarget;
        unordered_map <char, int> frequancySource;

        for(char c : t) {
            frequancyTarget[c]++;
        }


        int left =0;
        int right =0;

        for(; right < s.size(); right ++ ) {

            if(frequancyTarget.find(s[right]) != frequancyTarget.end()) {
                frequancySource[s[right]] ++ ;
            }

            // validata is it good sample
            // has to be removed to save time
           bool isGood = validate(frequancySource, frequancyTarget);

            // contract left pointer as long as it will stay good sample
        //    cout << s.substr(left, right-left+1) << endl;
       //     if(s.substr(left, right-left+1) =="CODEBANC") {
       //         cout << s[left]<< ">>" << frequancySource[s[left]]  <<endl;
       //         cout << s[left]<< ">>" << frequancyTarget[s[left]]  <<endl;
        //    }
            while( left <= right && (frequancyTarget[s[left]] == 0 || frequancySource[s[left]] > frequancyTarget[s[left]])) {
                if(frequancySource[s[left]] > 0)
                    frequancySource[s[left]]--;
                left++;
        //        cout << s[left]<< ">>" << frequancySource[s[left]]  <<endl;
        //        cout << s[left]<< ">>" << frequancyTarget[s[left]]  <<endl;

            }


            // for everygood sample store in if the length is smaller than result

            if(isGood) {
                string tmp = s.substr(left, right-left+1);
                if(result=="") {
                    result=tmp;
                }
                else
                    result = (result.size() < tmp.size() )?  result: tmp;
            }

        }

        return result;
    }
};

int main() {
	cout << "" << endl; // prints 
	return 0;
}
