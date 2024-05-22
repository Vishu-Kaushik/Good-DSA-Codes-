#include <iostream>
using namespace std;
#include<stack>
#include<queue>
struct Node{
    Node*left , *right ;
    int data;
    Node(int x)
    {
        data=x;
        left=right=NULL;
    }
};
//Time complexity is O(n) and Auxiliary space is O(n) or theta(width)
void levelOrderTraversal(Node*root)
{
    if(root==NULL)
    {
        return ;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL); //This is a end of level marker
    while(q.size()>1)
    {
        Node*curr=q.front();
        q.pop();
        if(curr==NULL)
        {
            cout<<endl;
            q.push(NULL);
            continue;
        }
        cout<<curr->data<<" ";
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
void levelOrder1(Node*root) // TC is O(n) becoz in the inner loop we go into queue once and come out of queue once which is a constant operation 
// AS is theta(width of tree)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(q.empty()==false)
    {
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            Node*curr=q.front();
            q.pop();   
            cout<<(curr->data)<<" ";
            if(curr->left!=NULL) {q.push(curr->left);}
            if(curr->right!=NULL) {q.push(curr->right);}
        }
        cout<<"\n";
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
levelOrder1(head);
return 0;
}

