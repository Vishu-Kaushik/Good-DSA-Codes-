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
int maxLevel=0;
// Recursive Solution --> idea is to use the preorder traversal technique
void leftView1(Node*root,int level)
{
    if(root==NULL){
        return ;
    }
    if(maxLevel<level)
    {
        cout<<root->data<<" ";
        level=level+1;
    }
    leftView1(root->left,level+1);
    leftView1(root->right,level+1);
}


void printleftView1(Node*root)
{
    leftView1(root,1); // --> initially level is passed as 1 because of root as it is at level 1 and also the left most element of its level
}
// interative
void leftView(Node*root) // TC is O(n) and auxiliary space is O(width)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    vector<int> v;
    while(q.empty()==false)
    {
        int count=q.size();
        Node*curr=q.front();
        v.push_back(8);
        for(int i=0;i<count;i++)
        {
            q.pop();
        }
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
    leftView(head);
    return 0;
}