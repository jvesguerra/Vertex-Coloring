/*
	Exercise: Vertex Coloring
	1. Complete the basic greedy coloring program below.
	2. Analyze the running time of the program.
	3. Improve the quality of your solution by determining a good starting vertex.
*/

#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>

typedef struct node{
	int x;
	struct node *next;
}graph;

graph **createAdjList(int *, int *);
void viewList(graph **, int);
int * graphColoring(graph **, int);
int getAvailableColor(graph **, int *, int, int);
void viewColor(int *, int);
void deleteGraph(graph **, int);

FILE *fp;
int numIn;
int num2;

int main(){
	graph **g;
	int v, e;
	int *color;	//Array of the color of each vertex. For example color[0] = 0 means vertex 0 has color 0

	g = createAdjList(&v, &e);
	// color = graphColoring(g, v);
	// viewList(g, v);
	// viewColor(color, v);
	
	// free(color);
	// deleteGraph(g, v);

}

graph **createAdjList(int *v, int *e){
	/*insert code here for creating an adjacency list*/

	int vertices[5];
	struct node* A[5];
	int counter = 0;

	fp = fopen("Exer9.in", "rw");

	if(fp != NULL){
		fscanf(fp,"%d",&numIn);
		*v = numIn;
		fscanf(fp,"%d",&numIn);
		*e = numIn;

		printf("Vertices: %d \n", *v);
		printf("Edges: %d \n", *e);

		while((fscanf(fp,"%d",&numIn)) == 1){
			fscanf(fp,"%d",&num2);

			// first node
			struct node* newNode = (struct node*)malloc(sizeof(struct node));
			newNode->x = num2;
			newNode->next = NULL;

			// second node
			struct node* newNode2 = (struct node*)malloc(sizeof(struct node));
			newNode2->x = numIn;
			newNode2->next = NULL;

			if(vertices[numIn] != numIn){
				A[numIn] = newNode; // add head
			}else{
				struct node *temp = A[numIn];
				while(temp->next != NULL){
					temp = temp->next;
				}
				temp->next = newNode;
			}


			// update vertices array
			vertices[numIn] = numIn;

			
		}
	}
	fclose(fp);

	graph *p;
	for(int i = 0; i < *v; i++){
		p = A[i];
		printf("%d: ", i);
		//traverse the list connected to vertex i
		while(p != NULL){
			printf("%3d", p->x);
			p = p->next;
		}
		printf("\n");
	}
}

void viewList(graph **g, int v){
	int i;
	graph *p;
	
	for(i = 0; i < v; i++){
		p = g[i];
		printf("%d: ", i);
		//traverse the list connected to vertex i
		while(p != NULL){
			printf("%3d", p->x);
			p = p->next;
		}
		printf("\n");
	}
}

int * graphColoring(graph **g, int v){
	int *color, availCol, i;
	
	//colors are represented as integers starting from 0
	color = (int *)malloc(sizeof(int)*v);
	for(i = 0; i < v; i++)
		color[i] = -1;
	
	color[0] = 0;	//assign first vertex with the first color
	for(i = 1; i < v; i++){
		availCol = getAvailableColor(g, color, v, i);
		color[i] = availCol;
	}
	return color;
}

int getAvailableColor(graph **g, int *color, int v, int curr){
	graph *p;
	int *available, i, availCol;
	
	//keeps track of the colors used on any previously colored vertices adjacent to it
	available = (int *)malloc(sizeof(int)*(v));
	for(i = 0; i < v; i++)
		available[i] = 1;		//initalize all the color as available (1).
	
	/*Insert code here for marking the colors that have been used 
	on any previously colored vertices adjacent to it. Change the color availability from
	1 to 0 if the color is already used.*/
	

	
	
	for(i = 0; i < v; i++){				//get the smallest color that is available (1-available; 0-not availables)
		if(available[i] == 1){
			availCol = i;
			break;
		}
	}
	
	free(available);
	return availCol;
}

void viewColor(int *color, int v){
	int i;
	
	for(i = 0; i < v; i++){
		printf("Vertex %d -> Color %d\n", i, color[i]);
	}
}

void deleteGraph(graph **g, int v){
	int i;
	graph *p;
	for(i = 0; i < v; i++){
		while(g[i] != NULL){
			p = g[i];
			g[i] = g[i]->next;
			free(p);
		}
	}
	free(g);
}