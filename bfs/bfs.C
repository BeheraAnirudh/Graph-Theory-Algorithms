#include<stdio.h>

#include<stdlib.h>

/* Represent various colors for the nodes and updated

while the algorithm runs. */

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INFINITY 10000
#define NIL 0
#define ANSI_COLOR_RED  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/* Structure for holding the graph nodes */

struct queue

{

    int data;

    struct queue * link;

}* QUEUE = NULL;

/* Function declarations for the queue operations like:

a. Enqueue a node into the queue

b. Dequeue a node out of the queue */

int enqueue(int v);

int dequeue();

/* Global variables for holding color of nodes, discovery time and

predecessor nodes respectively */

int * color, * dist, * pred;

/* Global variable to hold the number of elements in the graph */

int n;

int main(int argc, char * argv[])

{

    int i, j, * v, u;

    int ** adj, src;
    printf(ANSI_COLOR_RED  "ANIRUDHA_BEHERA//A20503687//ECE588-22FALL"  ANSI_COLOR_RESET "\n"); 
    printf("-----Breadth-First-Search Algorithm-------\n");
    printf("========================================\n");
    printf("Enter the number of vertices in the graph: ");

    scanf("%d", & n);

    /* Record the graph nodes depending on the number of inputs */

    v = (int * ) malloc(n * sizeof(int));

    for (i = 0; i < n; i++)

        v[i] = i;

    /* Allocate memory for the matrix representation of the graph */

    adj = (int ** ) malloc(n * sizeof(int * ));

    for (i = 0; i < n; i++)

        adj[i] = (int * ) malloc(n * sizeof(int));

    /* Input the adjacency matrix */

    printf("\n enter the adjacency matrix: \n");

    for (i = 0; i < n; i++)

    {

        for (j = 0; j < n; j++)

            scanf("%d", & adj[i][j]);

    }

    printf("\n Enter the source node: ");

    scanf("%d", & src);

    src -= 1;

    color = (int * ) malloc(n * sizeof(int));

    dist = (int * ) malloc(n * sizeof(int));

    pred = (int * ) malloc(n * sizeof(int));

    /* Initialize the color matrix, discovery times and

    predecessor nodes */

    for (i = 0; i < n; i++)

        if (v[i] != src)

    {

        color[i] = WHITE;

        dist[i] = INFINITY;

        pred[i] = NIL;

    }

    /* Source is covered initially and hence color is gray */

    color[src] = GRAY;

    /* Distance from source to itself is 0 because we are considering

    only simple graphs */

    dist[src] = 0;

    /* Source node is the starting node and hence predecessor for the

    source node is 0 */

    pred[src] = NIL;

    /* Enqueue the source node */

    enqueue(src);

    printf("\n BFS order is: \n");

    printf("ORDER\tPREDECESSOR\tDISCOVERY TIME\n");

    printf("-----\t-----------\t---------------\n");

    while (QUEUE != NULL)

    {

        u = dequeue();

        printf("%d\t%d\t\t%d\n", u + 1, pred[u] + 1, dist[u]);

        for (i = 0; i < n; i++)

        {

            /* To implement the BFS, we have to check if the adjacent nodes of u is infinity or 1

            and check the color of adjacent nodes of u. If the color of adjacenct nodes

            of u is white and node values adjacent of u is not infinity then :

            a. update the adjacent node color of u to gray in the color matrix.

            b. update the discovery time as (current discovery time + 1) in the discovery time matrix.

            c. Update u's adjacent node's predecessor as u in the predecessor matrix.

            d. Enqueue the adjacent nodes of u using the enqueue() function.

            e. Mark adjacent nodes of u as infinity in the adjacency matrix */

            if (adj[u][i] == 1 && color[i] == WHITE) // check if adjecent edge and not visited
            {
                color[i] = GRAY; // mark as visited
 
                dist[i] = dist[u] + 1; // update discovery time

                pred[i] = u; // update predecessor

                enqueue(i); // enqueue the node

                adj[u][i] = INFINITY; // mark as infinity

            }

        }

        color[u] = BLACK; // mark as visited

    }

}

/* The enqueue function adds a graph node to the queue front */

int enqueue(int v)
{

    struct queue * temp;

    temp = (struct queue * ) malloc(sizeof(struct queue * ));

    temp -> data = v;

    temp -> link = QUEUE;

    QUEUE = temp;

    return 1;
}

/* The dequeue function removes the rear element in the queue */

int dequeue()

{

    struct queue * front, * rear;

    int data;

    front = QUEUE;

    if (front -> link != NULL)

        front = front -> link;

    else

    {

        data = front -> data;

        QUEUE = NULL;

        return (data);

    }

    rear = QUEUE;

    while (front -> link != NULL)

    {

        front = front -> link;

        rear = rear -> link;

    }

    data = front -> data;

    rear -> link = NULL;

    free(front);

    return data;

}

