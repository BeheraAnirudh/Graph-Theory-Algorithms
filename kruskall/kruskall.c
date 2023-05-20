//Kruskal's algorithm for Minimum Spanning Tree


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EDGE 100
#define MAX_NODE 100
#define TRUE 1
#define FALSE 0
#define ANSI_COLOR_RED  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct {
	int v;
	int w;
	int cost;
} edge;

void insert_min_heap(edge item, int *n);

edge delete_min_heap(int *n);

void union2(int i, int j);

int find2(int i);

int kruskal(int node_num, int *edge_num);

void file_input(void);

void print(int node_num, int edge_num); //print result

int equal(edge data, int edge_num); //check redundant edge

edge E[MAX_EDGE]; //contains minimum heap

edge T[MAX_EDGE]; // resulting edges

int parent[MAX_NODE];

void main(void){
	int i=1;
	while(i){
		printf(ANSI_COLOR_RED  "ANIRUDHA_BEHERA//A20503687//ECE588-22FALL"  ANSI_COLOR_RESET "\n");
	    printf("-----------Kruskall Algorithm-----------\n");
	    printf("========================================\n");
		printf("\n1. file input\n2. quit \n==>");
		scanf("%d", &i);
		switch(i){
			case 1 :
				file_input();
				break;
			default :
				return;
		}
	}
}

void file_input(void){
	FILE *fp;
	int node_num, edge_num=0, i, count;
	char tem[20], delim[] = "' '" , *token;
	edge temp;
	if((fp = fopen("input-kruskal.txt","r"))==NULL) {
		fprintf(stderr, "file error!!\n");
		exit(1);
	}
	for(i=0; i<MAX_NODE; i++) //parent initialization
		parent[i] = -1;

	fgets(tem, 10, fp);
	node_num = atoi(tem); //node number
	fgets(tem, 10, fp);
	count = atoi(tem); //edge number

	if(count > ((node_num * (node_num-1))/2)){
		fprintf(stderr,"edge number can not exceed (node * nod - 1)/2.\n");
		exit(1);
	}

	for(i=0; i<count && !feof(fp); i++) // while less than the number of edges or until the end of file
	{
		fgets(tem, 10, fp);
		token = strtok(tem, delim);
		while(token != NULL) //store each node costs
		{
			temp.v = atoi(token);
			token = strtok(NULL, delim);
			temp.w = atoi(token);
			token = strtok(NULL, delim);
			temp.cost = atoi(token);
			token = strtok(NULL, delim);

			if(equal(temp, edge_num)){
				fprintf(stderr,"There is already same edges.\n");
				exit(1);
			}

			insert_min_heap(temp, &edge_num); // insert each node to min heap
		}
	}

	if((count != i) || !feof(fp)){
		fprintf(stderr,"edge number is not same as real number.\n");
		exit(1);
	}

	print(node_num, edge_num);
	fclose(fp);
}

int equal(edge data, int edge_num) //check edge duplication
{
	int i;
	for(i=1; i<=edge_num; i++)
		if(((data.v == E[i].v) || (data.v == E[i].w)) && ((data.w == E[i].v) || (data.w == E[i].w)) || (data.v == data.w))
			return TRUE;

	return FALSE;
}

void print(int node_num, int edge_num){
	int i,j;
	printf("total nodes: %d , total edges: %d\n",node_num, edge_num);
	printf("\n input data : \n"); //print input data

	for(i=1; i<=edge_num; i++)
		printf("[%d] edge : (%d , %d) ==> cost : %d\n",i,E[i].v, E[i].w, E[i].cost);

	j = kruskal(node_num, &edge_num);
	if(j == -1)
		return;

	printf("\n Minimum Spanning Tree :\n");

	for(i=0 ; i<j ; i++)
		printf("[%d] edge : (%d %d) ==> cost : %d\n",i+1,T[i].v, T[i].w, T[i].cost);
}


void insert_min_heap(edge item, int *n){
	int i;
	if(*n == MAX_EDGE -1){
		fprintf(stderr,"The heap is full.\n");
		exit(1);
	}
	i = ++(*n);
	while((i != 1) && (item.cost < E[i/2].cost)){
		E[i] = E[i/2];
		i /= 2;
	}
	E[i] = item;
}

edge delete_min_heap(int *n) //return the minimum costs
{
	int parent, child;
	edge item, temp;
	if(!(*n)){
		fprintf(stderr,"The heap is empty\n");
		exit(1);
	}
	item = E[1];
	temp = E[(*n)--];
	parent = 1;
	child = 2;

	while(child <= *n){
		if((child < *n) && (E[child].cost) > E[child+1].cost)
			child++;
		if(temp.cost <= E[child].cost)
			break;
		E[parent] = E[child];
		parent = child;
		child *= 2;
	}
	E[parent] = temp;
	return item;
}

void union2(int i, int j){
	int temp = parent[i] + parent[j];
	if(parent[i] > parent[j]){
		//parent[i] = j;
		parent[j] = i;
	}else{
		parent[j] = i;
		parent[i] = temp;
	}
}

int find2(int i){
	int root, trail, lead;
	for(root = i; parent[root]>=0; root = parent[root]);
	for(trail = i; trail != root; trail = lead){
		lead = parent[trail];
		parent[trail] = root;
	}
    return root;
}

int kruskal(int node_num, int *edge_num){
	int idx = 0;
	while(idx < node_num-1 && edge_num != 0){
		edge e = delete_min_heap(edge_num);
		if(find2(e.v) != find2(e.w)){
            union2(e.v, e.w);
			T[idx] = e;
			idx++;
		}
	}
	if(idx < node_num-1){
		printf("\n Error! Minimum Spanning Tree can't be formed\n");
		return -1;
	}
	return idx;
}