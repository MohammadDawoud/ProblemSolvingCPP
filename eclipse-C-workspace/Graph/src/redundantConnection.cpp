/*
 * redundantConnection.cpp
 *
 *  Created on: Nov 26, 2020
 *      Author: david
 */

/*
 684. Redundant Connection
Medium

1688

233

Add to List

Share
In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

Update (2017-09-26):
We have overhauled the problem description + test cases and specified clearly the graph is an undirected graph. For the directed graph follow up please see Redundant Connection II). We apologize for any inconvenience caused.
 */

#include<iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        populateNodes(edges);  // create the graph
        set<int> visited;
        vector<int> path;
     //   path.push_back(*nodes.begin());
        dfs(*nodes.begin(), this->edges, visited, -1, path);



       return getLastEdege(path, edges);
    }

    set<int> nodes;
    unordered_map <int, set<int>> edges;
    void populateNodes(vector<vector<int>>& edgesVec) {
        for(vector<int> x : edgesVec) {
            nodes.insert(x[0]);
            nodes.insert(x[1]);

            edges[x[0]].insert(x[1]);
            edges[x[1]].insert(x[0]);

        }
     /*   for(int x : nodes)
            cout << x << ", ";
        cout << endl;
     */
    }


    bool  dfs (int currentNode, unordered_map <int, set<int>> &edges, set<int> &visited, int parent, vector<int>& path ) {
       // cout << currentNode << ", ";
        set <int> childNodes = edges[currentNode];
        vector<int>  result;
        path.push_back(currentNode);

        if(visited.count(currentNode) > 0) {  // visited then it is aloop and redundant // base case of recursion
            return true;
        }

        visited.insert(currentNode);

        for(int x : childNodes) {
            if(x == parent)
                continue;

           bool answer = dfs(x, edges, visited, currentNode, path);


            if(answer)
                return true;

        }
        path.pop_back();    // back tracking
        return false;
    }


  vector <int> getLastEdege(vector<int>& path, vector<vector<int>>& edges) {
      int lastNode =  path.back();
      int lastEdgeIndex = -1;
      int i = 0;
      for(; i < path.size(); i++)
      {
          if(path[i] == lastNode )
              break;
      }

      for(; i < path.size()-1; i++) {
     //     cout << "index=" << i << " value =" << path[i] << endl;
          vector<int> tmp = vector<int>();
          tmp.push_back(min(path[i],path[i+1]));
          tmp.push_back(max(path[i],path[i+1]));

          for(int j = 0; j< edges.size(); j++) {
           //   cout << "tmp ==" << tmp[0] << ","<< tmp[1] << "edge" << x[0] << ","<< x[1]<< endl;
              if(tmp[0] == edges[j][0] && tmp[1] == edges[j][1])
                  lastEdgeIndex = max(lastEdgeIndex, j);
          }
      }

      return edges[lastEdgeIndex];

  }



};
