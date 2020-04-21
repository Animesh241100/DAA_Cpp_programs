#include<iostream>
#include<stdlib.h>

using namespace std;

/*typedef struct 
{
    int a;
    int b;
}
class Graph
{
    public:
        

}*/
struct node
{
    int vertex;
    int weight;
    struct node * points_to;
};

void Add_Edge(int src, int dest, int weight, struct node * arr[]);
void Print_Graph(struct node * adj[], int number_of_nodes);

int main()
{
    int number_of_nodes, weight;
    char ch;
    cout<<"Enter the no. of nodes in the Graph: ";
    cin>>number_of_nodes;
    struct node * arr[number_of_nodes];
    for(int i = 0; i < number_of_nodes; i++)
    {
        arr[i] = NULL;   //Initially the adjacency array with NULL
        for(int j = 0; j < number_of_nodes; j++)
        {
            if(i != j)
            {
                printf("Does there exist an edge from %d to %d: y/n", i, j);
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
    Print_Graph(arr, number_of_nodes);
    return 0;
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







