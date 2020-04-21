//The minheap implementation of Dijkstra's Algo. This implementation can be very important if you want to understand how to make a priority queue or minheap using



#include <iostream>
#include <bits/stdc++.h>
using namespace std; 

struct Vertex
{
    int id;
    int dist; 
    int pid;
    int color;
};

class Graph
{
	public:
        int V;
        int E;
        Vertex Vertex_Array[100];
        vector<pair<int, int> > adj[100];
        void addEdge(int u, int v, int wt) 
        { 
            adj[u].push_back(make_pair(v, wt)); 
        } 
        void printGraph()
        {
            for (int u = 0; u < V; u++) 
            { 
                cout << "Node " << u << " connects to \n"; 
                for (auto it = adj[u].begin(); it != adj[u].end(); it++) 
                {  
                    cout << "\tNode " << it->first << " with edge weight ="
                        << it->second << endl;
                }
                cout << endl; 
            } 
        }
}; 

class Pair
{
    public:
        int Vertex_id;
        int d;
        Pair(int id, int distance) 
        { 
            Vertex_id = id; 
            d = distance; 
        } 
        
        int getID() const { return Vertex_id; } 
        int getDIST() const { return d; }  
}; 
  
// To compare two Pairs 
class myComparator 
{ 
    public: 
        int operator() (const Pair& p1, const Pair& p2)
        { 
            return p1.getDIST() > p2.getDIST(); 
        } 
};

int Set[100];
Graph All_pair_spath_tree;
void Dijkstra(Graph &G, Vertex s);
void Initialize_single_source(Graph &G, Vertex s);
 
int main()
{
    Graph G;
    Vertex s;
    int x, y, wt, p;
    cout << "Enter the no. of vertices: ";
    cin >> G.V;
    cout << "Enter the no. of edges: ";
    cin >> G.E;
    cout << "Enter the edges one by one:\n";
    for(int i = 0; i < G.E; i++)
    {
        cin >> x >> y >> wt;
        G.addEdge(x, y, wt);
    }
    cout << "input graph: " << endl;
    G.printGraph();
    All_pair_spath_tree.V = G.V;
    All_pair_spath_tree.E = G.E;
    //while(p != -1) //you can run a loop to find all pair shortest paths for all vertices. which have nozero out-degrees
   // {
        cout << "Enter dijkstra's source: ";
        cin >> p;
        s.id = p;
        Dijkstra(G, s);
        cout << "Dijkstra graph: " << endl;
        All_pair_spath_tree.printGraph();
  //  }
    return 0;
}

void Dijkstra(Graph &G, Vertex s)
{
    Initialize_single_source(G, s);
    int u, v, wt;
    priority_queue<Pair, vector<Pair>, myComparator> Min_Heap;
    for(int i = 0; i < G.V; i++)
    {
        Set[i] = 0;
        Min_Heap.push(Pair(i, G.Vertex_Array[i].dist)); 
    } 
    while(Min_Heap.empty() == false)
    {
        Pair P = Min_Heap.top(); //extract min
        Min_Heap.pop();
        u = P.getID();
        Set[u] = 1; //include in Set 
        for(auto it = G.adj[u].begin(); it != G.adj[u].end(); it++)
        {
            v = it->first;
            wt = it->second;
            if(G.Vertex_Array[v].dist > G.Vertex_Array[u].dist + wt && Set[v] == 0)
            {
                G.Vertex_Array[v].dist = G.Vertex_Array[u].dist + wt;
                G.Vertex_Array[v].pid = u;
                P.Vertex_id = v; //making pair of new dist value and 'v'
                P.d = G.Vertex_Array[v].dist;
                Min_Heap.push(P);   //pushing it into the heap because there is no way it is possible to update the weight of 'v' in the heap, so we have to re-insert.
            }
        }
    }
    for(int i = 0; i < All_pair_spath_tree.V; i++)
    {
        All_pair_spath_tree.addEdge(G.Vertex_Array[i].pid, i, 1);
    }

}

void Initialize_single_source(Graph &G, Vertex s)
{
    for(int i = 0; i < G.V; i++)
    {
        G.Vertex_Array[i].id = i;
        G.Vertex_Array[i].dist = INFINITY;
        G.Vertex_Array[i].pid = -2;
    }
    G.Vertex_Array[s.id].dist = 0;
}
    