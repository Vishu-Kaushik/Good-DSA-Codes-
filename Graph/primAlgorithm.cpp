#include <iostream>
#include <queue>
#define V 4
using namespace std;
/*
Given a weighted and connected undirected Graph
Minimum Spanning Tree --> Minimize the weight of edges and make sure that all the vertices are connected to each other may be through some intermidiate vertices
Prim's Algorithm --> WE maintain two sets 1. Vertices in MST 2. Vertices not in MST
                    and always we make a cut and make a greedy descision of minimum edge that connects first set to the second set
                    Finally we include all the vertices in the first set and make the second set empty.
*/
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
    int primAlgo(int graph[V][V]);
};
// Time complexity using Adjacency matrix is theta(v^2) 
// And if we use Adjacency matrix for this implementation We will have O((V+E)(log V)) as TC
int graph ::primAlgo(int graph[V][V])
{
    int key[V];
    int res = 0;
    fill(key, key + V, INT16_MAX);
    bool mSet[V];
    key[0] = 0;
    for (int count = 0; count < V; count++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
        {
            if (!mSet[i] && (u == -1 || key[i] < key[u])) // Can be replaced with min heap data structure (extracting min) Which gives result in O(Log V) time
            {
                u = i;
            }
        }
        mSet[u] = true;
        res += key[u];
        for (int v = 0; v < V; v++)   // THis will be normal traversal of the list which can be done in O(V+E) time
        {
            if (graph[u][v] != 0 && !mSet[u])  
            {
                key[v] = min(key[v], graph[u][v]);    // Extracting min (Log V) time
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
