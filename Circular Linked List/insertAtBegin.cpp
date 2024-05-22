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

Node *insertAtBegin(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        temp->next = temp;
    return temp;
    }
    else{
    Node *curr = head;
   do{
       curr=curr->next;

   }while(curr->next!=head);

    temp->next = head;
    curr->next = temp;
    return temp;
}

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
        cout << curr->data <<" ";
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
     head=insertAtBegin(head, 10);
    print(head);

    return 0;
}
