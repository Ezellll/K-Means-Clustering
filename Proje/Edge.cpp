#include "Edge.h"
/// <summary>
/// // constructor initializes node_points, id_cluster
/// </summary>
/// <param name="node_points"></param>
/// <param name="ID_cluster"></param>
/// <param name="ID_edge"></param>
Edge::Edge(vector <Clustering> node_points,int ID_cluster, int ID_edge)
{
	clusters = node_points;
	id_cluster = ID_cluster;
	id_edge = ID_edge;
	calculateEdgeWeight();
}

Edge::~Edge()
{
}
/// <summary>
/// // Calculate distance between  two nodes in clusters
/// </summary>
/// <param name=""></param>
void Edge::calculateEdgeWeight(void)
{
	double edge_w = 0.0;

	for (int i = 0; i < clusters[id_cluster].getTotalPoints(); i++) {
		edge_w = pow((clusters[id_cluster].getPoint(id_edge).getValue(0) - clusters[id_cluster].getPoint(i).getValue(0)), 2) 
			   + pow((clusters[id_cluster].getPoint(id_edge).getValue(1) - clusters[id_cluster].getPoint(i).getValue(1)), 2);
		edge_w=sqrt(edge_w);
		edges_w.push_back(edge_w);
	}
}
/// <summary>
/// // Function to retrieve id_edge
/// </summary>
/// <returns></returns>
int Edge::getID() const
{
	return id_edge;
}
/// <summary>
/// // Function to retrieve edges_w vector
/// </summary>
/// <returns></returns>
vector <double> Edge::getEdgeW()
{
	return edges_w;
}