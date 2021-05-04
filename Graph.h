#ifndef _ROUTING_
#define _ROUTING_

//typedef struct stGraph* Graph;
//typedef struct stNode* Node;
//typedef int Vertex;

typedef struct vertex
{
    char vertexName[50];
    int vertexId;

} vertex;

struct Graph
{
    int numVertices; //Number of vertices
    struct ListNode **adjacencyList;
    struct ListNode **path;
};
/*
#define WHITE  1
#define GRAY   0
#define BLACK -1
#define INFTY  10000
#define UNKNOWN -1
#define NOTVERTEX -1
*/
/*
struct stGraph{
    int iN;
    Node* pvertex;
};
struct stNode{
    int Nodeid;
    Node pNext;
};
*/

struct StreetData
{
    //int dest;
    int length;
    int traffic;
    int numLanes;      //range = 1-4
    int num_cars;      //Average Number of cars on the street per hour ---- range = 10 - 300
    int num_accidents; //Average Number of accidents per week -------- range = 1 - 10
    int speed_limit;   //Maximum Speed Limit --- range= 10-100 km/h
    int weight;        //Final weightage/congestion index of the street
    int safety_value;
};

typedef struct ListNode
{
    vertex dest;
    struct ListNode *next;
    struct StreetData SD;
} ListNode;

typedef struct ListNode *head;

struct Graph *CreateGraph(int n); //n is no of vertices;
//struct StreetData* CreateStreetData(int n);
void AddStreet(struct Graph *G, vertex src, vertex dest, struct StreetData SD);
void getFastestPath(struct Graph *G, vertex src, vertex dest);
/*
Graph CreateGraph(int iNumber_of_vertices);
void InsertEdge(Graph G, Vertex u, Vertex v);
void BFS(Graph G, Vertex s);
void DFS(Graph G, Vertex s);
*/

#endif
