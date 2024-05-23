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

int maxDepth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(lh, rh);
}
int maxi = 0;
void findMax(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    maxi = max(maxi, lh + rh);
    findMax(root->left);
    findMax(root->right);
}
