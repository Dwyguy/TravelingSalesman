#include "GraphAlgs.h"

std::vector<NodeID> bestTour;
int* currentTour;
double bestLen;
double currentLen;
Graph* graph;
int size;

void setup(Graph* G)
{
	bestTour.resize(G->size());
	bestLen = 0.0;
	currentLen = 0.0;
	graph = G;
	size = G->size();

	currentTour = new int[G->size()];

	for(int x = 0; x < G->size(); x++)
	{
		currentTour[x] = x;
	}
	
	for(int y = 0; y < size - 1; y++)
		bestLen += graph->weight(currentTour[y], currentTour[y + 1]);

	bestLen += graph->weight(currentTour[size - 1], currentTour[0]);

}


std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G)
{
	setup(G);
	tour(currentTour, G->size(), 1);

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
		double sum = graph->weight(currentTour[startingPlace], currentTour[startingPlace + 1]);


		for(int x = startingPlace; x < numnodes; x++)
		{
			swap(startingPlace, x);
			tourCycle(sum, startingPlace);
			tour(arr, numnodes, startingPlace + 1);
			swap(x, startingPlace);
		}
	}
}

void tourCycle(double sum, int cur)
{
	//sum = 0;

	for(int x = cur; x < size - 1; x++)
		sum += graph->weight(currentTour[x], currentTour[x + 1]);

	sum += graph->weight(currentTour[size - 1], 0);

	if(sum < bestLen)
	{
		for(int y = 0; y < size; y++)
			bestTour[y] = currentTour[y];

		bestLen = sum;
	}

}