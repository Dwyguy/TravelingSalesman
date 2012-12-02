#include "MatrixGraph.h"

using namespace std;

MatrixGraph::MatrixGraph(unsigned num_nodes)
{
	M.resize(num_nodes);
	for(int x = 0; x < num_nodes; x++)
	{
		M[x].resize(num_nodes);
		for(int y = 0; y < num_nodes; y++)
			M[x][y] = 0;
	}

	num_edges = 0;
}

MatrixGraph::~MatrixGraph()
{

}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{
	if(u != v)
	{
		M[u][v] = weight;
		M[v][u] = weight;
	}
	else
		M[u][v] = -1;
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const
{
	if(M[u][v] != -1)
		return M[u][v];
	else
		return 0;
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const
{
	list<NWPair>* nodeList = new std::list<NWPair>();

	for(int x = 0; x < M.size(); x++)
		if(M[u][x] != 0)
			nodeList->push_back(make_pair(u, M[u][x]));

	return *nodeList;
}

unsigned MatrixGraph::degree(NodeID u) const
{

	/*
	int degree = 0;

	for each vector element in M[u]
	if(M[u][element] != -1)
	degree++;

	return degree;

	*/
	return 0;
}

unsigned MatrixGraph::size() const
{
	/* graph traversal here, or just make a variable.  Not sure if we can edit MatrixGraph.h or not */
	return 0;
}

unsigned MatrixGraph::numEdges() const
{
	return num_edges;
}
