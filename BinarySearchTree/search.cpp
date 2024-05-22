#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Recursive implementation : Time Complexity is O(H) and auxiliary space O(H)
// The height can be logN when the tree is balanced or it can go N when the tree is skew
bool search(Node *root, int x)
{

    // given key bigger then root go to right
    // given key lesser then root go to left
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == x)
    {
        return true;
    }
    else if (root->data > x)
    {
        return search(root->left, x);
    }
    else
    {
        return search(root->right, x);
    }
}

// Iterative implementation : Time Complexity is O(H) and auxiliary space O(1)
bool search1(Node *root, int x)
{
    while (root != NULL)
    {
        if (root->data == x)
        {
            return true;
        }
        else if (root->data < x)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return false;
}
