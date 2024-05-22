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
Node *mergeAlternate(Node*head1,Node *head2)
{
    Node*res1=head1;
    Node*res2=head2;
      Node *temp1, *temp2;
    //   Node *a, *b;
    Node*dummy;
    while(res1!=NULL && res2!=NULL)
    {
        temp1=res1->next;
        res1->next=res2;
        res1=temp1;

        temp2=res2->next;
        res2->next=res1;
        res2=temp2;
    }

 
    return head1;
}
Node*addpos(Node *head, int data,int pos)
{
    Node*temp=new Node(data);
    Node*curr=head;
    int count=0;
    while(count <pos-1)
    {
        curr=curr->next;
        count++;
    }
    temp->next=curr->next;
    curr->next=temp;
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
    // fourth->next = NULL;

    Node *head1 = new Node(1);
    Node *second1 = new Node(5);
    Node *third1 = new Node(6);
    Node *fourth1 = new Node(8);
    Node *fifth1 = new Node(10);
    Node *sixth1 = new Node(16);
     head1->next = second1;
    second1->next = third1;
    third1->next = fourth1;
    fourth1->next = fifth1;
    fifth1->next = sixth1;
    // sixth1->next = NULL;
    head=mergeAlternate(head,head1);
    // addpos(head,10,3);
    print(head);
    return 0;
}