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

Node *constructTree(vector<int> inorder, int is, int ie, vector<int> postorder, int ps, int pe, map<int, int> hashMap)
{
    if (ps > pe || is > ie)
    {
        return NULL;
    }
    Node *root = new Node(postorder[pe]);

    int inRoot = hashMap[postorder[pe]]; // returns the index of the root
    int numsLeft = inRoot - is;          // tells the number of elements in the left subtree

    root->left = constructTree(inorder, is, inRoot - 1, postorder, ps, ps + numsLeft - 1, hashMap);
    root->right = constructTree(inorder, inRoot + 1, ie, postorder, ps + numsLeft, pe - 1, hashMap);
    return root;
}

// ------------------ Main FUnction with TC as O(LOG N) and AS as O(2N) (for recursion and for map)
Node *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    if (inorder.size() != postorder.size())
    {
        return NULL;
    }
    map<int, int> hashMap;

    // Mapping every element with there indexes .

    for (int i = 0; i < inorder.size(); i++)
    {
        hashMap[inorder[i]] = i;
    }
    return constructTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, hashMap);
}