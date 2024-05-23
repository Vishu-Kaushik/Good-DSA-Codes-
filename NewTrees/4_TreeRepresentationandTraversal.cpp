#include <iostream>
#include <vector>
#include <queue>
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
Tree Traversal techniques --> BFS and DFS
BFS - Breadth First Search ---- Level Order Traversal
DFS - Depth First Search :
    1. Inorder -   left Subtree --> Root --> Right Subtree
    2. Preorder -  Root --> Left Subtree --> Right Subtree
    3. Postorder - leftSubtree --> Right Subtree --> Root
*/

// preorder Traversal  - Time Complexity is O(N) and space complexity is O(N)
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal - Time Complexity is O(N) and Space complexity is O(N)
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder Traversal - Time Complexity is O(N) and Space complexity is O(N)
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// BFS - breadth first search
// Level Order Traversal

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
            level.push_back(curr->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main(int argc, char const *argv[])
{

    return 0;
}
