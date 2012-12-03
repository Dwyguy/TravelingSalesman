/**
* @file GraphAlgs.cpp
* CSE 274 - Fall 2012
* My solution for Traveling Sales Person
*
* @author Matthew Dwyer
* @date 12/3/2012
*
* @note This file is (c) 2012. It is licensed under the
* CC BY 3.0 license (http://creativecommons.org/licenses/by/3.0/),
* which means you are free to use, share, and remix it as long as you
* give attribution. Commercial uses are allowed.
*/

#include "GraphAlgs.h"
#include <iostream>

std::vector<NodeID> bestTour;
int* currentTour;
double bestLen;
double currentLen;
Graph* graph;
int size;
double sum1;
int count = 0;

void setup(Graph* G)
{
	bestTour.resize(G->size());
	bestLen = 0.0;
	currentLen = 0.0;
	graph = G;
	size = G->size();

	currentTour = new int[G->size()];

	for(int x = 0; x < size; x++)
	{
		currentTour[x] = x;
		bestTour[x] = x;
	}
	
	// Need to initialize best length for later tests
	for(int y = 0; y < size - 1; y++)
		bestLen += graph->weight(currentTour[y], currentTour[y + 1]);

	bestLen += graph->weight(currentTour[size - 1], currentTour[0]);

}


std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G)
{
	setup(G);
	
	// Starting place is 1, the initial sum is 0
	tour(currentTour, size, 1, 0);

	return make_pair(bestTour, bestLen);
}

void swap(int a, int b)
{
	NodeID temp = currentTour[a];
	currentTour[a] = currentTour[b];
	currentTour[b] = temp;
}

void tour(int* arr, int numnodes, int startingPlace, int sum)
{
	
	if(sum < bestLen)
	{
		// Thanks to Matthew Marine for pointing out that I can start at startingPlace + 1
		for(int x = startingPlace + 1; x < numnodes; x++)
		{
			swap(startingPlace, x);
			// Matthew Marine also pointed out how to use the summing correctly in this case
			sum += graph->weight(currentTour[startingPlace - 1], currentTour[startingPlace]);

			tourCycle(sum, startingPlace);
			tour(arr, numnodes, startingPlace + 1, sum);
			swap(x, startingPlace);
		}
	}

}

void tourCycle(double sum, int cur)
{
	// Sums the current tour
	for(int x = 0; x < size - 1; x++)
		sum += graph->weight(currentTour[x], currentTour[x + 1]);

	sum += graph->weight(currentTour[size - 1], 0);

	if(sum < bestLen)
	{
		for(int y = 0; y < size; y++)
			bestTour[y] = currentTour[y];

		bestLen = sum;
	}

}