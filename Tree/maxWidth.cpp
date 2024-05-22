#include <iostream>
#include <queue>
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
//Hint --> use of line by line level order traversal 
//Tc  and as is same as that of line by line level order traversal 
int maxWidth(Node*root)
{
    if(root==NULL){
        return 0;
    }
    int max1;
    queue<Node*> q;
    q.push(root);
    int res=0;
    while(q.empty()==false)
    {
        // q.pop();
        int count1=q.size(); 
        res=max(res,count1);
        for(int i=0;i<count1;i++)
        {
        Node*curr=q.front();
        // v.push_back(curr);
            q.pop();
        if(curr->left!=NULL){q.push(curr->left);}   
        if(curr->right!=NULL){q.push(curr->right);}   
        }
        // int count2=q.size();
        // max1=max(count1,count2);
    }
    return res;

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
cout<<maxWidth(head);
return 0;
}