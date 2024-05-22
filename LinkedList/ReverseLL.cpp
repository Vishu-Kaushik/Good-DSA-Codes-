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

// Method 1 --> Recursively Reversing the linked list

Node *reverse1(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *rest_head = reverse1(head->next);
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return rest_head;
}

// Method 2 --> Recursively Reversing the linked list

Node *reverse2(Node *curr, Node *prev)
{
    if (curr == NULL)
    {
        return prev;
    }
    Node *next = curr->next;
    curr->next = prev;
    return reverse2(next, curr);
}

// Method 3 --> Iterative

Node *reverse3(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}