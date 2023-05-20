#include<stdio.h>
#define function(a,b) \
 ({ __typeof__ (a) _a = (a); \
 __typeof__ (b) _b = (b); \
 _a < _b ? _a : _b; })\

#define ANSI_COLOR_RED  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int i, j, k,n,dist[10][10];
void floydWarshell ()
{
for (k = 0; k < n; k++)
 for (i = 0; i < n; i++)
 for (j = 0; j < n; j++)
 dist[i][j] = function(dist[i][j],dist[i][k]+dist[k][j]);
}
//Use the Floyd Warshall algorithm to solve all shortest path problems.
// Hint:
//step 1: do For k=0 to k<n:
//step 2: do For i=0 to i<n:
//step 3: do For j=0 to j<n:
//step 4: if D[i][k]+D[k][j] < D[i][j]:
//step 5: set D[i][j] = D[i][k]+D[k][j]
//step 6: Exit.
//Hint for blank#2~#5 : Reconstruct step 4 and step 5 using the "function".
int main()
{
 int i,j;
 printf(ANSI_COLOR_RED  "ANIRUDHA_BEHERA//A20503687//ECE588-22FALL"  ANSI_COLOR_RESET "\n");
 printf("-------Floyd Warshall Algorithm-------\n");
 printf("========================================\n");
 printf("Enter the number of nodes:");
 scanf("%d",&n);
 printf("\n");
 printf("Enter distance matrix");
 for(i=0;i<n;i++)
 for(j=0;j<n;j++)
 {
 scanf("%d",&dist[i][j]);
 }
floydWarshell();
printf (" \n\n The distance matrix");
printf (" \n\n ------------------------------\n");
for (int i = 0; i < n; i++){
 for (int j = 0; j < n; j++)
{
printf("(%d,%d) : %d\n", i, j, dist[i][j]);
}
}
// Question::
// By using your distance table, please get the start node and 
//end node in scanf,and print the minimum weight between the nodes. 
int start, end; 
printf(" \n\n Enter the start node and end node: ");
scanf("%d %d", & start, & end); 
floydWarshell(); 
printf(" \n\n The minimum weight between the nodes: ");
printf("%d", dist[start][end]);
return 0;
}


