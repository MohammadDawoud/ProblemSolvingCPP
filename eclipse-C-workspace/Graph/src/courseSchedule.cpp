/*
 * courseSchedule.cpp
 *
 *  Created on: Nov 24, 2020
 *      Author: david
 */

/*
210. Course Schedule II
Medium


There are a total of n courses you have to take labelled from 0 to n - 1.

Some courses may have prerequisites, for example, if prerequisites[i] = [ai, bi] this means you must take the course bi before the course ai.

Given the total number of courses numCourses and a list of the prerequisite pairs, return the ordering of courses you should take to finish all courses.

If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.



Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]


Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.

*/
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        CourseNet courseNet;
        for(int i=0; i< numCourses; i++) {
            courseNet.add(i);
        }
        for(vector<int> v : prerequisites) {
          courseNet.addEdge(v[1],v[0]);
        }

        vector<int> result;
        vector<int> order = courseNet.getOrderBfs();
        for(int tmp : order) {
            result.push_back(tmp);
        }

        return result;


    }

    class CourseNet {
        unordered_map<int, int> nodesWithRank; // node value and rank (how many parent for it)
        unordered_map <int, list<int>> edges;

    public:
        void addEdge(int n1, int n2) {
            edges[n1].push_back(n2);
            nodesWithRank[n2]++;  // adding number of parent of N2
        }

        void add(int n1) {
            nodesWithRank.insert(make_pair(n1,0));
        }

        void dfs(int n, list<int>& order, set<int> & visited) {  // the problem in DFS is that it does not detect loop
            if(visited.count(n) > 0)
                return;
            cout << n << endl;
            visited.insert(n);
            for(int node : edges[n]) {
                dfs(node, order, visited);
            }

            order.push_front(n);

        }

        list <int> getOrderDfs() {
            set<int> visited;
            list<int> order;

       /*     for(int n : nodes) {
                dfs(n, order, visited);
            }
         */
            return order;
        }



        vector <int> getOrderBfs() {
            vector<int> order;
            order = bfs();

            return order;
        }

        vector<int> bfs() {
            queue<int> staging;
            set<int> visited;
            vector<int> order;

            for(auto p : nodesWithRank) {
                if(p.second == 0) {
                    staging.push(p.first);
                   // cout<<"Node "<< staging.front()<<endl;

           //         order.push_back(p.first);
                }
            }


            if(staging.empty())
                return order;

            while(staging.empty() != true ) {
                int currentNode = staging.front();
                staging.pop();

                visited.insert(currentNode);
                order.push_back(currentNode);
           //     cout<<"Node "<< currentNode<<endl;

                // reduce the rank of its children
                for(int tmpNode  : edges[currentNode]) {
                    nodesWithRank[tmpNode] --;
                    if(nodesWithRank[tmpNode] == 0)
                        staging.push(tmpNode);
                }


            }

            if(order.size() != nodesWithRank.size()) {
                order.clear();
            }

            return order;

        }




    };

};

