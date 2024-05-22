#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct Node{
    Node*left , *right ;
    int data;
    Node(int x)
    {
        data=x;
        left=right=NULL;
    }
};
Node* treeTodll(Node*root)
{
    if(root==NULL){
        return NULL;
    }
 static Node* prev=NULL;

   Node* head= treeTodll(root->left);
   if(prev==NULL){
    head=root;
   }
   else{
    root->left=prev;
    prev->right=root;
   }
    prev=root;
    treeTodll(root->right);
    return head;
}

int main(int argc, char const *argv[])
{
    Node *head = new Node(2);
    Node *second = new Node(3);
    Node *third = new Node(5);
    Node *fourth = new Node(7);
    Node *fifth = new Node(8);
    Node *sixth = new Node(9);
    Node *seventh = new Node(10);
    head->left=second;
    head->right=third;
    second->left=fourth;
    second->right=fifth;
    third->left=sixth;
    sixth->left=seventh; 
    treeTodll(head);
    return 0;
}