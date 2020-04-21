#include<iostream>
#include<bits/stdc++.h>
//#include "GraphSTL.h"
#include "Module1.h"
//#include "Module1.cpp"

using namespace std;

/*
class Vertex
{
    public:
        int id;
        int color;
        int dist;
        int pid;
        int Topological_Number;
        int In_Degree;
        //Vertex();
};


class Graph
{
    public:
    int V;
    int E;
    Vertex Vertex_Array[200];
    vector <int> adj[20];
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
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
};*/


vector<int> LPATH(Graph &G);
void Initialize_for_BFS(Graph &G, int s);
//Graph BFS(Graph &G,int s);


int main()
{
    Graph G;
    int s;  
    vector<int> lpath(G.V + 1);
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
        G.addUEdge(x,y);
    }
    lpath = LPATH(G);
    cout << "The length of the lpath is :" << lpath[0] << endl;
    for(auto it = lpath.begin() + 1; it != lpath.end(); it++)
        cout << "(" << *it << ")<--";
    //cout << " " << G.Vertex_Array[3].id << endl;
    return 0;
}


vector<int> LPATH(Graph &G) //an unweighted tree.
{
    int max_dist = 0;
    vector<int> Final_vector(G.V + 1);
    int deepest_node_id = 0;     //first_end_of_lpath_id
    int second_end_of_lpath_id = 0;
    for(int i = 0; i < G.V; i++)
        cout << G.Vertex_Array[i].id << " " << G.Vertex_Array[i].pid  << endl;
    Initialize_for_BFS(G, 0);
    for(int i = 0; i < G.V; i++)
        cout << G.Vertex_Array[i].id << " " << G.Vertex_Array[i].pid  << endl;
    BFS(G, 0); 
    for(int i = 0; i < G.V; i++)
    {
        if(max_dist < G.Vertex_Array[i].dist)
        {
            max_dist = G.Vertex_Array[i].dist;
            deepest_node_id = i;
        }
    }
    max_dist = 0;
    Initialize_for_BFS(G, deepest_node_id);
    for(int i = 0; i < G.V; i++)
        cout << G.Vertex_Array[i].id << " " << G.Vertex_Array[i].pid  << endl;
    BFS(G, deepest_node_id);
    for(int i = 0; i < G.V; i++)
    {
        if(max_dist < G.Vertex_Array[i].dist)
        {
            max_dist = G.Vertex_Array[i].dist;
            second_end_of_lpath_id = i;
        }
    }
    int i = second_end_of_lpath_id;
    int j = 1; 
    while(G.Vertex_Array[i].id != deepest_node_id)
    {
        Final_vector[j] = i;
        i = G.Vertex_Array[i].pid;
        j++;
    }
    Final_vector[0] = j - 1;
    Final_vector[j] = i;
    Final_vector.resize(j + 1);
    return Final_vector ;
}


void Initialize_for_BFS(Graph &G, int s)
{
    for(int i = 0; i < G.V; i++)
    {
        G.Vertex_Array[i].id = i;
        if(i != s)
        {
            G.Vertex_Array[i].color = 0;
            G.Vertex_Array[i].dist = INFINITY;
            G.Vertex_Array[i].pid = -2;
        }
    }
}


  /*  
Graph BFS(Graph &G, int s)
{
    Graph T;
    queue <int> q;
    T.V=G.V;
    q.push(s);
    G.Vertex_Array[s].color=1;
    G.Vertex_Array[s].pid=G.V; //NULL
    G.Vertex_Array[s].dist=0;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        cout<<t<<" ";
        for(int k=0;k<G.adj[t].size();k++)
        {
            int x=G.adj[t][k];
            if(G.Vertex_Array[x].color==0)
            {
                q.push(x);
                G.Vertex_Array[x].pid=t;
                G.Vertex_Array[x].dist=G.Vertex_Array[t].dist+1;
                G.Vertex_Array[x].color=1;
                T.adj[t].push_back(x);
                T.adj[x].push_back(t);
            }
        }
    }
    return T;
}*/