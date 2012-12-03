#include "GraphAlgs.h"

std::vector<NodeID> bestTour;
int* currentTour;
double bestLen;
double currentLen;
Graph* graph;

void setup(Graph* G)
{
	bestTour.resize(G->size());
	bestLen = 0.0;
	currentLen = 0.0;
	graph = G;

	currentTour = new int[G->size()];

	for(int x = 0; x < G->size(); x++)
	{
		currentTour[x] = x;
	}
	
}


std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G)
{
	setup(G);
	tour(currentTour, G->size(), 0);

	std::pair<std::vector<NodeID>, EdgeWeight> bestPair = std::make_pair(bestTour, bestLen);
	return bestPair;
}

void swap(int a, int b)
{
	NodeID temp = currentTour[a];
	currentTour[a] = currentTour[b];
	currentTour[b] = temp;
}

void tour(int* arr, int numnodes, int startingPlace)
{
	if(numnodes - startingPlace == 1)
	{
		for(int y = 0; y < startingPlace; y++)
			currentLen += graph->weight(arr[y], arr[y + 1]);

		currentLen += graph->weight(arr[numnodes - 1], 0);

		if(currentLen <= bestLen)
		{
			bestLen = currentLen;
			for(int z = 0; z < numnodes; z++)
				bestTour[z] = currentTour[z];
		}
	}
	else
	{
		for(int x = startingPlace; x < numnodes; x++)
		{
			swap(startingPlace, x);
			tour(arr, numnodes, startingPlace + 1);
			swap(x, startingPlace);
		}
	}
}