#include<iostream>
#include<vector>
using namespace std;

//void BFS(struct node * ptr);
void addEdge(vector<pair<int, int> > adj[], int u, int v, int wt);
void printGraph(vector<pair<int,int> > adj[], int V);

class Graph
{
    public:
        static int V = 5;
        vector<pair<int, int>> adj[V];
        //void addEdge(vector <pair<int, int>> adj[], int u, int v, int wt)
        void addEdge(int u, int v, int wt) 
        { 
            cout<<"adj.size =" << adj[].size <<"V = " << V << endl; 
            adj[u].push_back(make_pair(v, wt)); 
            adj[v].push_back(make_pair(u, wt)); 
        } 
        //void printGraph(vector<pair<int,int> > adj[], int V) 
        void printGraph(int V) 
        { 
            int v, w; 
            for (int i = 0; i < V; i++) 
            { 
                cout << "Node " << i << " makes an edge with \n"; 
                for (auto j = adj[i].begin(); j != adj[i].end(); j++) 
                { 
                    v = j->first; 
                    w = j->second; 
                    cout << "\tNode " << v << " with edge weight =" << w << "\n"; 
                } 
                cout << "\n"; 
            } 
        }

}

int main()
{
    /*int V = 5;
    vector<pair<int, int>> adj[V];
    addEdge(adj, 0, 1, 10);
    printGraph(adj, 5)*/
    Graph G;
    G.V = 5;
    G.addEdge(0, 1, 10);
    G.printGraph(G.V);
}


  
// Print adjacency list representaion ot graph 
 
/*
void BFS(class Graph)
{
    
}*/



   
