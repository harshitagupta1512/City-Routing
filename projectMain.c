#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void)
{
    int numPlaces,numStreets;
    scanf("%d %d",&numPlaces,&numStreets);
    Graph* City=CreateGraph(numPlaces);

    for(int i=0;i<numStreets;i++)
    {
        int src,dest;
        struct StreetData SD;
        scanf("%d %d %d %d %d %d %d",src,dest,SD.length,SD.numLanes,SD.num_cars,SD.num_accidents,SD.speed_limit);
        AddStreet(src,dest,SD);
    }

    //-------------City graph is made---------------------//

    int finalSource, finalDestination;
    scanf("%d %d",&finalSource,&finalDestination);
    getFastestPath(City,finalSource,finalDestination);
}
