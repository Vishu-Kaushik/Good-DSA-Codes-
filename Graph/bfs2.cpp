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

void addEdge(vector<int> vec[], int u, int v)
{
    vec[u].push_back(v);
    vec[v].push_back(u);
}

// THis code is for the disconnected components of a graph

void Bfs(vector<int> adj[], int v, int s, bool visited[])
{
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int x : adj[u])
        {
            if (visited[x] == false)
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

void bfsDis(vector<int> adj[], int v)
{
    bool visited[v + 1] = {false};
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            Bfs(adj, v, i, visited);
        }
    }
}
// Also one ques is: Determine the number of islands in the graph can be solved using this technique only
// IN this ques we only have to find the number of disconnected components in the graph we can simply add count++ in the if condition of that bfsDis function
int main(int argc, char const *argv[])
{
    vector<int> v[4];
    addEdge(v, 0, 1);
    addEdge(v, 0, 2);
    addEdge(v, 1, 3);
    addEdge(v, 1, 2);
    addEdge(v, 2, 3);
    // printEdge(v,4);
    bfsDis(v, 4);
    return 0;
}