#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    int vertex;
    int weight;
    struct node * points_to;
};

class Graph
{
    public:
        int number_of_nodes;
        int color;
        struct node * arr[100];

        Graph()
        {
            cout<<"Enter the no. of nodes in the Graph: ";
            cin>>number_of_nodes;
        }

        void Add_Edge(int src, int dest, int weight, struct node * arr[])
        {
            struct node * temp = (struct node *)malloc(sizeof(struct node*));
            temp->vertex = dest;
            temp->weight = weight;
            temp->points_to = arr[src];
            arr[src] = temp;
        }

        void Print_Graph(struct node * adj[], int number_of_nodes)
        {   
            struct node * thptr;
            for(int i = 0; i < number_of_nodes; i++)
            {
                thptr = adj[i];
                while(thptr != NULL)
                {
                    printf("%d---(wt:%d)-->%d ", i, thptr->weight, thptr->vertex);
                    thptr = thptr->points_to;
                }
                cout<<endl;
            }
        }

        void Graph_Construction()
        {
            char ch;
            int weight;
            printf("hi");
            for(int i = 0; i < number_of_nodes; i++)
            {
                arr[i] = NULL;   //Initializing the adjacency array with NULL
                for(int j = 0; j < number_of_nodes; j++)
                {
                    if(i != j)
                    {
                        printf("Is there an edge from %d to %d ?: y/n:   ", i, j);
                        cin>>ch;
                        switch(ch)
                        {
                            case 'y':
                                printf("Enter the weight of the directed edge %d---->%d ", i, j);
                                cin>>weight;
                                Add_Edge(i, j, weight, arr);
                                break;
                            case 'n':
                                break;
                        }
                    }
                }
            }
        }
};


void print(Graph G);
void Graph_Construction(Graph G);
void Prin_Graph(Graph G);
int main()
{
    Graph G;
    G.Graph_Construction();
    G.Print_Graph(G.arr, G.number_of_nodes);
    cout<<G.color<<endl;
    print(G);
    cout<<G.color<<endl;
    G.color = 7;
    cout<<"nod"<<endl;
    cout<<G.color<<endl;
    //Prin_Graph(G);
    return 0;
}

void print(Graph G)
{
    G.color = 6;
    G.Print_Graph(G.arr, G.number_of_nodes);
    cout<<"in "<<G.color<<endl;
}

void Prin_Graph(Graph G)
{   
    struct node * thptr;
    for(int i = 0; i < G.number_of_nodes; i++)
    {
        thptr = G.arr[i];
        while(thptr != NULL)
        {
            printf("%d---(wt:%d)-->%d ", i, thptr->weight, thptr->vertex);
            thptr = thptr->points_to;
        }
        cout<<endl;
    }
}









