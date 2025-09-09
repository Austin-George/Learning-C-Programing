#include <stdio.h>

#define MAX_WEIGHT 1000

int main()
{
    int countOfVertices;
    scanf("%d", &countOfVertices);

    int countOfEdges;
    scanf("%d", &countOfEdges);

    int adjecencyMatrix[countOfVertices][countOfVertices];
    int visitedVertices[countOfVertices];
    int distances[countOfVertices];
    int parents[countOfVertices];

    for (int i = 0; i < countOfVertices; i++)
    {
        for (int j = 0; j < countOfVertices; j++)
        {
            adjecencyMatrix[i][j] = MAX_WEIGHT;
        }
        visitedVertices[i] = 0;
        distances[i] = MAX_WEIGHT;
        parents[i] = -1;
    }

    for (int i = 0; i < countOfEdges; i++)
    {
        int src, des, wei;
        scanf("%d", &src);
        scanf("%d", &des);
        scanf("%d", &wei);
        adjecencyMatrix[src][des] = wei;
        adjecencyMatrix[des][src] = wei;
    }

    int src;
    scanf("%d", &src);

    distances[src] = 0;

    for (int i = 0; i < countOfVertices; i++)
    {
        int minimumWeightEdge = MAX_WEIGHT;
        int minimumWeightNode = -1;
        for (int j = 0; j < countOfVertices; j++)
        {
            if (!visitedVertices[j] && distances[j] < minimumWeightEdge)
            {
                minimumWeightEdge = distances[j];
                minimumWeightNode = j;
            }
            
        }

        if (minimumWeightNode == -1)
        {
            break;
        }
        
        visitedVertices[minimumWeightNode] = 1;
        for (int j = 0; j < countOfVertices; j++)
        {
            if (!visitedVertices[j] && distances[j] > distances[minimumWeightNode] + adjecencyMatrix[minimumWeightNode][j])
            {
                distances[j] = distances[minimumWeightNode] + adjecencyMatrix[minimumWeightNode][j];
                parents[j] = minimumWeightNode;
            }
            
        }
        
    }

    //minimum distance from src
    for (int i = 0; i < countOfVertices; i++)
    {
        printf("%d to %d : %d\n", src, i, distances[i]);
    }

    //minimum spanning tree.
    for (int i = 0; i < countOfVertices; i++)
    {
        printf("%d parent: %d\n", i, parents[i]);
    }
    
    return 0;
}