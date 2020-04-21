#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;


struct Vertex
{
    int Vertex_id;
    char Vertex_name = Vertex_id + 97;

};

struct node
{
    int vid;
    int weight;
    struct node * nptr;
};

struct Qblock
{
    int data;
    struct Qblock * nptr;
};

class Queue
{
    public:
        struct Qblock * front = NULL;
        struct Qblock * rear = NULL;
        void Enqueue(int data)
        {
            struct Qblock * temp = (struct Qblock *)malloc(sizeof(struct Qblock*));
            temp->data = data;
            temp->nptr = NULL;
            if(front == NULL)
            {
                front = temp;
                rear = front;
            }
            else
            {
                rear->nptr = temp;
                rear = temp;
            }
        }
        int Dequeue()
        {
            if(front == NULL)
                return -1947;
            int x = front->data;
            front = front->nptr;
            if(front == NULL) //checking if we have exhausted the list
                rear = NULL;//rear was still pointing to the last node existing, thus rear gets updated only in this phase of dequeuing
            return x;
        }
};            


class Graph
{
    public:
        int number_of_nodes;
        int color;
        struct node * Adjacency_list[100];
        int visit[100];
        
        Graph()
        {
            cout<<"Enter the no. of nodes in the Graph: ";
            cin>>number_of_nodes;
        }

        void Add_Edge(int src, int dest, int weight, struct node * Adjacency_list[])
        {
            struct node * temp = (struct node *)malloc(sizeof(struct node*));
            temp->vid = dest;
            temp->weight = weight;
            temp->nptr = Adjacency_list[src];
            Adjacency_list[src] = temp;
        }

        void Print_Graph(struct node * Adjacency_list[], int number_of_nodes)
        {   
            struct node * thptr;
            for(int i = 0; i < number_of_nodes; i++)
            {
                thptr = Adjacency_list[i];
                while(thptr != NULL)
                {
                    printf("%d---(wt:%d)-->%d ", i, thptr->weight, thptr->vid);
                    thptr = thptr->nptr;
                }
                cout<<endl;
            }
        }

        void Graph_Construction()
        {
            char ch;
            int weight;
            for(int i = 0; i < number_of_nodes; i++)
            {
                Adjacency_list[i] = NULL;   //Initializing the adjacency array with NULL
                for(int j = 0; j < number_of_nodes; j++)
                {
                    Vertex Vi, Vj;
                    Vi.Vertex_id = i;
                    Vj.Vertex_id = j;
                    if(i != j)
                    {
                        printf("Is there an edge from %c to %c ?: y/n:   ", Vi.Vertex_name, Vj.Vertex_name);
                        cin>>ch;
                        switch(ch)
                        {
                            case 'y':
                                printf("Enter the weight of the directed edge %c---->%c ",  Vi.Vertex_name, Vj.Vertex_name);
                                cin>>weight;
                                Add_Edge(i, j, weight, Adjacency_list);
                                break;
                            case 'n':
                                break;
                        }
                    }
                }
            }
        }
};


void BFS(Graph G);
void BFS(Graph G, Vertex V);

int main()
{
    Graph G;
    int vid;
    Vertex V;
    G.Graph_Construction();
    G.Print_Graph(G.Adjacency_list, G.number_of_nodes);
    cout<<"Enter the vertex to start the BFS from  ";
    while(vid != 100)
    {
        cin>>V.Vertex_name;
        //V.Vertex_id = vid - 97;
        BFS(G, V);
        printf("Enter 100 to stop accepting vertices to run BFS");
    }
    cout<<"now algorithm arbitrarily choses a vertex and does the job.\n";
    BFS(G);
    return 0;
}

void BFS(Graph G)
{
    srand(time(0));
    int vid = rand() % (G.number_of_nodes);
    printf("Chosen Vertex is %c .", vid + 97);
    for(int i = 0; i < G.number_of_nodes; i++)
        G.visit[i] = 0;
    G.visit[vid]++;
    Queue Q;
    int u;
    Q.Enqueue(vid);
    while(Q.front != NULL)
    {
        u = Q.Dequeue();
        struct node * thptr = G.Adjacency_list[u];
        while(thptr != NULL) //while you have not traversed through the row of the Adjacency_list belonging to the node 'u'.
        {
            G.visit[thptr->vid]++; //visiting the node adjacent to node u
            Q.Enqueue(thptr->vid);
            thptr = thptr->nptr;
        }
    }
    cout<<"The visit array";
    for(int i = 0; i < G.number_of_nodes; i++)
        printf(" %d ", G.visit[i]);
}

void BFS(Graph G, Vertex V)
{
    int vid = V.Vertex_id;
    for(int i = 0; i < G.number_of_nodes; i++)
        G.visit[i] = 0;
    G.visit[vid]++;
    Queue Q;
    int u;
    Q.Enqueue(vid);
    while(Q.front != NULL)
    {
        u = Q.Dequeue();
        struct node * thptr = G.Adjacency_list[u];
        while(thptr != NULL) //while you have not traversed through the row of the Adjacency_list belonging to the node 'u'.
        {
            G.visit[thptr->vid]++; //visiting the node adjacent to node u
            Q.Enqueue(thptr->vid);
            thptr = thptr->nptr;
        }
    }
    cout<<"The visit array";
    for(int i = 0; i < G.number_of_nodes; i++)
        printf(" %d ", G.visit[i]);
}


    











