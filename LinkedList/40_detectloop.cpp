#include <iostream>
#include <unordered_set>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

// Method 1 --> Naive O(n^2) - For the current ith node we store the next node in a temp node then we will another loop from head to this (i-1)th node and will check for every node
// that the next of temp node (data) is equal to the current node data or not.

// Method 2 (TC as O(N) and AS as O(1) --> By changing the structure of the Node of linked list which is adding a boolean variable for each node and marking them positive once we visit them.

/* Method 3 --> Modifications to the linked list pointers  {TC as O(N)  and AS as O(1) )}
Steps -- making a temp node and everytime we traverse a node we make next of current node as temp and mean while we jump to the next node in the linked list and the do the same
and if there  is a loop we will find a node whose next is already the temp node then we will return true at that instant */

bool isLoop3(Node *head)
{
    Node *temp = new Node(0);
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->next == NULL)
        {
            return false;
        }
        if (curr->next == temp)
        {
            return true;
        }
        Node *curr_next = curr->next;
        curr->next = temp;
        curr = curr_next;
    }
    return false;
}

/* Method 4 --> The idea is to use hashing  with TC as O(N) and Aux. space as O(N) */

bool isLoop4(Node *head)
{
    unordered_set<Node *> st;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        if (st.find(curr) != st.end())
        {
            return true;
        }
        st.insert(curr);
    }
    return false;
}