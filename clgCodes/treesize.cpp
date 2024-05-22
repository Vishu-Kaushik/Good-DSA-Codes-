#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void print (Node*root)
{
    if(root==NULL)
    {
        return ;
    }
    else{
        print(root->left);
        cout<<root->data<<" ";
        print(root->right);
    }
}
Node * insert(Node *root, int k )
{
    
}
int size(Node*root)
{//wrong code try again
    int count;
    if(root==NULL)
    {
        return count;
    }
    if(root!=NULL)
    {
    int count=0;
        size(root->left);
        if(root->left==NULL)
        {
            return count ++;
        }
        size(root->right);
        if(root->right==NULL)
        {
            return count++; 
        }

    }
    return count ++;
}
//iterative inorder traversal whose TC is O(n) and AS is O(h)
void inorder (Node *root)
{
    stack<Node*> s;
    Node*curr= root;
    while(curr!=NULL || s.empty()==false)
    {
         while(curr!=NULL)
         {
            s.push(curr);
            curr=curr->left;
         }
         curr=s.top();
         s.pop();
         cout<<(curr->data)<<" ";
         curr=curr->right;
    }
}
//iterative preorder traversal  whose tc is O(n) and AS is O(n)
void preOrder(Node*root)
{
    if(root==NULL)
    {return ;}
    stack<Node*> s;
    s.push(root);
    while(s.empty()==false)
    {
        Node*curr=s.top();
        cout<<(curr->data)<<" ";
        s.pop();
        if(curr->right!=NULL)
        {
             s.push(curr->right);
        }
        if(curr->left!=NULL)
        {
            s.push(curr->left);
        }
    }
}
//Space optimized iterative solution for preorder traversal of a tree 
// whose TC is O(n) but the auxiliary space required is O(h) where h is the height of the binary tree
 void preorderIterative(Node*root)
 {
    stack<Node*> s;
    Node*curr=root;
    if(root==NULL)
    {
        return ;
    }
    while(curr!=NULL || s.empty()==false)
    {
        while(curr!=NULL)
        {
            cout<<curr->data<<" ";
            if(curr->right!=NULL)
            {
                s.push(curr->right);
            }
            curr=curr->left;
        }
        if(s.empty()==false)
        {
            curr=s.top();
            s.pop();
        }
    } 

 }
 void levelOrder(Node*root)
 {
    if(root==NULL)
        return;
    queue<Node*> q;
    // Node*curr=root;
    q.push(root);
    while(q.empty()==false) 
    {
        Node*curr=q.front();
        q.pop();
        cout<<(curr->data)<<" ";
        if(curr->left!=NULL)
        {
            q.push(curr->left);
        }
        if(curr->right!=NULL)
        {
            q.push(curr->right);
        }
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
levelOrder (head);
return 0;
}