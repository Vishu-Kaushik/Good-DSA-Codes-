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

// Implementation using Priority queues

int spanningTree(int v, vector<vector<int>> adj[])
{
    // Creating a priority queue of type weight, node, parent.
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // For zero based indexing
    vector<bool> vis(v, 0);

    // For Storing the MST  of type Edge from u to v
    vector<pair<int, int>> edge;

    // wt,node,parent
    pq.push({0, {0, -1}});
    int sum = 0;

    // E logE + ElogE
    // E Log E
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        // Taking out the information
        int node = it.second.first;
        int parent = it.second.second;
        int wt = it.first;

        // If the Node is visited then we move to the next iteration
        if (!vis[node])
        {
            continue;
        }

        // including in the MST
        vis[node] = true;
        sum += wt;

        // Traversing the adjacents
        for (auto iter : adj[node])
        {
            int adjNode = iter[0];
            int adjWt = iter[1];

            if (vis[adjNode] == false)
            {
                pq.push({wt, {adjNode, node}});
                edge.push_back({adjNode, node});
            }
        }
    }
    return sum;
    // Now if we want the edge list then we can return it also
}

int main(int argc, char const *argv[])
{

    return 0;
}