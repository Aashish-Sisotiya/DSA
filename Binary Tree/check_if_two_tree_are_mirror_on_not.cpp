#include <vector>
#include "bits/stdc++.h"

bool checkMirror(int n, vector<vector<int>> &edgesA, vector<vector<int>> &edgesB)
{
    // Write your code here.
    // can be done through recursion or iteratively if the root of the tree is given
    // Tc ---> O(2*e) where e is the number of the edges
    unordered_map<int, stack<int>> map; // beacuse at every level we have to check the order of the nodes , if we push the nodes of the edgeA in the map then while traversing edgesB we only need to check if the node at top is equla or not

    for (auto it : edgesA)
    {
        map[it[0]].push(it[1]);
    }
    // stack of 1  [4]
    //             [3]
    //             [2]
    // check if the node in map[0], map[1]  and so on  are in reverse order while traversing in edgesB

    for (auto it : edgesB)
    {
        if (map[it[0]].top() != it[1])
            return false;
        map[it[0]].pop();
    }
    return true;
}