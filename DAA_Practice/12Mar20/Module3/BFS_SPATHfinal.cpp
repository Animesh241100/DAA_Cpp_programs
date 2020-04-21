// C++ program to represent weighted/unweighted graph (by default directed)
// BFS_spath to get the shortest path.
// using STL dummy_vertices shall be added to forcefully employ BFS instead of simply using Dijkstra in case of weighted graphs.



#include<bits/stdc++.h>


using namespace std; 


struct vertex
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
        int  V_Prime;
        int dummy_vertex;
        vector <int> adj[500];  //adjacency list for weighted 
        void BFS_SPATH_addEdge(int u, int v, int wt, int flag) 
        { 
            if(flag == 0) //unweighted graph
            {
                adj[u].push_back(v); 
            }
            else   //weighted graph
            {
                V_Prime++;
                adj[u].push_back(dummy_vertex);  //creates one dummy_vertex and connects it to u
                for(int i = 1; i <= wt - 2; i++)
                {
                    V_Prime++;  //accomodoting space for a new born dummy_vertex.
                    adj[dummy_vertex].push_back(dummy_vertex + 1);//creates wt - 1 dummy_vertices and makes wt - 2 edges among consecutive edges.
                    dummy_vertex++;
                }
                adj[dummy_vertex].push_back(v); //creates an edge from dummy to v;
                dummy_vertex++;
            }
        } 

        void BFS_SPATH_printGraph(int flag) 
        { 
            if(flag == 0)
            {
                for (int u = 0; u < V; u++) 
                { 
                    cout << "Node " << u << " connects to nodes\t"; 
                    for (auto it = adj[u].begin(); it != adj[u].end(); it++) 
                        cout << *it << ", "; 
                    cout << endl; 
                } 
            }
            else
            {
                for (int u = 0; u < V; u++) 
                { 
                    cout << "Node " << u << " connects to \n"; 
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
        }
};
 
 
vector<vector<int>> BFS_SPATH(Graph G, vertex s, int flag);

int main() 
{ 
	Graph G;
    vertex s;
    int x, y, wt, flag;
    printf("Enter the no of nodes in the Graph: ");
    cin >> G.V;
    G.V_Prime = G.V;
    G.dummy_vertex = G.V;
    printf("Enter the no of edges in the Graph: ");
    cin >> G.E;
    cout << "Enter 1 if the graph is weighted, else 0 ";
    cin >> flag;
    vector<vector<int>> Output_Vector(G.V_Prime);
    for(int i = 0; i < G.E; i++)
    {
        if(flag == 0)
        {
            cin >> x >> y;
            G.BFS_SPATH_addEdge(x, y, wt, flag);
        }
        else
        {
            cin >> x >> y >> wt;
            G.BFS_SPATH_addEdge(x, y, wt, flag);
        }
    }
    cout << "\nGraph:" << endl;
	G.BFS_SPATH_printGraph(flag); 
    printf("Enter BFS source vertex: ");
    cin >> s.id;
    Output_Vector = BFS_SPATH(G, s, flag);
    cout << "Output vector" << endl;
    if(flag == 0)
    {
        for(int i = 0; i < G.V; i++)
        {
            cout << "spath of " << i << ": ";
            for(int j = 0; j < G.V && Output_Vector[i][j] != -1 ; j++)
                cout << "<----(" << Output_Vector[i][j] << ")";
            cout << endl;
        }
    }
    else
    {
        for(int i = 0; i < G.V; i++)
        {
            cout << "spath of " << i << ": ";
            for(int j = 0; j < G.V_Prime && Output_Vector[i][j] != -1 ; j++)
                cout << "<----(" << Output_Vector[i][j] << ")";
            cout << endl;
        }
    }
    cout << "In spath of a node i from source s:\n2147483647 indicates that there exists no path from source to i\n(-2) indicates i is the source vertex itself.\n";
    return 0; 
}



vector<vector<int>> BFS_SPATH(Graph G, vertex s, int flag)
{
    int u;
    queue <int> Q;
    Q.push(s.id);

    if(flag == 0)
    {
        vector <vector <int>> spath (G.V); 
        vertex Vertex_Array[G.V];
        for(int i = 0; i < G.V; i++)
        {
            Vertex_Array[i].id = i;
            if(i != s.id)
            {
                Vertex_Array[i].dist = INFINITY;
                Vertex_Array[i].pid = -2;
                Vertex_Array[i].color = 0; //white
            }
            else
            {
                Vertex_Array[i].color = 1;  //gray
                Vertex_Array[i].dist = 0;
                Vertex_Array[i].pid = G.V;  //sort of NIL an indication of having no parent.
            }
        }
    
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
        spath[s.id].push_back(-2);
        while(u != G.V)
        {
            int i = u;
            while(Vertex_Array[i].pid != G.V)
            {
                if(Vertex_Array[u].pid != -2)
                {
                    spath[u].push_back(Vertex_Array[i].pid);
                    i = Vertex_Array[i].pid;
                }
                else
                {
                    spath[u].push_back(INFINITY);
                    break;
                }
            }
            spath[u].push_back(-1); //to pad -1 for indication of end
            u++;
        }
        return spath;
    }
    else
    {
        vector <vector <int>> spath (G.V_Prime); 
        vertex Vertex_Array[G.V_Prime];
        for(int i = 0; i < G.V_Prime; i++)
        {
            Vertex_Array[i].id = i;
            if(i != s.id)
            {
                Vertex_Array[i].dist = INFINITY;
                Vertex_Array[i].pid = -2;
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
        spath[s.id].push_back(-2); //spath of the source vertex itself is kept as negative.
        while(u != G.V_Prime)
        {
            if(u < G.V)   //ensuring we don't push dummy_vertices.
            {
                int i = u;
                while(Vertex_Array[i].pid != G.V_Prime)
                {
                    if(Vertex_Array[u].pid != -2) //check if the vertex u is traversed using BFS or not.
                    {
                        if(Vertex_Array[i].pid < G.V)
                            spath[u].push_back(Vertex_Array[i].pid);
                        i = Vertex_Array[i].pid;
                    } 
                    else //if it is not traversed, put infinity in its spath
                    {
                        spath[u].push_back(INFINITY);
                        break;
                    }
                }
                spath[u].push_back(-1); //to pad -1 for indication of end
            }
            u++;
        }
        return spath;
    }
}

