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

// Recursive solution :Time Complexity is O(H) and auxiliary space O(H)
// The height can be logN when the tree is balanced or it can go N when the tree is skew

Node *insert(Node *root, int x)
{
    if (root == NULL)
    {
        return new Node(x);
    }
    else if (root->data < x)
    {
        root->right = insert(root->right, x);
    }
    else if (root->data > x)
    {
        root->left = insert(root->left, x);
    }
    return root;
}

// Iterative Solution : Time Complexity is O(H) and auxiliary space O(1)

Node *insert1(Node *root, int x)
{
    Node *temp = new Node(x);
    Node *parent = NULL, *curr = root;
    while (curr != NULL)
    {
        parent = curr;
        if (curr->data > x)
        {
            curr = curr->left;
        }
        else if (curr->data < x)
        {
            curr = curr->right;
        }
        else
        {
            return curr;
        }
    }
    if (parent == NULL)
    {
        return temp;
    }
    else if (parent->data > x)
    {
        parent->left = temp;
    }
    else if (parent->data < x)
    {
        parent->right = temp;
    }
    return root;
}