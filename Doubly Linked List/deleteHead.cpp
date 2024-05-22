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
Node*deleteHead(Node*head)
{
     Node *temp=head;
     if(temp==NULL)
     {
         return NULL;
     }

     temp=temp->next;
     temp->prev=NULL;
     delete (head);
     if(temp==NULL)
     {
        return NULL;
     }
     else{
        return temp;
     }
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
   head=deleteHead(head);
   print(head);
    return 0;
}
