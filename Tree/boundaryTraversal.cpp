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

// ----------------------------------------
bool isLeaf(Node *curr)
{
    if (curr->right == NULL && curr->left == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//--------------------------------------------------------------------------------

void addLeftBoundary(Node *root, vector<int> &res)
{
    Node *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
        {
            res.push_back(curr->data);
        }
        if (curr->left != NULL)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}

// -------------------------------------------------
// We will do inorder traversal then we will insert only leave nodes
void addLeaves(Node *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
    {
        addLeaves(root->left, res);
    }
    if (root->right)
    {
        addLeaves(root->right, res);
    }
}
// --------------------------------------------------

void addrightBoundary(Node *root, vector<int> &res)
{
    Node *curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (!isLeaf(curr))
        {
            temp.push_back(curr->data);
        }
        if (curr->right != NULL)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        res.push_back(temp[i]);
    }
}
// ----------------------------------------------------------
// Main Function
vector<int> boundary(Node *root)
{
    vector<int> res;
    if (root == NULL)
    {
        return res;
    }
    if (!isLeaf(root))
    {
        res.push_back(root->data);
    }
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addrightBoundary(root, res);
    return res;
}