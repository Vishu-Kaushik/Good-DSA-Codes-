#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <map>
#include <sstream>

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

// Time Complexity for both solution is O(N) and Auxiliary space complexity is O(N)
// converts the tree into the string
string serialize(Node *root)
{
    if (root == NULL)
    {
        return "";
    }
    string str = "";
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            str.append("#,"); // indicating that the node is null ahead
        }
        else
        {
            str.append(to_string(curr->data) + ',');
        }
        if (curr != NULL)
        {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return str;
}

// converts back the string into the tree that was initially given
Node *deserialize(string data)
{
    if (data.size() == 0)
    {
        return NULL;
    }
    stringstream s(data);
    // A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream(like cin).To use stringstream,
    // we need to include sstream header file.The stringstream class is extremely useful in parsing input.
    string str;
    getline(s, str, ',');
    Node *root = new Node(stoi(str)); // stoi() function converts the string to an integer value
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        // for left node
        getline(s, str, ',');
        if (str == "#")
        {
            curr->left = NULL;
        }
        else
        {
            Node *leftNode = new Node(stoi(str));
            curr->left = leftNode;
            q.push(leftNode);
        }

        // for right node
        getline(s, str, ',');
        if (str == "#")
        {
            curr->right = NULL;
        }
        else
        {
            Node *rightNode = new Node(stoi(str));
            curr->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
