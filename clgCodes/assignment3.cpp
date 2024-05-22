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
Node*append(Node*start1,Node*start2)
{
    Node*curr=start1;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=start2;
    return start1;

}
// int removepos(Node *head,int x)
// {
//     if(head==NULL)
//     {
//         return -1;
//     }
//     if(head->next==NULL)
//     {
//         int y=head->data;
//         return y;
//     }
//     Node *curr=head;
//     int y;
//     while()

// }
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
    head=append(head,head1);
    print(head);
    return 0;
}