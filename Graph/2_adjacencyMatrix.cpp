#include <iostream>
#include <vector>
using namespace std;

class graph
{
private:
    int vertices;
    bool **arr;

public:
    graph(int v)
    {
        vertices = v;
        arr = new bool *[vertices];
        for (int i = 0; i < vertices; i++)
        {
            arr[i] = new bool[vertices];
            for (int j = 0; j < vertices; j++)
            {
                arr[i][j] = false;
            }
        }
    }
    void addedge(int v, int u)
    {
        arr[v][u] = true; // For undirected graph
        arr[u][v] = true;
    }
};
