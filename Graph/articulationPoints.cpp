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

void dfs(int node, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj, vector<int> &ap, int timer)
{
    vis[node] = true;
    timer++;
    disc[node] = timer;
    low[node] = timer;
    int child = 0;
    for (auto nbr : adj[node])
    {
        if (nbr == parent)
        {
            continue;
        }
        if (!vis[nbr])
        {
            dfs(nbr, node, disc, low, vis, adj, ap, timer);
            low[node] = min(low[node], low[nbr]);

            // check for AP
            if (low[nbr] >= disc[node] && parent != -1)
            {
                ap[node] = 1;
            }
            child++;
        }
        else // case for when the neighbour is not parent and that neighbor node is visited
        {
            // Back Edge
            low[node] = min(low[node], disc[nbr]);
        }
    }
    // Checking if the starting point is articulation point or not
    if (parent == -1 && child > 1)
    {
        ap[node] = 1;
    }
}

int main(int argc, char const *argv[])
{
    int v = 5;
    int e = 5;
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));

    // Adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // creating the data structures to be used
    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    unordered_map<int, bool> vis;
    vector<int> ap(v, 0);

    // dfs
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, disc, low, vis, adj, ap, timer);
        }
    }

    // Print Articulation point
    cout << "The Articulation points are : " << endl;
    for (int i = 0; i < v; i++)
    {
        if (ap[i] != 0)
        {
            cout << i << " ";
        }
    }

    return 0;
}

/* Articulation Points (Cut Vertices)  :: It follows for connected and undirected Graph
        --> It is a vertex removal of this vertex and its associated edges or related edges increases the number of connected components in graph to more than one.
            or makes two or more than two connected components.
            OR which causes the graph to become disconnected.
*/