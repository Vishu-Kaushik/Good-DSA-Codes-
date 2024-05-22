#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
// Its Time Complexity is O(V+E) + O(V)(for printing the contents of the stack)
void dfsRec(vector<int> adj[], stack<int> &s, int u, bool visited[])
{
    visited[u] = true;
    for (auto x : adj[u])
    {
        if (visited[x] == false)
        {
            dfsRec(adj, s, x, visited);
        }
    }
    s.push(u);
}
void topologicalSort(vector<int> adj[], int v)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            dfsRec(adj, s, i, visited);
        }
    }
    while (s.empty() == false)
    {
        int u = s.top();
        cout << u << " ";
        s.pop();
    }
}
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    // indegree[u]=indegree[u]+1;
}

int main(int argc, char const *argv[])
{
    vector<int> v[4];
    // int indegree[4]={0};
    addEdge(v, 0, 1);
    addEdge(v, 0, 2);
    addEdge(v, 1, 3);
    addEdge(v, 1, 2);
    addEdge(v, 2, 3);
    // printEdge(v,4);
    topologicalSort(v, 4);
    return 0;
}