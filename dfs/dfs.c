#include<stdio.h>
#include<stdlib.h>

#define WHITE 1
#define GRAY 2
#define BLACK 3
#define NIL 100
#define INFINITY 10000

#define ANSI_COLOR_RED  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"
int dfs(int u);

/* 'n' is the number of nodes and 'time' is the discovery time of a node */
int n,time;

/* Adjacency matrix to hold the graph */

int **adj;

/* Matrix to hold the graph's node color */

int *color;

/* Matrix to hold the predecessor node values */

int *pred;

/* Matrix to hold the discovery time of a node */

int *dist;

/* Matrix to hold the finishing time of a node */

int *finish;

int main()
 {
   int i,j;
   printf(ANSI_COLOR_RED  "ANIRUDHA_BEHERA//A20503687//ECE588-22FALL"  ANSI_COLOR_RESET "\n");
   printf("-------------DFS Algorithm-------------\n");
   printf("========================================\n");
   printf("\n Enter the number of nodes: ");
   scanf("%d",&n);

   /* Memory allocation for all matrices is done here */

   adj = (int**)malloc(sizeof(int*));

   for(i=0;i<n;i++)
	   adj[i] = (int*)malloc(n*sizeof(int));

   color=(int*)malloc(n*sizeof(int));
   pred=(int*)malloc(n*sizeof(int));
   dist=(int*)malloc(n*sizeof(int));
   finish=(int*)malloc(n*sizeof(int));

   printf("\n Enter the adjacency matrix: ");

   for(i=0;i<n;i++)
    {
     for(j=0;j<n;j++)
       scanf("%d",&adj[i][j]);
    }
   
	/* Initialization of matrices */

    for(i=0;i<n;i++)
      {
       color[i]=WHITE;
       pred[i]=NIL;
      }

    /* set discovery time of starting node as 0 */

    time=0;

	printf("\n Node\tFinish Time\n");
	printf("----\t-----------\n");
    for(i=0;i<n;i++)
     {
		/* If the color of node is white then call dfs */

      if(color[i] == WHITE)
      dfs(i);
     }
  }

  int dfs(int u)
   {
int i;
color[u] = GRAY;
time+=1;
dist[u] = time;
for(i=0;i<n;i++)
{
if(adj[u][i] !=INFINITY && color[i] == WHITE)
{
pred[i] = u;
dfs(i);
}

color[u] = BLACK;
}
time+=1;
dist[u] = time;
finish[u] = dist[u];
printf("%d\t%d\n",u,finish[u]);
}
