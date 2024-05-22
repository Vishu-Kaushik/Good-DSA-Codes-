#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<int>> &vec, int u, int v)
{
    vec[u].push_back(v);
    vec[v].push_back(u);
}

void printEdge(vector<vector<int>> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}
/*
The segmentation fault is caused by the addEdge() function. In this function, you are trying to add the
edge (0, 1) to the vector v. However, the vector v is empty, so you are trying to access an invalid memory
location
*/
int main(int argc, char const *argv[])
{
    vector<vector<int>> v(4);
    addEdge(v, 0, 1);
    addEdge(v, 0, 2);
    addEdge(v, 1, 3);
    addEdge(v, 1, 2);
    addEdge(v, 2, 3);
    printEdge(v);
    return 0;
}