#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// A balanced binary tree is when for every node : (height of left subtree - height of right subtree) >= 1
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
// Naive SOlution where the Time Complexity is O(N^2)
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

bool balancedTree(Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    if (abs(lh - rh) > 1)
    {
        return false;
    }

    bool left = balancedTree(root->left);
    bool right = balancedTree(root->right);

    if (!left || !right)
    {
        return false;
    }
    return true;
}

// Efficient Solution
// Intuition is We return -1 if the tree is not balanced else if the tree is balanced then we return height of the tree
// TC = O(N) and auxiliary space is O(N)
int balanced(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = balanced(root->left);
    if (lh == -1)
    {
        return -1;
    }

    int rh = balanced(root->right);

    if (rh == -1)
    {
        return -1;
    }

    if (abs(lh - rh) > 1)
    {
        return -1;
    }

    return 1 + max(lh, rh);
}