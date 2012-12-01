#include "MatrixGraph.h"

using namespace std;

MatrixGraph::MatrixGraph(unsigned num_nodes)
{
	M.resize(num_nodes);
	for(int x = 0; x < num_nodes; x++)
		M[x].resize(num_nodes);



	num_edges = 0;
}

MatrixGraph::~MatrixGraph()
{

}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{
	/*
	if(u != v)
	M[u][v] = weight;
	M[v][u] = weight;
	else
	M[u][v] = -1;

	*/
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const
{
	/*
	if(M[u][v] != -1)
	return M[u][v];
	else
	return 0;
	*/
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
