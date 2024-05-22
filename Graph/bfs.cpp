#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Time Complexity of BFS is O(V+E)
void addEdge(vector<int> vec[], int u, int v)
{
    vec[u].push_back(v);
    vec[v].push_back(u);
}

void printEdge(vector<int> vec[], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int x : vec[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
void breadthFirstSearch(vector<int> vec[], int s, int v)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int x : vec[u])
        {
            if (visited[x] == false)
            {
                visited[x] = true;
                q.push(x);
            }
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
    breadthFirstSearch(v, 0, 4);
    return 0;
}