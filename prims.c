#include <stdio.h>

//task 1, create an adjacency list, nad btw, hi

#define V 6        //number of elementss

struct node* adjlist[V];

// this is the change kjbwen;on                lhbwerlioubvwe'pkv

void InitilizeArray(void){

	for (int i = 0; i < V; ++i)
	{
		adjlist[i]-> vertex = i;
		adjlist[i]-> weight = 0;
	}
};

struct node
{ 	
	int vertex;
	struct node* next = NULL;
	int weight;
};

struct node* returnNode(int parent_vertex){

	struct node * temp = adjlist[parent_vertex];
	for (; temp!=NULL ;)
	{
			if (temp->next == NULL)
		{
			return temp;

		}else{
			temp = temp->next;
		}

	}
};

void addNode(int parent_vertex, int vertex, int weight){
	struct node * parentNode = returnNode(parent_vertex);
	struct node * Childnode;
	Childnode = (struct node*)malloc(sizeof(struct node));      //A = 0; B = 1; C = 2; D = 3; E = 4; F = 5;
	Childnode->vertex = vertex;
	Childnode->weight = weight;
	Childnode->next = NULL;
	parentNode->next = Childnode;
};


int main()
{
	InitilizeArray();
	addNode(0,4,4); // A E 4
	addNode(0,1,8); // A B 8
	addNode(0,3,6); // A D 6
	addNode(1,4,7); // B E 7
	addNode(1,0,8); // A B 8
	addNode(1,2,4); // B C 4
	addNode(0,1,8);
	addNode(0,1,8);
	return 0;
}