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

/*
Ancestor -- for a node ancestor is node itself then its parent then its parent's parent ...... and so on .
LCA -- lowest common ancestor for two nodes is the lowest  ancestor which is common for both nodes
*/
// Naive Solution -- when TC is theta(N) and the space complexity is O(N)
// Idea -- behind this solution is to build path arrays for both the given value nodes and then compare and return the last common node

bool findPath(Node *root, vector<Node *> &p, int n1)
{
    if (root == NULL)
    {
        return false;
    }
    p.push_back(root);
    if (root->data == n1)
    {
        return true;
    }
    if (findPath(root->left, p, n1) || findPath(root->right, p, n1))
    {
        return true;
    }
    p.pop_back();
    return false;
}

Node *lca(Node *root, int n1, int n2)
{
    vector<Node *> path1, path2;
    if (findPath(root, path1, n1) && findPath(root, path2, n2)) // checking if both are present or not and also building the path arrays
    {
        return NULL;
    }
    for (int i = 0; i < path1.size() - 1 && i < path2.size() - 1; i++)
    {
        if (path1[i + 1] != path2[i + 1])
        {
            return path1[i];
        }
    }
    return NULL;
}

// Efficient Solution -- with only 1 traversal of the tree and with the assumption that the nodes value given is present
// TC is theta(N) and auxiliary space is O(H)
/*
1. Requires one traveral and theta(H) extra space for the recursive traveral
2. Assumes that both n1 and n2 exist in the tree. Does not give correct result when only one of(n1 or n2) exists.
*/

/*Idea : We do normal recursive traversal . We have the following cases for every node.
1. if it is same as n1 or n2 -- returns the head caller or root of the tree
2. if one of its subtrees contain n1 and the other contains n2. -- returns the root.
3. if one of its subtrees contains both n1 and n2 -- returns what its child call returns
4. if none of its subtrees contains any of n1 or n2 -- returns null
*/
Node *lca(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node *lca1 = lca(root->left, n1, n2);
    Node *lca2 = lca(root->right, n1, n2);

    if (lca1 != NULL && lca2 != NULL)
    {
        return root;
    }
    if (lca1 != NULL)
    {
        return lca1;
    }
    else
    {
        lca2;
    }
}