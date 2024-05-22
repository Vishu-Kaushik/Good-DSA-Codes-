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


// Time COmplexity is O(V+E) and TC is also linear O(V+E)

void dfs(int node, int parent, int timer, vector<int> &disc, vector<int> &low, unordered_map<int, list<int>> adj, vector<bool> &vis, vector<vector<int>> &res)
{
    vis[node] = true;
    timer++;
    disc[node] = timer;
    low[node] = timer;
    for (auto nbr : adj[node])
    {
        if (nbr == parent)
        {
            continue;
        }
        if (!vis[nbr])
        {
            dfs(nbr, node, timer, disc, low, adj, vis, res);
            low[node] = min(low[node], low[nbr]);
            // check if that particular edge between current nbr and node is bridge or not
            if (low[nbr] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                res.push_back(ans);
            }
        }
        else // case for when the neighbour is not parent and that neighbor node is visited
        {
            // Back Edge
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        // this is undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1); // Discovery time of any node according to the timer
    vector<int> low(v, -1);  // THis contains the lowest possible time to discover a node
    int parent = -1;
    vector<bool> vis(v, false);

    // dfs
    vector<vector<int>> result;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, timer, disc, low, adj, vis, result);
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{

    return 0;
}

/*
Bridges --> A bridge in any graph is defined as an edge which, when removed , makes the graph disconnected (or more precisely increases the number of connected
            components in the graph)

*/