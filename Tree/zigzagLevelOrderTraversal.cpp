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

// Flag = 1 ---> level order traversal from left to right
// Flag = 0 ---> level order traversal from right to left
vector<vector<int>> zigZag(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<Node *> q;
    q.push(root);
    bool flag = 0;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level{size};
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();

            int index = (flag) ? i : size - i - 1;

            level[index] = curr->data;
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
        flag = !flag;
        ans.push_back(level);
        /* alternative*/
        /*
        if(flag==1)
        {
            ans.push_back(level);
            flag = 0;
        }
        else {
            reverse(level.begin(),level.end());
            ans.push_back(level);
            flag = 1;

        }
        */
    }
    return ans;
}