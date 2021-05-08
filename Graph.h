#ifndef _ROUTING_
#define _ROUTING_

#define WHITE  1
#define GRAY   0
#define BLACK -1
#define INFTY  10000
#define UNKNOWN -1
#define NOTVERTEX -1

typedef struct vertex
{
    char vertexName[50];
    int vertexId;

}vertex;

int numPlaces, numStreets;
vertex placesAndIDs[1000000];

typedef struct Graph{
    int numVertices; //Number of vertices
    struct ListNode ** adjacencyList;
    struct ListNode **path;

}Graph;

struct StreetData{
    //int dest;
    float length;
    float traffic;
    int numLanes;//range = 1-4
    int num_cars;//Average Number of cars on the street per hour ---- range = 10 - 300
    int num_accidents;//Average Number of accidents per week -------- range = 1 - 10
    int speed_limit;//Maximum Speed Limit --- range= 10-100 km/h
    float weight; //Final weightage/congestion index of the street
    float safety_value;
};

typedef struct ListNode{
    vertex dest;
    struct ListNode* next;
    struct StreetData SD;
}ListNode;

typedef struct ListNode* head;
struct Graph* CreateGraph(int n); //n is no of vertices;
void AddStreet(Graph* G,vertex src,vertex dest, struct StreetData SD);
void getFastestPath(struct Graph* G ,vertex src,vertex dest,int flag);
void UpdateStreet(struct Graph *G, vertex u, vertex v, int cars);


#endif
