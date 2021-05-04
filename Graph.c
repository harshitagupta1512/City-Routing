#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#define INF INT_MAX

typedef struct queueNode
{
    vertex v;
    struct queueNode *next;
} queueNode;

typedef struct queue
{
    queueNode *front;
    queueNode *rear;
} queue;

queue *initqueue()
{
    queue *q;
    q = (queue *)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

queue *enqueue(queue *q, vertex x)
{
    queueNode *temp = (queueNode *)malloc(sizeof(struct queueNode));

    temp->v = x;
    temp->next = NULL;

    if (q->front == NULL)
    {
        q->front = temp;
        q->rear = temp;
    }

    else
    {
        q->rear->next = temp;
        q->rear = temp;
    }

    return q;
}

int dequeue(queue *q)
{
    int x = q->front->v.vertexId;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    return x;
}

//-------------------------------------------------//
void getFastestPath(struct Graph *G, vertex src, vertex dest)
{
    queue *q = initqueue();
    enqueue(q, src);

    int cost[G->numVertices];

    for (int i = 0; i < G->numVertices; i++)
    {
        cost[i] = INF;
    }

    cost[src.vertexId] = 0;

    int visited[G->numVertices];
    for (int i = 0; i < G->numVertices; i++)
    {
        visited[i] = 0;
    }

    visited[src.vertexId] = 1;

    /*  int path[G->numVertices];
   for (int i = 0; i < G->numVertices; i++)
   {
        path[i] = 0;
    }
    path[src.vertexId] = -1;
*/
    while (q->front != NULL)
    {
        int x = dequeue(q);
        visited[x] = 1;

        struct ListNode *temp = G->adjacencyList[x];

        int i = 0;

        while (temp != NULL)
        {
            if ((x != temp->dest.vertexId) && (cost[temp->dest.vertexId] >= (cost[x] + temp->SD.weight)))
            {
                cost[temp->dest.vertexId] = cost[x] + temp->SD.weight;
                G->path[temp->SD.weight]->next = G->path[x];
            }
            if (visited[temp->SD.weight] == 0)
            {
                visited[temp->dest.vertexId] = 1;
                enqueue(q, temp->dest);
            }

            temp = temp->next;
        }
    }
    struct ListNode *tempi = G->path[dest.vertexId];
    printf("\nthe shortest path between ' ' and ' ' in map is :");
    while (tempi != NULL)
    {
        printf("%d", tempi->dest.vertexId);
        tempi = tempi->next;
        if (tempi != NULL)
            printf("->");
    }
    printf("\n\n");
}

struct Graph *CreateGraph(int iNumber_of_vertices)
{
    struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph));
    assert(G != NULL);

    G->numVertices = iNumber_of_vertices;

    //AdjacencyList is the array of pointers to pointers to listnodes

    G->adjacencyList = (ListNode **)malloc(sizeof(ListNode *) * iNumber_of_vertices);
    G->path = (ListNode **)malloc(sizeof(ListNode *) * iNumber_of_vertices);
    assert(G->adjacencyList != NULL);

    for (int i = 0; i < iNumber_of_vertices; i++)
    {
        //G->pvertex[i] = (Node)malloc(sizeof(struct stNode));
        // assert(G->pvertex[i] != NULL);

        //   G->pvertex[i]->Nodeid = i;
        G->adjacencyList[i] = NULL;
        G->path[i] = (struct ListNode *)malloc(sizeof(struct ListNode *));
        G->path[i]->dest.vertexId = i;
        G->path[i]->next = NULL;
    }

    return G;
}

void AddStreet(struct Graph *G, vertex u, vertex v, struct StreetData SD)
{
    ListNode *temp;
    temp = G->adjacencyList[u.vertexId];

    int found = 0;
    vertex w;

    while (temp != NULL)
    {
        w = temp->dest;

        if (v.vertexId == w.vertexId)
        {
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found)
    {
        ListNode *New = (ListNode *)malloc(sizeof(struct ListNode));
        assert(New != NULL);
        New->dest = v;
        New->SD = SD;
        //Add at beginning
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
