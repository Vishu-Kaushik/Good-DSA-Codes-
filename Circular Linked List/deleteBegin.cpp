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
Node *deleteBegin(Node *head)
{
    Node *curr = head;
    // Node *temp = head;
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == head)
    {
        delete head;
        return NULL;
    }
    while (curr->next != head)
    {
        curr = curr->next;
    }
    curr->next = head->next;
    delete head;
    return (curr->next);
}

Node*deletek(Node*head,int k)
{
    Node*temp=head;
    if(head==NULL)
    {
        return NULL;
    }
    if(k==1)
    {
        delete head;
        return NULL;
    }
    for (int i = 0; i < k-2; i++)
    {
        temp=temp->next;
    }
    Node*del=temp->next;
    temp->next=temp->next->next;
    delete(del);
    return head;
  
}
void print(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
}

int main(int argc, char const *argv[])
{
    Node *head = new Node(2);
    Node *second = new Node(3);
    Node *third = new Node(5);
    Node *fourth = new Node(7);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head;
    head = deletek(head,3);
    print(head);
    return 0;
}