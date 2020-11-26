/*
 * Graph.h
 *
 *  Created on: Nov 14, 2020
 *      Author: david
 */

#ifndef GRAPH_H_

#define GRAPH_H_

#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <set>


using namespace std;

template <typename T>
class Graph {

	unordered_map <T, list<T>> nodes;

public:
	void addEdge(T n1, T n2) {
		nodes[n1].push_back(n2);
		nodes[n2].push_back(n1);
	}


	void dfs(T n, set<T> & visited) {
		if(visited.count(n) > 0)
			return;
		cout << n << endl;
		visited.insert(n);
		for(T node : nodes[n]) {
			dfs(node, visited);
		}

	}


	void bfs(T n) {
		queue<T> buffer;
	    set<T>  visited;
		buffer.push(n);
		visited.insert(n);
		while(buffer.empty() == false) {
			T tmp = buffer.front() ;
			buffer.pop();
			cout << tmp << endl ;

		//	visited.insert(tmp);
			if(this->nodes.count(tmp) > 0 ){
				list<T> connectedNodes = this->nodes[tmp];
				for(T node :  connectedNodes) {
					if(visited.count(node) == 0) {
						buffer.push(node);
						visited.insert(node);
						cout << "	"<<">>" << node<< endl;
					}
				}
			}

		}
	}


	void dfs(T n) {
		set<T> visited;
		dfs(n, visited);
	}

	int conncetedIsladCount() {
		set<T> visited;
		int islandCount= 0;
		for(auto p : nodes) {
			if(visited.count(p.first) == 0) {
				dfs(p.first, visited);
				islandCount++;
			}

		}
		return islandCount;

	}
};



#endif /* GRAPH_H_ */
