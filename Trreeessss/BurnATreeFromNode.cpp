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
// Tc : O(N) + O(NlogN) + O(N)
// Sc : O(N)
int findMaxDistance(unordered_map<Node *, Node *> &map, Node *target)
{
    queue<Node *> q;
    q.push(target);
    unordered_map<Node *, bool> vis;
    vis[target] = 1;
    int maxi = 0;
    while (!q.empty())
    {
        int size = q.size();
        bool fl = false;
        for (int i = 0; i < size; i++)
        {
            auto curr = q.front();
            q.pop();
            if (curr->left && !vis[curr->left])
            {
                fl = 1;
                vis[curr->left] = true;
                q.push(curr->left);
            }
            if (curr->right && !vis[curr->right])
            {
                fl = 1;
                vis[curr->right] = true;
                q.push(curr->right);
            }
            if (map[curr] && !vis[map[curr]])
            {
                fl = 1;
                vis[map[curr]] = true;
                q.push(map[curr]);
            }
        }
        if (fl)
        {
            maxi++;
        }
    }
    return maxi;
}
Node *bfsToMapParent(Node *root, unordered_map<Node *, Node *> &map, int start)
{
    queue<Node *> q;
    q.push(root);
    Node *res;
    while (!q.empty())
    {
        Node *curr = q.front();
        if (curr->data == start)
        {
            res = curr;
        }
        q.pop();
        if (curr->left)
        {
            map[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right)
        {
            map[curr->right] = curr;
            q.push(curr->right);
        }
    }
    return res;
}

int minTime(Node *root, int start)
{
    unordered_map<Node *, Node *> map; // map is such that is stores node and its parent
    Node *target = bfsToMapParent(root, map, start);
    int maxTime = findMaxDistance(map, target);
    return maxTime;
}