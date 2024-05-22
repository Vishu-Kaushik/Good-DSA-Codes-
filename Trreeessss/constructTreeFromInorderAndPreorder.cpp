#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <map>

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

Node *buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> inmap)
{
    if (preStart > preEnd || inStart > inEnd)
    {
        return NULL;
    }

    Node *root = new Node(preorder[preStart]);

    int inRoot = inmap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inStart + numsLeft, inmap);
    root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inmap);
    return root;
}

// ------------------ Main FUnction with TC as O(LOG N) and AS as O(2N) (for recursion and for map)
Node *constructTree(vector<int> &inorder, vector<int> &preorder, unordered_map<int, int> &inmap)
{
    for (int i = 0; i < inorder.size(); i++)
    {
        inmap[inorder[i]] = i;
    }

    Node *root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inmap);
    return root;
}