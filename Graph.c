#include "MyGraph.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Graph CreateGraph(int iNumber_of_vertices){
    Graph G = (Graph)malloc(sizeof(struct stGraph));
    assert(G != NULL);

    G->iN = iNumber_of_vertices;

    G->pvertex = (Node*)malloc(sizeof(Node)*iNumber_of_vertices);
    assert(G->pvertex != NULL);


    for(int i=0;i<iNumber_of_vertices;i++){
        G->pvertex[i] = (Node)malloc(sizeof(struct stNode));
        assert(G->pvertex[i] != NULL);

        G->pvertex[i]->Nodeid = i;
        G->pvertex[i]->pNext = NULL;
    }
    return G;
}

void InsertEdge(Graph G, Vertex u, Vertex v){
    Node temp;
    temp = G->pvertex[u];
    int found = 0;
    Vertex w;

    while(temp != NULL){
        w = temp->Nodeid;
        if(v == w){
            found = 1;
            break;
        }
        temp = temp->pNext;
    }

    if(!found){
        Node New = (Node)malloc(sizeof(struct stNode));
        assert(New != NULL);

        New->Nodeid = v;
        New->pNext = temp->pNext;
        temp->pNext = New;
    }
    return;
}

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
