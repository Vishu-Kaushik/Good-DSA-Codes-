#include <iostream>
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

// Recursive solution
//  TC is O(N) and Auxiliary Space is O(N/k)
Node *reverse(Node *head, int k)
{
    Node *curr = head;
    Node *prev = NULL, *next = NULL;

    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    if (next != NULL)
    {
        Node *rest_head = reverse(next, k); // we connect the last call prev as the next of original head of linked list
        head->next = rest_head;             // prev is new head
    }
    return prev;
}

// Iterative solution

Node *reverseIterative(Node *head, int k)
{
    Node *curr = head;
    Node *prevFirst = NULL;
    bool firstPass = true;
    while (curr != NULL)
    {
        Node *first = curr, *prev = NULL;
        int count = 0;
        while (curr != NULL && count < k)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (firstPass)
        {
            head = prev;
            firstPass = false;
        }
        else
        {
            prevFirst->next = prev;
        }
        prevFirst = first;
    }
    return head;
}