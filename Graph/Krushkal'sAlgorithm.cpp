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

class disjoint
{
private:
    int size;
    int *parent;
    int *rank;

public:
    disjoint(int x);
    void union1(int x, int y);
    int find(int x);
};

disjoint::disjoint(int x)
{
    size = x;
    parent = new int[size];
    rank = new int[size];
    for (int i = 0; i < size; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
void disjoint ::union1(int x, int y)
{
    int x_rep = find(x);
    int y_rep = find(y);
    if (x_rep == y_rep)
    {
        return;
    }
    if (rank[x_rep] < rank[y_rep])
    {
        parent[x_rep] = y_rep;
    }
    else if (rank[y_rep] < rank[x_rep])
    {
        parent[y_rep] = x_rep;
    }
    else
    {
        parent[y_rep] = x_rep;
        rank[x_rep]++;
    }
}

int disjoint ::find(int x)
{
    if (x == parent[x])
    {
        return x;
    }
    parent[x] = find(parent[x]);
    return parent[x];
}
bool myCmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
// In this algorithm we find the Minimum Spanning tree using Disjoint Set data structures
/*
    --> For implementing this algorithm We do not need to create an adjacency list.
    --> We are given a linear data structure (here it is edges 2d vector) which contains the information about edges weight.
    --> Like it has info in the form of u,v,w where the edge is between node u to node v and the weight is W.
    --> So We first sort the edges 2d vector according to the weight and the apply the union by rank and path compression concept
        on every edge and then just calculate the Weight of minimum Spanning tree + the Tree also
*/

int krushkal(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(), myCmp);
    disjoint node(n);
    int minWt = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = node.find(edges[i][0]); // Finding the first node of the edge
        int v = node.find(edges[i][1]); // Finding the second node of the edge
        int w = (edges[i][2]);

        // Case 1 : If the parent of both the nodes are same then we ignore which means both the nodes are in the same Set or means they are conncected;
        // Case 2 : If the parent of both the nodes are different then we apply union function between those two nodes

        if (u != v)
        {
            minWt += w;
            node.union1(u, v);
        }
    }
    return minWt;
}
int main(int argc, char const *argv[])
{

    return 0;
}