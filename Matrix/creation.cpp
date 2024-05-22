#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int m = 3, n = 2;
    // 1st Method of creation --> Double Pointers
    int **arr1;          // Creates a pointer that points to an array of pointers
    arr1 = new int *[m]; // Makes every pointer points to a contiguous set of elements
    for (int i = 0; i < m; i++)
    {
        arr1[i] = new int[n];
    }
    // 2nd Method --> Array of pointers
    int *arr2[m];
    for (int i = 0; i < n; i++)
    {
        arr2[i] = new int[n];
    }
    // 3rd Method --> Array of vectors
    vector<int> v1[m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v1[i].push_back(10);
        }
    }
    // 4th Method --> Vector of vector
    vector<vector<int>> v2;
    for (int i = 0; i < v2.size(); i++)
    {
        vector<int> v;
        for (int j = 0; j < v2[i].size(); j++)
        {
            v.push_back(10);
        }
        v2.push_back(v);
    }

    return 0;
}
