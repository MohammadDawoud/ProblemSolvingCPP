/*
 * longestCommonSequence.cpp
 *
 *  Created on: Oct 31, 2020
 *      Author: david
 */

#include <iostream>
#include <string.h>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:


    // Only for pairs of std::hash-able types for simplicity.
// You can of course template this struct to allow other hash functions
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;
    }
};

    int longestCommonSubsequence(string text1, string text2) {

       // unordered_map  <pair<int, int>,  int, pair_hash> dp;
       // return longestCommonSubsequence_dp(text1, text2, 0, 0, dp);

       vector <vector<int>> buffer (text1.length()+1, vector<int>(text2.length()+1, 0)) ;

        for(int i =0; i < text1.length(); i++)
            for(int j=0; j< text2.length(); j++) {
                if(text1[i] == text2[j]) {    // take the diagonal and add 1
                    buffer[i+1][j+1] = buffer[i][j]+1;
                }
                else
                    buffer[i+1][j+1] = max(buffer[i][j+1], buffer[i+1][j]);
            }

        return buffer[text1.length()][text2.length()];

    }








    int longestCommonSubsequence_dp(string text1, string text2, int i, int j, unordered_map  <pair<int, int>,  int, pair_hash> & dp) {

        int ans = 0;
        //base case
        if(i == text1.length() || j == text2.length()) {
            return 0;
        }


        pair<int, int> tmp (i,j);
           //         cout << "outside";

        if(dp[tmp] > 0) {
            return dp[tmp];
        }

        // recursion case
        if( text1[i] == text2[j]) {


            ans = 1+longestCommonSubsequence_dp(text1, text2, i+1, j+1, dp);
        }
        else {
            int opt1 = longestCommonSubsequence_dp(text1, text2, i+1, j, dp);
            int opt2 = longestCommonSubsequence_dp(text1, text2, i, j+1, dp);
            ans += max(opt1, opt2);

        }

        dp[make_pair(i,j)]=ans;

        return ans;
    }

};
