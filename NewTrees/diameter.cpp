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

/*
Diameter of a tree --> number of nodes longest path between two leaf nodes
    --> path does not need to  pass via root (not necessary)
*/

/*
Naive solution --> I am trying to take the longest on every node considering that node as the curve point
TC is O(N^2)
*/

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

int findMaX(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int d1 = 1 + maxDepth(root->left) + maxDepth(root->right);
    int d2 = findMaX(root->left);
    int d3 = findMaX(root->right);
    return max(d1, max(d2, d2));
}

// Efficient Solution where TC is O(N) and the extra space is O(H)
// Code 1:
int res = 0; // this variable stores the diamter of the binary tree
int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = diameter(root->left);
    int rh = diameter(root->right);
    res = max(res, 1 + lh + rh); // returns the diameter
    return 1 + max(lh, rh);      // return the height
}

// Code 2:
int height(Node *root, int dia)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left, dia);
    int rh = height(root->right, dia);
    dia = max(dia, 1 + lh + rh);
    return 1 + max(lh, rh);
}

int diameter(Node *root)
{
    int diameter = 0;
    height(root, diameter);
    return diameter;
}
