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

/*
Root Will be same.
for left Subtree --> traversal will be of the form  ----- root left right
for right Subtree --> traversal will be of the form  ----- root right left
*/

bool isSymmetrical(Node *root)
{
    return root == NULL || isSymmetricHelp(root->left, root->right);
}

bool isSymmetricHelp(Node *left, Node *right)
{
    if (left == NULL || right == NULL)
    {
        return left == right;
    }
    if (left->data != right->data)
    {
        return false;
    }
    return (isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left));
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
