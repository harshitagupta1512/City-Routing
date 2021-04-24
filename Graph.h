#ifndef mygraph_h
#define mygraph_h

typedef struct stGraph* Graph;
typedef struct stNode* Node;
typedef int Vertex;

#define WHITE  1
#define GRAY   0
#define BLACK -1
#define INFTY  10000
#define UNKNOWN -1
#define NOTVERTEX -1

struct stGraph{
    int iN;
    Node* pvertex;
};

struct stNode{
    int Nodeid;
    Node pNext;
};

Graph CreateGraph(int iNumber_of_vertices);
void InsertEdge(Graph G, Vertex u, Vertex v);
void BFS(Graph G, Vertex s);
void DFS(Graph G, Vertex s);
