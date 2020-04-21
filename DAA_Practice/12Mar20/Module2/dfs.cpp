#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    public:
    int V;
    int E;
    vector <int> adj[20];
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
    } 
    void printGraph()
    {
        for(int u=0;u<V;u++)
        {
            cout<<"Vertex "<<u<<":";
            for(int v=0;v!=adj[u].size();v++)
                cout<<adj[u][v]<<" ";
            cout<<endl;
        }
    }
};  
void BFS(Graph G);
int visit[20]={0};
stack <int> s;
int main()
{
    Graph G;
    cout<<"Enter the number of vertices:";
    cin>>G.V;
    cout<<"Vertices are:";
    for(int u=0;u<G.V;u++)
        cout<<u<<" ";
    cout<<"\nEnter the number of edges:";
    cin>>G.E;
    for(int l=0;l<G.E;l++)
    {
        int x,y;
        cin>>x>>y;
        G.addEdge(x,y);
    }
    cout<<"BFS result:"<<endl;
    BFS(G);
    cout<<endl;
    return 0;
}
void DFS(Graph G)
{
   int time = 0;
   for(int i =0; i < G.V; i++)
   {
       if(visit[
}
        
