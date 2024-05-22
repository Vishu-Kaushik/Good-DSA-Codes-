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

// Pair of the adjacency list is of type {node,dis}
vector<int> dijkstra(int V, vector<vector<int>> adj[], int src)
{
    set<pair<int, int>> st; // Making set pair as {dis,node}
    vector<int> dist(V, 1e9);
    st.insert({0, src});
    dist[src] = 0;
    while (!st.empty())
    {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgW = it[1];
            if(dis+edgW < dist[adjNode])
            {
                // erase if existed
                if(dist[adjNode]!=1e9)
                {
                    st.erase({dist[adjNode],adjNode});
                }
                dist[adjNode]=dis+edgW;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}

int main(int argc, char const *argv[])
{

    return 0;
}