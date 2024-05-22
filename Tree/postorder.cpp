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

// Using Two Stacks
vector<int> postorder(Node *root)
{
    vector<int> postorder;
    if (root == NULL)
    {
        return postorder;
    }

    stack<Node *> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);

        if (root->left != NULL)
        {
            st1.push(root->left);
        }

        if (root->right != NULL)
        {
            st1.push(root->right);
        }
    }

    while (!st2.empty())
    {
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    return postorder;
}

// Using One stack

vector<int> postorder(Node *root)
{
    vector<int> post;
    stack<Node *> st;
    Node *curr = root;
    Node *temp;

    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                post.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    post.push_back(temp->data);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
    return post;
}