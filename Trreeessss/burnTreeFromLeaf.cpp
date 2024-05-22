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

// This res is always passed as zero by reference
// This function does two things -- 1. Return Height 2. Set dist if given leaf is descendant
/* Burn a tree from a given node --> At zero second the required node will be burnt
--  At the first second its adjacent nodes are burnt
--  At the second sec. its adjacent are burnt then it goes on
Note : The fire spreads in the nodes that are adjacent to each other
When the all the nodes are burnt the time recorded was the time taken to burn the tree form the given node
*/
int burnTime(Node *root, int leaf, int &dist, int &res)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == leaf)
    {
        dist = 0;
        return 1;
    }
    int ldist = -1;
    int rdist = -1;
    int lh = burnTime(root->left, leaf, dist, res);
    int rh = burnTime(root->right, leaf, dist, res);
    if (ldist != -1)
    {
        dist = ldist + 1;
        res = max(res, dist + rh);
    }
    else if (rdist != -1)
    {
        dist = rdist + 1;
        res = max(res, dist + rh);
    }
    return max(lh, rh) + 1;
}