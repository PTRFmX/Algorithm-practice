/**
 * Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.
 * The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
    public: 
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            vector<vector<int>> paths;
            vector<int> path;
            if(graph.size() == 0) {
                return paths;
            }
            dfs(graph, paths, path, 0, graph.size() - 1);
            return paths;
        }

        void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int> path, int start, int end) {
            path.push_back(start);
            if(start == end) {
                ans.push_back(path);
                return;
            }
            for(int i = 0; i < graph[start].size(); i++) {
                dfs(graph, ans, path, graph[start][i], end);
            }
        }
    
};

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int size = readNumber();
        vector<vector<int>> graph;
        for(int j = 0; j < size; j++) {
            int vec_size = readNumber();
            vector<int> vec = readVector(vec_size);
            graph.push_back(vec);
        }
        Solution solution;
        solution.allPathsSourceTarget(graph);
    }
    return 0;
}