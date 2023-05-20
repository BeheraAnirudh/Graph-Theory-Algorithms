#include<stdio.h>
#include<stdlib.h>

#define ANSI_COLOR_RED  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int i, j, k, n, dist[10][10];
void floydWarshell() {
    for (k = 0; k < n; k++) { // Add all vertices one by one to the set of 
                              // intermediate vertices.
        for (i = 0; i < n; i++) { // Select all vertices as sources.
            for (j = 0; j < n; j++) { // Select all vertices as the destination of
                                      // the source selected above.
                if (dist[i][k] + dist[k][j] < dist[i][j])  // When vertex k is on the shortest path
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main()

{

    int i, j;
    printf(ANSI_COLOR_RED  "ANIRUDHA_BEHERA//A20503687//ECE588-22FALL"  ANSI_COLOR_RESET "\n");
	printf("-------Floyd Warshall Algorithm-------\n");
	printf("========================================\n");
    printf("Enter the number of nodes:");

    scanf("%d", & n);

    printf("\n");

    printf("Enter distance matrix");

    for (i = 0; i < n; i++)

        for (j = 0; j < n; j++)

    {

        scanf("%d", & dist[i][j]);

    }

    floydWarshell();

    printf(" \n\n The distance matrix");

    printf(" \n\n ------------------------------\n");

    for (int i = 0; i < n; i++)

    {

        for (int j = 0; j < n; j++)

            printf("%d\t", dist[i][j]);

        printf("\n");

    }

    int start, end; // The starting point and the end point of the shortest path

    printf(" \n\n Enter the start node and end node: ");

    scanf("%d %d", & start, & end); // get input from the user

    floydWarshell(); // call the function
    printf(" \n\n The minimum weight between the nodes: ");
    // print the minimum weight between the nodes
    printf("%d", dist[start][end]);

    return 0;

}