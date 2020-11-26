//============================================================================
// Name        : Graph.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>          // std::queue
#include <set>
#include <./Graph.h>


using namespace std;






int main1() {
	Graph<int> g;

	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(2,4);

	g.bfs(1);

	return 0;
}
