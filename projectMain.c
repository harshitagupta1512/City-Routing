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
    
    scanf("%d %d", &numPlaces, &numStreets);
    struct Graph *City = CreateGraph(numPlaces);

    int count = 0;

    char vertexArray[numPlaces][50];

   

    int itr = 0;
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
            placesAndIDs[itr] = src;
            itr++;
        }

        else
        {
            for (int i = 0; i < numPlaces; i++)
            {
                if (strcmp(placesAndIDs[i].vertexName, src.vertexName) == 0)
                    src.vertexId = placesAndIDs[i].vertexId;
            }
        }

        if (findInVertexArray(vertexArray, dest.vertexName, count) == 0)
        {
            strcpy(vertexArray[count], dest.vertexName);
            dest.vertexId = count;
            count++;
            placesAndIDs[itr] = dest;
            itr++;
        }
        else
        {
            for (int i = 0; i < numPlaces; i++)
            {
                if (strcmp(placesAndIDs[i].vertexName, dest.vertexName) == 0)
                    dest.vertexId = placesAndIDs[i].vertexId;
            }
        }

        SD.traffic = 1 / (SD.numLanes * 10 * 0.6) + 1 / SD.speed_limit * 0.4 + SD.num_cars * 1;
        SD.safety_value = 1 / ((SD.num_accidents * 0.8) + (0.2 * SD.speed_limit / 10)); //Safe Routing
        SD.weight = SD.traffic * 0.6 + SD.length * 0.4;                                 //Congestion

        printf("\nCount = %d SrcID = %d DestID = %d\n", count, src.vertexId, dest.vertexId);
        AddStreet(City, src, dest, SD);
    }

    //-------------City graph is made---------------------//

    //PRINT VERTEX IDS AND NAMES

    for(int i=0;i<numPlaces;i++)
    {
        printf("%d %s\n",placesAndIDs[i].vertexId,placesAndIDs[i].vertexName);
    }

   ListNode *temp;

    for (int i = 0; i < numPlaces; i++)
    {
        printf("%d---> ", i);
        temp = City->adjacencyList[i];
        while (temp != NULL)
        {
            printf(" %d ", temp->dest.vertexId);
            temp = temp->next;
        }
        printf("\n");
    }

    vertex finalSource, finalDestination;
    scanf("%s %s", finalSource.vertexName, finalDestination.vertexName);

    for (int i = 0; i < numPlaces; i++)
    {
        if (strcmp(placesAndIDs[i].vertexName, finalSource.vertexName) == 0)
            finalSource.vertexId = placesAndIDs[i].vertexId;

        else if (strcmp(placesAndIDs[i].vertexName, finalDestination.vertexName) == 0)
            finalDestination.vertexId = placesAndIDs[i].vertexId;
    }

    printf("Final source - %d Final Destination - %d\n",finalSource.vertexId ,finalDestination.vertexId);
    getFastestPath(City, finalSource, finalDestination);
    printf("\nDo you want to update ur currect location(Y/N)? : ");

    char q;
    scanf("%*c%c", &q);
    if (q == 'Y')
    {
        printf("Enter the name of your current location : ");
        vertex node;
        //char nodename[50];
        scanf("%s", node.vertexName);
        int i = 0;
        while (i <= numPlaces)
        {
            if (strcmp(node.vertexName, placesAndIDs[i].vertexName) == 0)
            {
                node.vertexId = placesAndIDs[i].vertexId;
                //strcpy(node.vertexName, placesAndIDs[i].vertexName);
                break;
            }
            i++;
        }
        printf("Enter number of streets for which you want to change data for :-");
        int changeStreetsNum = 0;
        scanf("%d", &changeStreetsNum);

        printf("Enter the changed streets' data (source destination num_cars)\n");

        for (int i = 0; i < changeStreetsNum; i++)
        {
            vertex srcChange, destChange;
            int carsNum;
            scanf("%s %s %d", srcChange.vertexName, destChange.vertexName, &carsNum);
            int i = 0;
            while (i <= numPlaces)
            {
                if (strcmp(srcChange.vertexName, placesAndIDs[i].vertexName) == 0)
                {
                    srcChange.vertexId = placesAndIDs[i].vertexId;
                    break;
                }

                i++;
            }

            int j = 0;
            while (j <= numPlaces)
            {
                if (strcmp(destChange.vertexName, placesAndIDs[j].vertexName) == 0)
                {
                    destChange.vertexId = placesAndIDs[j].vertexId;
                    break;
                }
                j++;
            }

            printf("Changing data for %s(%d) -> %s(%d)",srcChange.vertexName,srcChange.vertexId,destChange.vertexName,destChange.vertexId);
            UpdateStreet(City, srcChange, destChange, carsNum);
        }


        getFastestPath(City, node, finalDestination);

  
}
