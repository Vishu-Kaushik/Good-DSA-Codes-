#include <iostream>
#include <math.h>

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
int height(Node*root)
{
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right)+1);
}
//Naive solution with TC of O(n^2)
bool isBalanced(Node*root)
{
    if (root==NULL){
        return true;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return (abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right));
}
//Efficient Solution with TC of O(n)
int isbalanced1(Node*root)
{
    if(root==NULL){
        return ;
    }
    int lh=height(root->left);
    if(lh==-1){
        return -1;
    }
    int rh= height(root->right);
    if(rh==-1){
        return -1;
    }
    if(abs(lh-rh)>1){return -1;}
    else {
        return max(lh,rh)+1;
    }
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
    //print (head);
    //cout<< size (head);
// inorder(head);
// cout<<endl;
// preorderIterative(head);
// levelOrderTraversal (head);
cout<<isBalanced(head);
return 0;
}
