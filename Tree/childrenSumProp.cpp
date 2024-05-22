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
bool childSum(Node*root) // TC for this solution is O(n) and Auxiliary Space is O(height of tree)
{
    if(root==NULL){
        return true;
    }
    else if(root->left==NULL && root->right==NULL ){
        return true;
    }
    int sum=0;
    if(root->left!=NULL){sum=sum+(root->left->data);}
    if(root->right!=NULL){sum=sum+(root->right->data);}
    return (sum==root->data) && (childSum(root->left)) && (childSum(root->right));
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
    cout<<childSum(head);
    return 0;
}