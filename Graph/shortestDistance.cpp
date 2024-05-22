#include<iostream>
#include<vector>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
vector<int> minDistance(vector<int> adj[],int s,int v)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i]=false;
    }
    vector<int> dist(v,INT8_MAX);
    dist.at(s)=0;
    queue<int> q;
    visited[s]=true;
    q.push(s);
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        for(auto x: adj[u])
        {
            if(visited[x]==false)
            {
                visited[x]=true;
                dist[x]=dist[u]+1;
                q.push(x);
            }
        }
    }
    return dist;
}
int main(int argc, char const *argv[])
{
    vector<int> v[10];
    addEdge(v,0,1);
    addEdge(v,0,2);
    addEdge(v,1,3);
    addEdge(v,1,2);
    addEdge(v,2,3);
    addEdge(v,0,3);
    addEdge(v,2,6);
    vector<int> vec= minDistance(v,0,10);
    // printEdge(v,4);
    // mindistance(v,0,10)
    for(auto it=vec.begin();it< vec.end();it++)
    {
        cout<< *it<<" ";
    }
    return 0;
}