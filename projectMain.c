#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int findInVertexArray(char array[][50], char key[50], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(array[i], key) == 0)
            return 1;
    }
    return 0;
}

int main(void)
{
    int numPlaces, numStreets;
    scanf("%d %d", &numPlaces, &numStreets);
    struct Graph *City = CreateGraph(numPlaces);

    int count = 0;

    char vertexArray[numPlaces][50];

    for (int i = 0; i < numStreets; i++)
    {
        vertex src, dest;
        struct StreetData SD;

        scanf("%s %s %d %d %d %d %d", src.vertexName, dest.vertexName, &SD.length, &SD.numLanes, &SD.num_cars, &SD.num_accidents, &SD.speed_limit);

        if (findInVertexArray(vertexArray, src.vertexName, count) == 0)
        {
            strcpy(vertexArray[count], src.vertexName);
            src.vertexId = count;
            count++;
        }

        if (findInVertexArray(vertexArray, dest.vertexName, count) == 0)
        {
            strcpy(vertexArray[count], dest.vertexName);
            dest.vertexId = count;
            count++;
        }

        SD.traffic = 1 / (SD.numLanes * 10 * 0.6) + 1 / SD.speed_limit * 0.4 + SD.num_cars * 1;
        SD.safety_value = 1 / ((SD.num_accidents * 0.8) + (0.2 * SD.speed_limit / 10)); //Safe Routing
        SD.weight = SD.traffic * 0.6 + SD.length * 0.4;                                 //Congestion

        AddStreet(City, src, dest, SD);
    }

    //-------------City graph is made---------------------//

    vertex finalSource, finalDestination;
    scanf("%s %s", finalSource.vertexName, finalDestination.vertexName);
    getFastestPath(City, finalSource, finalDestination);
}
