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

/*
    Some Important points to keep in mind
    1. Does not work for the graph with negative weight edges
    2. Does the shortest path change if we add a weight to all edges of the original path?
        Ans: Yes, becoz it depends on the number of edges if they are more then the number increases by more amount
    3. The shortest path does not if multiply weight of the edges by some same factor
    4. If we use Adjacency List and Min Heap Data Structure , Time complexity will be O(V logV + E logV)
*/
// THis implementation is very Simple using adjacency Matrix with weights

class graph
{
private:
    int vertices;
    int **arr;

public:
    graph(int v)
    {
        vertices = v;
        arr = new int *[vertices];
        for (int i = 0; i < vertices; i++)
        {
            arr[i] = new int[vertices];
            for (int j = 0; j < vertices; j++)
            {
                arr[i][j] = 0;
            }
        }
    }
    void addedge(int v, int u, int w)
    {
        arr[v][u] = true; // For undirected graph
        arr[v][u] = w;
        arr[u][v] = true;
        arr[u][v] = w;
    }
};

vector<int> Dijkstra(vector<int> graph[], int V, int src)
{
    vector<int> dist(V, INT16_MAX);
    dist[src] = 0;
    vector<int> fin(V, false); // finalized vector
    for (int count = 0; count < V; count++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
        {
            if (!fin[i] && (u == -1 || dist[i] < dist[u]))
            {
                u = i;
            }
        }
        fin[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && fin[v] == false)
            {
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
            }
        }
    }
    return dist;
}
int main(int argc, char const *argv[])
{

    return 0;
}