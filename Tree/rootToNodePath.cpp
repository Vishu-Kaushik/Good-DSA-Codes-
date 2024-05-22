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

// Time Complexity --> O(N) and space complexity is O(H) (revursive stack space)
// We did Inorder traversal in this solution

bool getPath(Node *root, int b, vector<int> &vec)
{
    if (root == NULL)
    {
        return false;
    }
    vec.push_back(root->data);
    if (root->data == b)
    {
        return true;
    }
    if (getPath(root->left, b, vec) || getPath(root->right, b, vec))
    {
        return true;
    }

    vec.pop_back();
    return false;
}

vector<int> solution(Node *root, int b)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    getPath(root, b, ans);
    return ans;
}