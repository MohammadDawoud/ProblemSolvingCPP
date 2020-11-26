

//============================================================================
// Name        : ConnectedComponent.cpp
// Author      : Mohamed Dawoud
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style


//calculate number of islands in the graph
//============================================================================

#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <set>
#include <./Graph.h>


using namespace std;


int main() {
	Graph<int> g;

	g.addEdge(0,3);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(3,2);
	g.addEdge(0,4);

	g.addEdge(5,5);
	g.addEdge(6,6);

	int resut = g.conncetedIsladCount() ;
	cout <<"connectedCount==" << resut << endl;

	return 0;
}



