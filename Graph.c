#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Graph* CreateGraph(int iNumber_of_vertices)
{
    Graph* G = (Graph*)malloc(sizeof(struct Graph));
    assert(G != NULL);

    G->numVertices = iNumber_of_vertices;

    //AdjacencyList is the array of pointers to pointers to listnodes 
    G->adjacencyList = (ListNode**)malloc(sizeof(ListNode*)*iNumber_of_vertices);
    assert(G->adjacencyList != NULL);

    for(int i=0; i<iNumber_of_vertices; i++)
    {
        //G->pvertex[i] = (Node)malloc(sizeof(struct stNode));
       // assert(G->pvertex[i] != NULL);

     //   G->pvertex[i]->Nodeid = i;
        G->adjacencyList[i]= NULL;
    }
    return G;
}

void InsertEdge(Graph G, Vertex u, Vertex v)
{
    ListNode temp;
    temp = G->adjacencyList[u];

    int found = 0;
    int w;

    while(temp != NULL)
    {
        w = temp->dest;

        if(v == w)
        {
            found = 1;
            break;
        }
        temp = temp->pNext;
    }

    if(!found){
        ListNode* New = (ListNode*)malloc(sizeof(struct ListNode));
        assert(New != NULL);
        New->dest = v;
        New->next = temp;
        temp = New;
    }
    
    return;
}

/*
void DFS(Graph G, Vertex s){
    Node temp = G->pvertex[s];
    Vertex v;

    char* pVisited = (char*)malloc(sizeof(char)*G->iN);
    assert(pVisited != NULL);

    for(int i=0;i<G->iN;i++){
        pVisited[i] = 0;
    }

    while (temp->pNext != NULL)
    {
        v = temp->pNext->Nodeid;
        if(pVisited[v] == 0){
            DFS_Visit(G,v,pVisited);
        }
        temp = temp->pNext;
    }
    pVisited[s] = 1;
    return;
}

void DFS_Visit(Graph G,Vertex v,char* pVisited){
    Node temp = G->pvertex[v];
    Vertex w;

    while(temp->pNext != NULL){
        w = temp->pNext->Nodeid;
        if(pVisited[w] == 0)
            DFS_Visit(G,w,pVisited);
        temp = temp->pNext;
    }
    pVisited[v] = 1;
    return;
}
*/
