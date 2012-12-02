#include "ListGraph.h"


ListGraph::ListGraph(int numnodes)
{
	edgeList.resize(numnodes);

	num_edges = 0;
}

ListGraph::~ListGraph()
{

}

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{
	EList::const_iterator it;
	for(it = edgeList[u].begin(); it != edgeList[u].end(); it++)
	{
		NWPair tPair = (*it);
		if(tPair.first == v)
		{
			tPair.second = weight; // Updates weight
			for(it = edgeList[v].begin(); it != edgeList[v].end(); it++)
			{
				NWPair tPair = (*it);
				if(tPair.first == u)
				{
					tPair.second = weight; // Updates weight
					return;  // Edge was found, return
				}
			}
		}
	}

	// Edge was not found, add it
	edgeList[u].push_back(std::make_pair(v, weight));
	edgeList[v].push_back(std::make_pair(u, weight));

	num_edges++;
}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const
{
	EList::const_iterator it;
	for(it = edgeList[u].begin(); it != edgeList[u].end(); it++)
	{
		NWPair tPair = (*it);
		if(tPair.first == v)
			return tPair.second;
	}

	return 0;
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const
{
	return edgeList[u];
}

unsigned ListGraph::degree(NodeID u) const
{
	return edgeList[u].size();
}

unsigned ListGraph::size() const
{
	return edgeList.size();
}

unsigned ListGraph::numEdges() const
{
	return num_edges;
}