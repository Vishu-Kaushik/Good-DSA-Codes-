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
// Children Sum Property --> root's value = left child value + right child value
// Time complexity is O(N) and SC is O(H)
void changeTree(Node *root)
{
    if (!root)
    {
        return;
    }
    int child = 0;
    if (root->left)
    {
        child += root->left->data;
    }
    if (root->right)
    {
        child += root->right->data;
    }
    if (child >= root->data)
    {
        root->data = child;
    }
    else
    {
        if (root->left)
        {
            root->left->data = root->data;
        }
        if (root->right)
        {
            root->right->data = root->data;
        }
    }
    changeTree(root->left);
    changeTree(root->right);
    int tot = 0;
    if (root->left)
    {
        tot += root->left->data;
    }
    if (root->right)
    {
        tot += root->right->data;
    }
    if (root->left || root->right)
    {
        root->data = tot;
    }
}

// Function to check if the tree follows children sum property or not

bool isSum(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    int sum = 0;
    if (root->left)
    {
        sum += root->left->data;
    }
    if (root->right)
    {
        sum += root->right->data;
    }
    return ((root->data == sum) && isSum(root->left) && isSum(root->right));
}