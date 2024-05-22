#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <map>
// #include <sstream>

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

// TC = amortized O(N)
// We will make the given binary tree a threaded binary tree.
// In this we make threads betwenn the right most guy of the left subtree to the current node then only we will start the traveral
vector<int> getInorder(Node *root)
{
    vector<int> inorder;
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            inorder.push_back(curr->data);
            curr = curr->right;
        }

        // Start to search the right most node in the left subtree for a particular node
        else
        {
            Node *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                // Breaking the thread if exists then pushing the value of the current node to the vector
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder;
}

vector<int> getPreorder(Node *root)
{
    vector<int> preorder;
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left)
        {
            preorder.push_back(curr->data);
            curr = curr->right;
        }

        // Start to search the right most node in the left subtree for a particular node
        else
        {
            Node *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = curr;
                preorder.push_back(curr->data);
                curr = curr->left;
            }
            else
            {
                // Breaking the thread if exists then pushing the value of the current node to the vector
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preorder;
}
