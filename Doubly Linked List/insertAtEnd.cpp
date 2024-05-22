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

Node*insertEnd(Node*head,int d)
{
    Node*temp=new Node(d);
    Node *curr=head;
    if(head==NULL)           //Corner case : When we pass an empty linked list, we simply return temp as the new head.
    {
        return temp;
    }
    while (curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
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
   head=insertEnd(head,15);
   print(head);
    return 0;
}
