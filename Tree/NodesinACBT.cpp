#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

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

int leftHeight(Node *root)
{
    int height = 0;

    while (root)
    {
        height++;
        root = root->left;
    }
    return height;
}

int rightHeight(Node *root)
{
    int height = 0;

    while (root)
    {
        height++;
        root = root->right;
    }
    return height;
}
// Main FUnction using the concept : nodes in a complete binary tree are 2^h - 1.
// TC = O((logN)^2) and ASC = O(logN)
int totalNode(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = leftHeight(root);
    int rh = rightHeight(root);

    if (lh == rh)
    {
        return (1 << lh) - 1;
    }

    return 1 + totalNode(root->left) + totalNode(root->right);
}
