#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// DFS traversal for the disconnected graph where Time Complexity is O(v+e)
// where source is also not given
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void dfsrec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (auto i : adj[s])
    {
        if (visited[i] == false)
        {
            dfsrec(adj, i, visited);
        }
    }
}
void dfs(vector<int> adj[], int v)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            dfsrec(adj, i, visited);
        }
    }
}
int main(int argc, char const *argv[])
{
    vector<int> v[4];
    addEdge(v, 0, 1);
    addEdge(v, 0, 2);
    addEdge(v, 1, 3);
    addEdge(v, 1, 2);
    addEdge(v, 2, 3);
    // printEdge(v,4);
    dfs(v, 4);
    return 0;
}
/*
Application of DFS
1.cycle detection
2.Topological sorting
3.strongly connected graph
4.solving maze and similar puzzles
5.path finding
*/