//============================================================================
// Name        : hash_pair.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include<unordered_map>
using namespace std;

// A hash function used to hash a pair of any kind
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int main()
{
    // Sending the hash function as a third argument
    unordered_map<pair<int, int>, int, hash_pair> um;

    // Creating some pairs to be used as keys
    pair<int, int> p1(1000, 2000);
    pair<int, int> p2(2000, 3000);
    pair<int, int> p3(2005, 3005);

    // Inserting values in the unordered_map.
    um[make_pair(1000, 2000)] = 1;
   // um[p2] = 2;
    //um[p3] = 3;

    cout << "Contents of the unordered_map : \n";
    for (auto p : um)
        cout << "[" << (p.first).first << ", "
             << (p.first).second << "] ==> "
             << p.second << "\n";


    pair<int, int> tmp (1000, 2000);
    if(um.count(tmp) > 0){
    	cout << um[tmp] << endl;
    }

    return 0;
}
