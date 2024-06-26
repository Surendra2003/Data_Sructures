#include <stdio.h>
#include <stdlib.h>
// A structure to represent an adjacency list node
struct AdjListNode 
{
	 int dest;  struct AdjListNode* next; 
};
// A structure to represent an adjacency list
struct AdjList
 { 
	struct AdjListNode* head;
	   };
 //*A structure to represent a graph. A graph  is an array of adjacency lists.  Size of array will be V (number of vertices in graph) */
struct Graph 
{   
	int V; 
	 struct AdjList* array;
	  };
// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest)
{ 
	struct AdjListNode* newNode = (struct AdjListNode*)malloc( sizeof(struct AdjListNode));
	newNode->dest = dest; newNode->next = NULL; return newNode;
}
// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{  
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;
  // Create an array of adjacency lists. Size of array will be V
	graph->array = (struct AdjList*)malloc( V * sizeof(struct AdjList));
// Initialize each adjacency list as empty by making head as NULL
	int i;
	for (i = 0; i < V; ++i)
		graph->array[i].head = NULL;
 return graph;  }
// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest)
{	struct AdjListNode* check = NULL;
	struct AdjListNode* newNode = newAdjListNode(dest);
if (graph->array[src].head == NULL) { newNode->next = graph->array[src].head; 
                  graph->array[src].head = newNode; }
	else {  check = graph->array[src].head;
		while (check->next != NULL) {
			check = check->next;  }
		graph->array[src].head = newNode;
		check->next = newNode; }
	newNode = newAdjListNode(src);
	if (graph->array[dest].head == NULL) {
		newNode->next = graph->array[dest].head;
		graph->array[dest].head = newNode; }
	else { check = graph->array[dest].head;
		while (check->next != NULL) { check = check->next; }
		check->next = newNode;  }
    // newNode = newAdjListNode(src);
	// newNode->next = graph->array[dest].head;
	// graph->array[dest].head = newNode;
}
void printGraph(struct Graph* graph)
{  int v;
	for (v = 0; v < graph->V; ++v) {
		struct AdjListNode* pCrawl = graph->array[v].head;
		printf("\n Adjacency list of vertex %d\n head ", v);
		while (pCrawl) {
			printf("-> %d", pCrawl->dest); pCrawl = pCrawl->next; }
		printf("\n"); }  }
int main()
{  int V = 5;
	struct Graph* graph = createGraph(V);
	addEdge(graph, 0, 1); addEdge(graph, 0, 4);  addEdge(graph, 1, 2);
    int choice,x,y;
    printf("\nEnter your Choice\n");
    printf("\n1. Add an Edge\n");
    printf("\nPrint the graph.\n");
    scanf("%d",&choice);
    switch(choice){
        case 1: printf("Enter 2 vertices (0<=v<=4):");
        scanf("%d %d",&x,&y);
        addEdge(graph, x, y);  break;
        case 2: printGraph(graph); break;
        default: printf("Enter choice as 1 or 2.");
    }
return 0;
 }
