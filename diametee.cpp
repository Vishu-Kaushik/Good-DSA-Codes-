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

// TC = O(N^2)

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + (height(root->left), height(root->right));
}

void findMax(Node *root, int maxi)
{
    if (root == NULL)
    {
        return;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    maxi = max(maxi, lh + rh);
    findMax(root->left, maxi);
    findMax(root->right, maxi);
}

// O(N)
int solve(Node *root, int &maxi)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = 0, rh = 0;
    lh = solve(root->left, maxi);
    rh = solve(root->right, maxi);
    maxi = max(maxi, lh + rh);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(Node *root)
{
    int maxi = INT_MIN;
    solve(root, maxi);
    return maxi;
}