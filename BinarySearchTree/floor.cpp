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

// if the value is present then return the node with that value or if the value is not present then ..
// return the largest value which is smaller than the given value and if there is no smaller value then return NULL
// Time Complexity is O(H) and Auxiliary space is O(1)

Node *floor(Node *root, int x)
{
    Node *curr = root;
    Node *floor = NULL;
    while (curr)
    {
        if (curr->data == x)
        {
            return curr;
        }
        else if (curr->data > x)
        {
            curr = curr->left;
        }
        else
        {
            floor = curr;
            curr = curr->right;
        }
    }
    return floor;
}