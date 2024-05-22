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

// This Algorithm works for directed graph
// This algorithm is used to find out all the strongly connected components within a graph --> A strongly connected component is the component of a directed graph
// that has a path from every vertex to every other vertex in that component. It can only be used in a directed graph.

/*
Approach :
    Step 1 --> Order the vertices in decreasing order of there finish times in DFS. (can be done using stack)
    Step 2 --> Reverse all the edges
    Step 3 --> Do DFS of the reversed graph in the order obtained in step1.
                For every vertex , print all reachable vertices as on strongle connected component.
*/

void topo(int src, unordered_map<int, list<int>> &adj, stack<int> &s, vector<bool> &visited)
{
    visited[src] = true;
    for (auto x : adj[src])
    {
        if (!visited[x])
        {
            topo(x, adj, s, visited);
        }
    }
    s.push(src);
}

void dfsRec(int node, unordered_map<int, list<int>> adj, vector<bool> visited)
{
    visited[node] = true;
    for (auto nbr : adj[node])
    {
        if (!visited[nbr])
        {
            dfsRec(nbr, adj, visited);
        }
    }
}

int kosaraju(int v, vector<vector<int>> &edges)
{
    // create adjacency list
    unordered_map<int, list<int>> adj; // Here we can also use vector<vector<int>> v to create a adjacency list
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    // topological sorting

    /*
    Here for creating boolean visited --> we can use two approaches
    1. using unordered map like ---> unordered_map<int,list<int>> adj
    2. using 2D vectors like --->    vector<vector<int>> vec;
    */

    stack<int> s;
    vector<bool> visited(v, false);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topo(i, adj, s, visited);
        }
    }

    //  Create a transpose graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        for (auto nbr : adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }

    // Simply doing DFS for the above stored order in the stack
    int count = 0;
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        if (!visited[top])
        {
            count++;
            dfsRec(top, adj, visited);
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{

    return 0;
}

// Transpose means we are reversing the direction of every edge in the directed graph
// Time complexity is O(V+E)