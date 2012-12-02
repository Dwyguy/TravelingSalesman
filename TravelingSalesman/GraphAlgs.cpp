#include "GraphAlgs.h"


void GraphAlgs::setup(Graph* G)
{
	bestTour.resize(G->size());
	bestTourLen = 0.0;

	for(int x = 0; x < G->size(); x++)
	{
		currentTour[x] = 0;
	}
	
}


std::pair<std::vector<NodeID>, EdgeWeight> GraphAlgs::TSP(Graph* G)
{
	setup(G);
}

std::vector<NodeID> GraphAlgs::tour(int* arr, int numnodes, int startingPlace);
{
	if(numnodes - startingPlace == 1)
		int stuff;
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

void GraphAlgs::swap(int a, int b)
{
	int temp = currentTour[a];
	currentTour[a] = currentTour[b];
	currentTour[b] = temp;
}
	

/*void DFS(G, S)
{
	Stack openList;
	int seenList;
	openList.push(S);
	seenList[S] = S;
	
	while(!openList.empty())
	{
		u = openList.top();
		openList.pop();
		
		for all v, which are neighbors of u
		if(seenList[v] == -1)
		{
			seenList[v] = u;
			openList.push[v];
		}
	}
}
*/