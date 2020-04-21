// C++ program to represent weighted graph (by default directed)
// BFS_spath to get the shortest path using stl.
// using STL dummy_vertices shall be added to forcefully employ BFS instead of simply using Dijkstra



#include<bits/stdc++.h>

#define INF INT_MAX;  //INFINITY.
using namespace std; 

//int dummy_vertex = INF;
struct vertex
{
    int id;
    int dist;  //we don't use it in this code but let it be if one wants to get the exact distance not path but as a vector. 
    int pid;
    int color;
};
    
class Graph
{
	public:
        int V;
        int E;
        int  V_Prime;
        int dummy_vertex;
        vector <int> adj[500];  //A vector with total of 500 possible vectors accessed by adj[i] 
        void addEdge(int u, int v, int wt) 
        { 
            V_Prime++;
            adj[u].push_back(dummy_vertex);  //creates one dummy_vertex and makes an edge with u
            //(uncomment it when having directed graph)adj[dummy_vertex].push_back(u); 
            for(int i = 1; i <= wt - 2; i++)
            {
                V_Prime++;  //accomodoting space for a new born dummy_vertex.
                adj[dummy_vertex].push_back(dummy_vertex + 1);//creates wt - 1 dummy_vertices and makes wt - 2 edges among consecutive edges.
                //(uncomment it when having directed graph)adj[dummy_vertex + 1].push_back(dummy_vertex);
                dummy_vertex++;
            }
            //(uncomment it when having directed graph)adj[v].push_back(dummy_vertex); 
            adj[dummy_vertex].push_back(v); //creates one edge b/w alredy existing dummy and v;
            dummy_vertex++;
        } 

        void printGraph() 
        { 
            for (int u = 0; u < V; u++) 
            { 
                cout << "Node " << u << " makes an edge with \n"; 
                for ( auto it =  adj[u].begin() ; it != adj[u].end() ; it++) 
                {
                    int twt = 0;
                    int prev = u;
                    int curr = *it;  //curr is a child of u(prev)
                    twt++;  //tempweight
                    while(curr >= V)
                    {
                        if(adj[curr][0] != prev)  // adj[v][0] is a child of v;
                        {
                            prev = curr;
                            curr = adj[curr][0];
                        }
                        else
                        {
                            prev = curr;
                            curr = adj[curr][1];
                        }
                        twt++;
                    }
                    cout << "\tNode " << curr << " with edge weight ="
                        << twt  << endl << endl;  
                } 
            }
        }
};
 
 
vector<vector<int>> BFS_SPATH(Graph G, vertex s);

int main() 
{ 
	Graph G;
    vertex s;
    int x, y, wt;
    printf("Enter the no of nodes in the Graph: ");
    cin >> G.V;
    G.V_Prime = G.V;
    G.dummy_vertex = G.V;
    printf("Enter the no of edges in the Graph: ");
    cin >> G.E;
    vector<vector<int>> Output_Vector(G.V_Prime);
    for(int i = 0; i < G.E; i++)
    {
        cin >> x >> y >> wt;
        G.addEdge(x, y, wt);
    }
    cout << "\nGraph:" << endl;
	G.printGraph(); 
    printf("Enter BFS source vertex: ");
    cin >> s.id;
    Output_Vector = BFS_SPATH(G, s);
    cout << "Output vector" << endl;
    for(int i = 0; i < G.V; i++)
    {
        cout << "spath of " << i << ": ";
        for(int j = 0; j < G.V_Prime && Output_Vector[i][j] != -1 ; j++)
            cout << Output_Vector[i][j] << "  ";
        cout << endl;
    }
    return 0; 
}



vector<vector<int>> BFS_SPATH(Graph G, vertex s)
{
    int u;
    vector <vector <int>> spath (G.V_Prime); 
    vertex Vertex_Array[G.V_Prime];
    for(int i = 0; i < G.V_Prime; i++)
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
            Vertex_Array[i].pid = G.V_Prime;  //sort of NIL an indication of having no parent.
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
            if(Vertex_Array[*it].color == 0)
            {
                Vertex_Array[*it].color = 1; 
                Vertex_Array[*it].dist = Vertex_Array[u].dist + 1;
                Vertex_Array[*it].pid = u; 
                Q.push(Vertex_Array[*it].id);
            }
        }
        Vertex_Array[u].color = 2;
    }

    //below part is just to make a ordered collection of parents, done for every node. 
    u = 0;
    spath[s.id].push_back(0);
    while(u != G.V_Prime)
    {
        if(u < G.V)   //ensuring we don't push dummy_vertices.
        {
            int i = u;
            while(Vertex_Array[i].pid != G.V_Prime)
            {
                if(Vertex_Array[i].pid < G.V)
                    spath[u].push_back(Vertex_Array[i].pid);
                i = Vertex_Array[i].pid;
            }
            spath[u].push_back(-1); //to pad -1 for indication of end
        }
        u++;
    }
    return spath;
}
