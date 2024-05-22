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
Node*insertAtBegin(Node*head,int d)
{
     Node *temp=new Node(d);
     temp->next=head;
    if(head!=NULL)
    {
        head->prev=temp;
    }
    //  head->prev=temp;
     return temp;

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
   head=insertAtBegin(head,15);
   print(head);
    return 0;
}
