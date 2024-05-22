#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool dfsRec(vector<int> adj[], int s, bool visited[], int parent)
{
    visited[s] = true;
    for (auto u : adj[s])
    {
        if (visited[u] == false)
        {
            if (dfsRec(adj, u, visited, s) == true)
            {
                return true;
            }
        }
        else if (u != parent)
        {
            return true;
        }
    }
    return false;
}
bool dfs(vector<int> adj[], int v)
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
            if (dfsRec(adj, i, visited, -1) == true)
            {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector<int> v[10];
    addEdge(v, 0, 1);
    addEdge(v, 0, 2);
    addEdge(v, 1, 3);
    addEdge(v, 1, 2);
    addEdge(v, 2, 3);
    addEdge(v, 0, 3);
    addEdge(v, 2, 6);
    // printEdge(v,4);
    // mindistance(v,0,10)
    cout << dfs(v, 10);

    return 0;
}