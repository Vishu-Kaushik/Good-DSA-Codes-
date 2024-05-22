#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;

// Minimum Spanning Tree --> When you convert a graph into a tree with n nodes and n-1 edges and such that each node is reachable from
//                          every other node

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    // Three Data structures that we need
    vector<int> key(n + 1, INT16_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // Algo
    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < n; i++)
    {
        int mini = INT16_MAX;
        int u;
        // find the min key value node
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }
        // Mark min node as true
        mst[u] = true;

        // Check its adjacent node
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}
