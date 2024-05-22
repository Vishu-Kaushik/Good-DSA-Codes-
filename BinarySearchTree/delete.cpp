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

// for the case when we have both childs for the node to be deleted we can either replace that node with the closest smaller value of its child or with the closest
// greater value . In our case we always choose the closest greater value .
// Now the closest greater value here is the inorder successor of that node . The node which comes after the given key in the inorder traversal.
// inorder successor of a node --> left most leaf of the right child
// The method we used gives the  inorder successor when the right child is not empty ..... there might be cases when the  inorder successor is one of the ancestor instead
// of lying in the right subtree or it might happen when the right child is NULL or empty

Node *getSuccessor(Node *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *deleteNode(Node *root, int x)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data > x)
    {
        root->left = deleteNode(root->left, x);
    }
    else if (root->data < x)
    {
        root->right = deleteNode(root->right, x);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *succ = getSuccessor(root);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
        return root;
    }
}