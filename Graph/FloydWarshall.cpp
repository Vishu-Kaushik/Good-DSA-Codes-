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

/* Question
The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it
means there is no edge from i to j.   Do it in-place.
*/

/*  This is also an Shortest Path Algorithm.
--> It is an algorithm in which we find shortest path from each node in the graph to every other node in the graph.
--> We can use this to Detect Negative Cycles in the graph. 
--> Also known as MultiSource Shortest Path Algorithm.
--> It is a Brute Force Algorithm which Takes O(N^3) time
*/
// Also for finding the shortest distance from each node to every other node we can apply Dijkstra's Algorithm for every node which can be treated as source
// So the TC will be O(N* ELogV)


void shortestDistance(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]==-1)
            {
                matrix[i][j]=1e9;
            }
            if (i == j)
            {
                matrix[i][j] = 0;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j]=min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
            }
            
        }
    }
    
    // Now for detecting the Negative Cycles 

    for (int i = 0; i < n; i++)
    {
        if(matrix[i][i] < 0)
        {
            cout<<"Negative Cycles";
        }
    }
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1e9)
            {
                matrix[i][j] = -1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}