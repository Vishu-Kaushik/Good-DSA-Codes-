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

// Naive --> we find root to node path and then compare both of them and then return the last common node
/*
    Efficient -- with TC and Space Complexity of O(N)
    Idea we do simple DFS to avoid extra space complexity
    The code is itself understood
*/

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    // Base Case
    if (root == NULL || root == p || root == q)
    {
        return root;
    }
    Node *left = lowestCommonAncestor(root->left, p, q);
    Node *right = lowestCommonAncestor(root->right, p, q);

    // If at any side we find any of the node (p or q) we return that .
    if (left == NULL)
    {
        return right;
    }
    else if (right == NULL)
    {
        return left;
    }
    else
    {
        // This is the case when we get both desired nodes from the both the side.
        return root;
    }
}