#include<iostream>
#include<queue>
#include<vector>
// This is called KAHN's algorithm
using namespace std;
// We can store the indegree by either manipulating the add edge fucntion or in the sort function itself
void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    // indegree[u]=indegree[u]+1;
}

void topologicalSort(vector<int> adj[],int size)
{
    // 1.Store indegree of every vertex in the graph
    int indegree[size]={0};
    for (int i = 0; i < size; i++)
    {
        for(auto x: adj[i])
        {
            indegree[x]++;
        }
    }
    queue<int> q;
    for(int i=0;i<size;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(auto x:adj[u])
        {
            indegree[x]--;
            if(indegree[x]==0)
            {
                q.push(x);
            }
        }
    }
}

    int main(int argc, char const *argv[])
{
    vector<int> v[4];
    // int indegree[4]={0};
    addEdge(v,0,1);
    addEdge(v,0,2);
    addEdge(v,1,3);
    addEdge(v,1,2);
    addEdge(v,2,3);
    // printEdge(v,4);
    topologicalSort(v,4);
    return 0;
}
    

