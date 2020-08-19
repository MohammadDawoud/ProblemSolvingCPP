//============================================================================
// Name        : Trie.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

/*
 421. Maximum XOR of Two Numbers in an Array

Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
 */

class Node {
public:
	int value;
	Node* zero;
	Node* one;

	Node(int value) {
		this->value =  value;
		zero =  nullptr;
		one = nullptr;
	}

};

class Trie {
public:
	Node *root;
	Trie(){
		root = new Node(-1);
	}

	void insert(int input) {
		stack<bool> bits ;
		for(int i=0; i < 32; i++) {
			bits.push(input&1);
			input = input >> 1;
		}

		Node * tmp = root;
		for(int i=0; i < 32; i++) {
			bool bit = bits.top();
			bits.pop();

			if(bit) {
				if(tmp->one == nullptr) {
					tmp->one =  new Node(1);
				}
				tmp = tmp->one;
			} else {
				if(tmp->zero == nullptr) {
					tmp->zero =  new Node(0);
				}
				tmp = tmp -> zero;
			}
		}
	}

	int getMaxXor(int input) {

		insert(input);

		int Xor = 0;
		stack<bool> bits ;
		for(int i=0; i < 32; i++) {
			bits.push(input&1);
			input = input >> 1;
		}

		Node * tmp = root;
		for(int i=0; i < 32; i++) {
			bool bit = bits.top();
			bits.pop();

			if(bit) {
			// is one, traverse to zero if exists
				if(tmp->zero != nullptr) {
					Xor += 1 << (31-i);
					tmp =  tmp->zero;
				} else
					tmp =  tmp->one;  // I am sure one is there as I just inserted the input into Trie


			}
			else {
				// is zero, traverse to one if exists
				if(tmp->one != nullptr) {
					Xor += 1 << (31-i);
					tmp =  tmp->one;
				} else
					tmp =  tmp->zero;  // I am sure zero is there as I just inserted the input into Trie
			}
		}

		return Xor;


	}

};


int findMaximumXOR(vector<int>& nums) {
	Trie *t = new Trie();
	int xorv = 0;
	int maxXor =  INT_MIN;


	for(int i =0; i < nums.size(); i++) {
	  xorv = t->getMaxXor(nums[i]);
	//  cout << "  xorv = " << xorv ;
	  maxXor =  max(xorv, maxXor);
	}
	//cout << endl;
	return maxXor;
}

int main() {

  int input[] = {3, 10, 5, 25, 2, 8};
  Trie *t = new Trie();
  int xorv = 0;
  int maxXor =  INT_MIN;


  for(int i =0; i < 6; i++) {
	  xorv = t->getMaxXor(input[i]);
	  cout << "  xorv = " << xorv ;
	  maxXor =  max(xorv, maxXor);
  }
  cout << endl;

	return maxXor;
}
