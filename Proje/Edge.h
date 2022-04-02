#ifndef EDGE_H
#define EDGE_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "Node.h"
#include "Clustering.h"
using namespace std;
class Edge
{
public:
	/// <summary>
	/// Constructor initializes node_points, id_cluster, id_edge
	/// </summary>
	/// <param name="node_points"></param>
	/// <param name="ID_cluster"></param>
	/// <param name="ID_edge"></param>
	Edge(vector<Clustering> node_points,int ID_cluster,int ID_edge);
	~Edge();
	/// <summary>
	/// Calculate distance between  two nodes in clusters
	/// </summary>
	/// <param name=""></param>
	void calculateEdgeWeight(void);
	/// <summary>
	/// Function to retrieve id_edge
	/// </summary>
	/// <returns></returns>
	int getID() const;
	/// <summary>
	/// Function to retrieve edges_w vector
	/// </summary>
	/// <returns></returns>
	vector <double> getEdgeW();
private:
	/// <summary>
	/// Store the clusters vector
	/// </summary>
	vector <Clustering> clusters;
	/// <summary>
	/// Store the edge ID
	/// </summary>
	int id_edge;
	/// <summary>
	/// Store the cluster ID
	/// </summary>
	int id_cluster;
	vector <double> edges_w;
};

#endif