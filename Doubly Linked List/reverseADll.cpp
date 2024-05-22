#include <iostream>
using namespace std;
struct Node{
    int data;
    Node*next=NULL;
    Node*prev=NULL;
    Node(int d)
    {
        data=d;
        prev=NULL;
        next=NULL;
    }
};

Node*reverse(Node*head)
{
    Node*temp=head;
    Node*curr;
    while(temp->next!=NULL)
    {
        curr=head;
        curr->prev=head->next;
        curr->next=head->prev;
        temp=temp->next;
        head=head->next;
    }
    head=curr;
    return head;
}

void print(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(int argc, char const *argv[])
{
   Node*head=new Node(10);
   Node*second=new Node(20);
   Node*third=new Node(30);
   head->next=second;
   second->prev=head;
   second->next=third;
   third->prev=second;
   head=reverse(head);
   print(head);
    return 0;
}