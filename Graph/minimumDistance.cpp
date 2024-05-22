#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    // indegree[u]=indegree[u]+1;
}

// Idea --> To use topological sorting
// 1. using BFS --> we can store topological sort in an array
// 2. Using DFS --> It will be stored in the stack and then we can use accordingly

vector<int> topologicalSorting(vector<int> adj[], int v)
{
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (auto x : adj[i])
        {
            indegree[x]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> vec;
    while (q.empty() == false)
    {
        int u = q.front();
        vec.push_back(u);
        q.pop();
        for (auto x : adj[u])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }
    return vec;
}

vector<int> minDistance(vector<int> adj[], int v, int source)
{
    vector<int> dis(v, -INT16_MIN);
    dis[source] = 0;
    // vector<int> vec;
    vector<int> top = topologicalSorting(adj, v);
    for (int i = 0; i < v; i++)
    {
        for (auto v : adj[top[i]])
        {
            if (dis[v] > dis[u] + weight(u, v))
            {
                dis[v] = dis[u] + weight(u, v);
            }
        }
    }
    return dis;
}
// we CAN write a weight function for a vertex between u and v
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

    return 0;
}