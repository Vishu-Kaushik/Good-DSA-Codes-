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

// Using morris traversal for flattening the binary tree in place with time Complexity of O(N) and AS as O(1)
void flattenBinaryTree(Node *root)
{
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left)
        {
            Node *pred = curr->left;
            while (pred->right)
            {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }

    /*
        Another Approach
        curr = root;
        while(curr!=NULL)
        {
            curr->left = NULL;
            curr = curr->right;
        }
    */
}