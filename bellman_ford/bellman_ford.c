//Bellman-Ford algorithm for find shortest path

#include<stdio.h>
#include<stdlib.h>
#define N 9					        //size of matrix
#define INF 9999			      //weight of disconnected nodes
#define ANSI_COLOR_RED  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int head[N][N]={			
 {0,1,INF,10,INF,INF,INF,INF,INF},
{1,0,2,INF,5,15,INF,INF,INF},
{INF,2,0,INF,INF,5, INF,INF,INF},
{10,INF, INF,0,35,INF,11,55,INF},
{INF,5,INF,35,0,75,INF,10,INF},
{INF,15,5,INF,75,0,INF,INF,5},
{INF,INF,INF,11,INF,INF,0,22,INF},
{INF,INF,INF,55,10,INF,22,0,INF},
{INF,INF,INF,INF,INF,5,INF,INF,0}
};


void bellman_ford();
void print();


int prev[N][N];                     
int current[N][N]; 

int main()
{
	bellman_ford();
	print();
	return 0;
}
void bellman_ford()
	//Hint
	// 1. define local variables as needed
  // 2. initialize previous values
  // 3. initialize the current values 
  // in nested for loops
  // 4. check if the distance to the node w is greater than (distance to v + distance b/w v and w)
  // 5. if the condition above is true, update the current distance of w to the new value
  // 6. set previous value to the current value for the next node
{	 
	for (int i = 0; i < N; i++) {
        current[i][N - 2] = INF;
    }
    current[0][N - 2] = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int u = 0; u < N; u++) {
            for (int v = 0; v < N; v++) {
                if (current[u][N - 2] != INF &&
                    current[u][N - 2] + head[u][v] < current[v][N - 2]) {
                    current[v][N - 2] = current[u][N - 2] + head[u][v];
                }
            }
        }
    }

}
void print()
{
	int i=0;
	printf(ANSI_COLOR_RED  "ANIRUDHA_BEHERA//A20503687//ECE588-22FALL"  ANSI_COLOR_RESET "\n");
	printf("Bellman Ford Algorithm!!(start = node1)\n");
	printf("========================================\n");
	printf("     destination             cost \n");
	for(i = 1; i < N; i++)                                          //print the distance to the destination
	{
        	printf("%11d%21d\n",i+1, current[i][N-2]);
	}
}