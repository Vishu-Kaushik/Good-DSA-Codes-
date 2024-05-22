#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Dijkstra's Algorithm --> it does not work for edges with negative weights
/*
    Bellman's Ford Algorithm --> Also this algo is used to find the minimum distance from the source to every other node in the graph.
                        --> Given in this a connected and weighted graph.
                        --> It works for edges with negative weights.
                        --> It does not work when negative cycle is present.
                        --> Also it is used to find if there is a negative cycle present.
                        --> If negative cycle not present then it finds out shortest path / distance to desired node.
*/

int bellmanFord(int v, int e, int src, int dest, vector<vector<int>> &edges)
{
    // Initializing with v+1 because of 1 based indexing in the graph
    vector<int> dist(v + 1, 1e9);
    dist[src] = 0;

    // Traversing for n-1 times over every edge  of the graph and applying the minimization distance formula  which the algorithm says
    for (int i = 1; i <= v; i++)
    {
        // Traversing the edge list
        for (int j = 0; j < e; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            // applying the minimization of distance formula
            if (dist[u] != 1e9 && ((dist[u] + wt) < dist[v]))
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // checking for the negative cycle
    bool flag = 0;
    for (int j = 0; j < e; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        // applying the minimization of distance formula
        if (dist[u] != 1e9 && ((dist[u] + wt) < dist[v]))
        {
            flag = 1;
        }
    }

    if (flag == 0)
    {
        return dist[dest];
    }
    return -1;
}