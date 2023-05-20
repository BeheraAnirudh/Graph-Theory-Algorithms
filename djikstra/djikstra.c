#include<stdio.h>
#include<stdlib.h>

#define INFINITY 10000
#define NIL 20000
#define TRUE 1
#define FALSE 0
#define ANSI_COLOR_RED  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/* These global variable are used to hold the number of nodes and adjacency matrix
   of the graph respectively */
int n,**adj;

int i1,j2;

/* These variable are used to hold the predecessors, shortest distances and completed nodes
   of the graph */

int *pred,*dist,*completed;

int main(int argc,char **argv[])
 {
   int i=0,j,min,index;
   printf(ANSI_COLOR_RED  "ANIRUDHA_BEHERA//A20503687//ECE588-22FALL"  ANSI_COLOR_RESET "\n"); 
   printf("-----------Djikstra Algorithm-----------\n"); 
   printf("========================================\n");
   printf("\n Enter the number of nodes: ");
   scanf("%d",&n);

   printf("\n Enter the adjacency matrix: ");
   
   /* Memory allocation for the adjacency matrix and other matrices takes place here */

   adj = (int **) malloc( n * sizeof(int *) );

   for(i=0;i<n;i++)
    adj[i]=(int*)malloc(n*sizeof(int));

    
    pred=(int*)malloc(n * sizeof(int));
    dist=(int*)malloc(n * sizeof(int));
    completed=(int*)malloc(n * sizeof(int));
    
   for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
        scanf("%d",&adj[i][j]);
    }
   
	/* Initialization takes place here */

    for(i=0;i<n;i++)
     {
      pred[i]=NIL;
      dist[i]=INFINITY;
      completed[i]=FALSE;
     }
     
	 dist[0]=0;
     index=0;

     /* This part of the program checks if all the nodes' final distances has already been
	    computed or not. If they are not computed yet then this code relaxes all those edges
		whose final distances are not yet computed */

 	 while(checkCompleted())
	 {
		   for(j=0;j<n;j++)
			 {
			    if(adj[index][j] != INFINITY)
				 {
					relax(index,j);
				 }
			 }

		index=findSmallestDistance();
	 }

  printf("\nNode\tDistance from source \n");
  printf("\n----\t--------------------\n");
  for(i=0;i<n;i++)
   printf("%d\t%d\n",i,dist[i]);
}
 
 int relax(int u,int v)
  {
    if (dist[v] > dist[u] + adj[u][v])
     {
       dist[v] = dist[u] + adj[u][v];
       pred[v] = u;
     }
  }
  
  int findSmallestDistance()
  {
    
// taking necessary variables

int j,index,small=INFINITY;

j=0;

while(j<n){
    // main crux

if(completed[j]==FALSE){

if(dist[j]<small){

small=dist[j];

index=j;

}

}

j=j+1;

}

completed[index]=TRUE;

return index;

}
   
 int checkCompleted()
 {
	 int i;

	for(i=0;i<n;i++)
		if(completed[i] == FALSE)
		 return 1;

	return 0;
 }