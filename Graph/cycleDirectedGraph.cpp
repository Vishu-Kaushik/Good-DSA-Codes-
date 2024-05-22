#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v); // for directed graph
    // adj[v].push_back(u);
}

bool cycleDetect(vector<int> adj[], int s, bool visited[], bool recSt[])
{
    visited[s] = true;
    recSt[s] = true;
    for (auto x : adj[s])
    {
        if (visited[x] == false && cycleDetect(adj, x, visited, recSt))
        {
            return true;
        }
        else if (recSt[x] == true)
        {
            return true;
        }
    }
    recSt[s] = false;
    return false;
}
// This recSt[] array is made to check which vertices are there in the recursion call stack and hence helps is finding the back edge
// Back Edge --> A edge which connects a decendant to one of its ancestors
bool cycleDfs(vector<int> adj[], int v)
{
    bool visited[v], recSt[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        recSt[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            if (cycleDetect(adj, i, visited, recSt) == true)
            {
                return true;
            }
        }
    }
    return false;
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
    cout << cycleDfs(v, 0);
    return 0;
}