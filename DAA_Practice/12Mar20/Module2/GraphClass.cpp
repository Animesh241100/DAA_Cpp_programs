struct node
{
    int vertex;
    int weight;
    struct node * nptr;
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
            temp->vertex = dest;
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
                    printf("%d---(wt:%d)-->%d ", i, thptr->weight, thptr->vertex);
                    thptr = thptr->nptr;
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
                Adjacency_list[i] = NULL;   //Initializing the adjacency array with NULL
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
