#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

/*
Naive solution :
Idea --> use concept of indexing
        1. Zero based-indexing = then left child will have index as (2*i + 1) and right child will have index (2*i + 2)
        2. One based indexing = then left child will have index as (2*i ) and right child will have index (2*i + 1)
But this solution will create overflow for skew trees so this idea is avoided
*/

/*
Efficient Solution : Tc ans space complexity is O(N)
We modified above idea to avoid overflow condition by indexing it.
*/

int widthBinaryTree(Node *root)
{
    if (!root)
    {
        return 0;
    }
    int ans = 0;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();
        int min = q.front().second;
        int first, last;
        for (int i = 0; i < size; i++)
        {
            int curr_id = q.front().second - min;
            Node *curr = q.front().first;
            q.pop();
            if (i == 0)
            {
                first = curr_id;
            }
            if (i == size - 1)
            {
                last = curr_id;
            }
            if (curr->left)
            {
                q.push({curr->left, 2 * curr_id + 1});
            }
            if (curr->right)
            {
                q.push({curr->right, 2 * curr_id + 2});
            }
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}