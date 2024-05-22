#include <iostream>
using namespace std;

class disjoint
{
private:
    int size;
    int *parent;
    int *rank; // It is an array which maintains the height of the tree

public:
    disjoint(int x);
    void union1(int x, int y);
    int find(int x);
    // int find(int x)
    // {
    //     if (parent[x] == x)
    //     {
    //         return x;
    //     }
    //     else
    //     {
    //         return find(parent[x]);
    //     }
    // }
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
// Union by rank technique
// Here we do not simply make union of two disjoint sets.
// We do this by comparing the ranks of two representative elements because we do not want the overall height to grow.
// we make the smaller height node representative as child of the higher height representative.
// Time Complexity for m operations it becomes as O(m*log(n))
// For a single operation it becomes O(log n)
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
    else // Otherwise following the convention in making the second element as child of the first element tree.
    {
        parent[y_rep] = x_rep;
        rank[x_rep]++;
    }
}

// Path compression technique
/*
when both optimizations are combined then
This make the Time Complexity as O(m*aplha(n))
where, alpha(n) <= 4 --> for any big universe of numbers
                this is also know as amortized time complexity
Also alpha(n) is the Inverse Ackerman Function
*/

int disjoint ::find(int x)
{
    if (x == parent[x])
    {
        return x;
    }
    parent[x] = find(parent[x]);
    return parent[x];
}
