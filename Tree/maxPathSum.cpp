#include <iostream>
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

int maxPathDown(Node *root, int &maxi)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftSum = max(0, maxPathDown(root->left, maxi));
    int rightSum = max(0, maxPathDown(root->right, maxi));
    maxi = max(maxi, root->data + leftSum + rightSum);
    return (root->data, max(leftSum, rightSum));
}

int maxPathSum(Node *root)
{
    int maxi = INT16_MIN;
    maxPathDown(root, maxi);
    return maxi;
}