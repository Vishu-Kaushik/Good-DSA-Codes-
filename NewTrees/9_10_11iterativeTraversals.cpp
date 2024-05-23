#include <iostream>
#include <stack>
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

// Iterative Preorder Traversals
// TC is O(N) and Space COmplexity is O(N)
vector<int> pre(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *curr = st.top();
        st.pop();

        ans.push_back(curr->data);
        if (root->right != NULL)
        {
            st.push(curr->right);
        }
        if (root->left != NULL)
        {
            st.push(curr->left);
        }
    }
    return ans;
}

// Iterative Inorder Traversals
// TC is O(N) and Space COmplexity is O(N)
vector<int> inorder(Node *root)
{
    stack<Node *> st;
    Node *curr = root;
    vector<int> inorder;
    while (true)
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if (st.empty() == true)
            {
                break;
            }
            curr = st.top();
            st.pop();
            inorder.push_back(curr->data);
            curr = curr->right;
        }
    }
    return inorder;
}