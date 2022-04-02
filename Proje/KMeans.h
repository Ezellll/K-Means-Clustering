#ifndef KMEANS_H
#define KMEANS_H
#include "Node.h"
#include "Clustering.h"
#include "Edge.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cmath>
/// <summary>
/// KMeans class is derived from base class Clustering
/// </summary>
class KMeans :public Clustering
{
public:
	/// <summary>
	/// Constructor initializes max iteration and call base-class constructer
	/// </summary>
	/// <param name="k"></param>
	/// <param name="Max_iteration"></param>
	KMeans(int k,int Max_iteration);
	/// <summary>
	/// Function to set the  max_iterations
	/// </summary>
	/// <param name="a"></param>
	void setMaxIteration(int a);
	/// <summary>
	/// Function to run the machine learning approaches
	/// </summary>
	/// <param name="a"></param>
	void run(int a);
	/// <summary>
	/// Function to determine the farthest points in the initialization step
	/// </summary>
	/// <param name="node"></param>
	/// <param name="points"></param>
	/// <returns></returns>
	vector<Node> findFarthestPoints(Node node, vector<Node>& points);
private:
	/// <summary>
	/// // Store maximum iteration
	/// </summary>
	int max_iterations;
	/// <summary>
	/// Return ID of nearest center (uses euclidean distance)
	/// </summary>
	/// <param name="node"></param>
	/// <returns></returns>
	int getIDNearestCenter(Node node);
	/// <summary>
	/// Function to assign nodes to random clusters
	/// </summary>
	/// <param name="points"></param>
	/// <param name="a"></param>
	void randomCluster(vector<Node>& points, int a);
	/// <summary>
	/// Store the distance of the nodes in the clusters from each other
	/// </summary>
	vector <Edge> edges;
};

#endif