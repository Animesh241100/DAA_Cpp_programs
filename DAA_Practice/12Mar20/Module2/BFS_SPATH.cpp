// C++ program to represent undirected and unweighted graph 
// using STL// BFS_spath to get the shortest path using stl.


#include<bits/stdc++.h>

#define INF INT_MAX;  //INFINITY.
using namespace std; 

struct vertex
{
    int id;
    int dist;  //we don't use it in this code but let it be if one wants to get the exact distance not path as a vector. 
    int pid;
    int color;
};
    
class Graph
{
	public:
        int V;
        int E;
        vector<pair<int, int> > adj[20]; 

        void addEdge(int u, int v, int wt) 
        { 
            adj[u].push_back(make_pair(v, wt)); 
            //(uncomment for undirected graphs)adj[v].push_back(make_pair(u, wt)); 
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
 
 
vector<vector<int>> BFS_SPATH(Graph G, vertex s);

int main() 
{ 
	Graph G;
    vertex s;
    int x, y;
    printf("Enter the no of nodes in the Graph: ");
    cin >> G.V;
    printf("Enter the no of edges in the Graph: ");
    cin >> G.E;
    vector<vector<int>> Output_Vector(G.V);
    for(int i = 0; i < G.E; i++)
    {
        cin >> x >> y;
        G.addEdge(x, y, 1);
    }
    printf("Enter BFS source vertex: ");
    cin >> s.id;
    Output_Vector = BFS_SPATH(G, s);
    cout << "Output vector" << endl;
    for(int i = 0; i < G.V; i++)
    {
        for(int j = 0; j < G.V && Output_Vector[i][j] != -1 ; j++)
            cout << Output_Vector[i][j] << "  ";
        cout << endl;
    }
    cout << "\nGraph:" << endl;
	G.printGraph(); 
	return 0; 
} 

vector<vector<int>> BFS_SPATH(Graph G, vertex s)
{
    int u;
    vector <vector <int>> spath (G.V); 
    vertex Vertex_Array[G.V];
    for(int i = 0; i < G.V; i++)
    {
        Vertex_Array[i].id = i;
        if(i != s.id)
        {
            Vertex_Array[i].dist = INF;
            Vertex_Array[i].pid = 0;
            Vertex_Array[i].color = 0; //white
        }
        else
        {
            Vertex_Array[i].color = 1;  //gray
            Vertex_Array[i].dist = 0;
            Vertex_Array[i].pid = G.V;  //sort of NIL an indication of having no parent.
        }
    }
   
    queue <int> Q;
    Q.push(s.id);
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for(auto it = G.adj[u].begin(); it < G.adj[u].end(); it++)
        {  
            if(Vertex_Array[it->first].color == 0)
            {
                Vertex_Array[it->first].color = 1; 
                Vertex_Array[it->first].dist = Vertex_Array[u].dist + 1;
                Vertex_Array[it->first].pid = u; 
                Q.push(Vertex_Array[it->first].id);
            }
        }
        Vertex_Array[u].color = 2;
    }
    u = 0;
    spath[s.id].push_back(0);
    while(u != G.V)
    {
        int i = u;
        int count = 0;
        while(Vertex_Array[i].pid != G.V)
        {
            spath[u].push_back(Vertex_Array[i].pid);
            i = Vertex_Array[i].pid;
            count++;
        }
        spath[u].push_back(-1); //to pad -1 for indication of end
        u++;
    }
    return spath;
}