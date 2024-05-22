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

Node* deleteLastNode(Node*head)
{
    Node*temp;
    if(head==NULL)           //corner case no.1
    {
        return NULL;
    }
    if(head->next==NULL)     //corner case no.2
    {
        delete head;
        return NULL; 
    }
    for(temp=head;temp->next!=NULL;temp=temp->next);
     temp->prev->next=NULL;
     delete temp;   
    return head;
    /* We can also reduce the time complexity of the last node operation by maintaining a tail pointer--->**O(1)** 
      this also has some certain disadvantages */
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
   head=deleteLastNode(head);
   print(head);
    return 0;
}