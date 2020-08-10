//============================================================================
// Name        : OnlineStockSpan.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
901. Online Stock Span

Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].



Example 1:

Input: ["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
Output: [null,1,1,1,2,1,4,6]
Explanation:
First, S = StockSpanner() is initialized.  Then:
S.next(100) is called and returns 1,
S.next(80) is called and returns 1,
S.next(60) is called and returns 1,
S.next(70) is called and returns 2,
S.next(60) is called and returns 1,
S.next(75) is called and returns 4,
S.next(85) is called and returns 6.

Note that (for example) S.next(75) returned 4, because the last 4 prices
(including today's price of 75) were less than or equal to today's price.


Note:

Calls to StockSpanner.next(int price) will have 1 <= price <= 10^5.
There will be at most 10000 calls to StockSpanner.next per test case.
There will be at most 150000 calls to StockSpanner.next across all test cases.
The total time limit for this problem has been reduced by 75% for C++, and 50% for all other languages.
 */


class StockSpanner {
public:
	stack<pair<int,int>> st; // first represent the span number and second the price
	inline static int numberOfDays  = 0;
    StockSpanner() {
    	st = stack <pair<int,int>> ();
    }

    int next(int price) {

    	numberOfDays++;
    	int span=0;
    	while(st.empty() == false) {
    		pair<int,int> last = st.top();
    		if(price >  last.second) {
    			st.pop();
    		}
    		else {
    			span = numberOfDays-last.first;
    			st.push(make_pair(numberOfDays, price));
    			break;
    		}
    	}

    	// edge case when the stack is empty
		if(st.empty() == true) {
			span = numberOfDays;
			st.push(make_pair(numberOfDays, price));
		}

		return span;
    }
};


int main() {
	StockSpanner S = StockSpanner();
/*
  	cout << S.next(100) << endl; // is called and returns 1,
	cout << S.next(80) << endl;  // is called and returns 1,
	cout << S.next(60) << endl;  // is called and returns 1,
	cout << S.next(70) << endl;  // is called and returns 2,
	cout << S.next(60) << endl;  // is called and returns 1,
	cout << S.next(75) << endl;  // is called and returns 4,
	cout << S.next(85) << endl;  // is called and returns 6.
["StockSpanner","next","next","next","next","next"]
[[],[85],[76],[43],[26],[52]]
*/
  	cout << S.next(85) << endl; // is called and returns 1,
	cout << S.next(76) << endl;  // is called and returns 1,
	cout << S.next(43) << endl;  // is called and returns 1,
	cout << S.next(26) << endl;  // is called and returns 1,
	cout << S.next(52) << endl;  // is called and returns 3,


	return 0;
}
