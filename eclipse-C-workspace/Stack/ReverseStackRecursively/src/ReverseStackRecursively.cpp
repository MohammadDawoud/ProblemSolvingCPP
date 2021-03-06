//============================================================================
// Name        : ReverseStackRecursively.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
using namespace std;

void insertAtButtom(int input, stack<int> & st) {
	if(st.empty()) {
		st.push(input);
		return;
	}
	int top= st.top();
	st.pop();
	insertAtButtom(input, st);
	st.push(top);
}

void reverseStack(stack<int> & st) {

	if(st.empty())
		return;

	int top = st.top();
	st.pop();
	reverseStack(st);
	insertAtButtom(top, st);
}

int main() {
	stack <int> st ;

	for(int i=0; i< 5; i++) {
		st.push(i);
	}

	reverseStack(st);

	for(int i=0; i< 5; i++) {
		cout<< st.top() << ", ";
		st.pop();
	}

	return 0;
}
