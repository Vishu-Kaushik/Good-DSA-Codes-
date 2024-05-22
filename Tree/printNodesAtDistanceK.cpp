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

// Time Complexity is O(N) + O(NlogN) {log N for unordered map}
// Space Complexity is O(N)

void parentTrack(Node *root, unordered_map<Node *, Node *> &parent)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        if (current->left)
        {
            parent[current->left] = current;
            q.push(current->left);
        }
        if (current->right)
        {
            parent[current->right] = current;
            q.push(current->right);
        }
    }
}

vector<int> nodesAtDistance(Node *root, Node *target, int k)
{
    // map is of type node and its parent
    unordered_map<Node *, Node *> parent;
    parentTrack(root, parent);

    unordered_map<Node *, bool> visited;
    queue<Node *> q;
    q.push(target);
    visited[target] = true;
    int curr_level = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (curr_level++ == k)
        {
            break;
        }
        for (int i = 0; i < size; i++)
        {
            Node *current = q.front();
            q.pop();
            if (current->left && !visited[current->left])
            {
                q.push(current->left);
                visited[current->left] = true;
            }
            if (current->right && !visited[current->right])
            {
                q.push(current->right);
                visited[current->right] = true;
            }
            if (parent[current] && !visited[parent[current]])
            {
                q.push(parent[current]);
                visited[parent[current]] = true;
            }
        }
    }
    vector<int> result;
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        result.push_back(current->data);
    }
    return result;
}