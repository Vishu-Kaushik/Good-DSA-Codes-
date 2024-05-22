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
Node*rotate(Node*head)
{
    Node*temp;
    Node *curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    temp=head;
    curr->next=temp;
    head=head->next;
    temp->next=NULL;
    return head;
}



void print(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *curr = head;
     while(curr!=NULL)
     {
        cout<<curr->data<<" ";
        curr=curr->next;
     }
   
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
    head=rotate(head);
    print(head);
    return 0;
}