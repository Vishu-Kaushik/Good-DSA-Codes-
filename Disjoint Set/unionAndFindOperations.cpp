#include <iostream>
using namespace std;

// In this we will implement union and find operations
// This is simple implementation.
class Disjoint
{
private:
    int size;
    int *parent;

public:
    Disjoint(int x)
    {
        size = x;
        parent = new int[size];
    }
    void initialize()
    {
        for (int i = 0; i < size; i++)
        {
            parent[i] = i;
        }
    }
    // Worst case time complexity of these two operations are O(N) if the elements start to form the chains.
    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        else
        {
            return find(parent[x]);
        }
    }
    // Here the standard is making the second element as the child of the first element passed in the union1 function.
    // Then the representative element of the second element becomes the first element.
    // In union1 operation --> when we make x and the y the friend , then in result the freind of x becomes freind of y and the freind of y becomes freind of x.
    //                          also these elements becomes part of the same set.

    void union1(int x, int y)
    {
        int x_rep = find(x);
        int y_rep = find(y);
        if (x_rep == y_rep)
        {
            return;
        }
        else
        {
            parent[y_rep] = x_rep;
        }
    }
};
