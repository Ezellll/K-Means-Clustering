// prevent multiple inclusions of header
#ifndef CLUSTERING_H
#define CLUSTERING_H

#include <algorithm>
#include <fstream>
#include <time.h>
#include <vector>
#include <iostream>
#include "Node.h"

using namespace std;

/// <summary>
/// Clustering class definition
/// Base class
/// </summary>
class Clustering
{
public:
	/// <summary>
	/// Constructor initializes K(Number of Cluster), Total Points, Total Values(x,y)
	/// </summary>
	/// <param name=""></param>
	Clustering(int);
	~Clustering();
	/// <summary>
	/// Function to set the Cluster Id
	/// </summary>
	/// <param name="Id_cluster"></param>
	void setIDCluster(int Id_cluster);
	
	/// <summary>
	/// function to set total_points
	/// </summary>
	/// <param name=""></param>
	void setTotalPoints(int);
	/// <summary>
	/// function to set the total_values
	/// </summary>
	/// <param name=""></param>
	void setTotalValues(int);
	/// <summary>
	/// function to set K
	/// </summary>
	/// <param name=""></param>
	void setK(int);
	/// <summary>
	/// function to set the inizilazing central values 
	/// </summary>
	/// <param name="node"></param>
	void setNode(Node node);
	/// <summary>
	/// Changing center point based on incoming index and value
	/// </summary>
	/// <param name="index"></param>
	/// <param name="value"></param>
	void setCentralValue(int index, double value);

	/// <summary>
	/// Function to retrieve the  Clusters' total point
	/// </summary>
	/// <returns></returns>
	int getTotalPoints() const;
	/// <summary>
	/// Function to retrieve the Number of values read from 20.txt and 40.txt files
	/// </summary>
	/// <returns></returns>
	int getTotalPointss() const;

	/// <summary>
	/// Function to Return Node(x,y) from the points vector,  through incoming index
	/// </summary>
	/// <param name="index"></param>
	/// <returns></returns>
	Node getPoint(int index) const;

	/// <summary>
	/// Function to retrieve the  total values (x,y)
	/// </summary>
	/// <returns></returns>
	int getTotalValues() const;

	/// <summary>
	/// Function to retrieve the  K
	/// </summary>
	/// <returns></returns>
	int getK() const;

	/// <summary>
	/// Function to retrieve clusters' center values
	/// </summary>
	/// <param name="index"></param>
	/// <returns></returns>
	double getCentralValue(int index) const;
	/// <summary>
	/// Function to retrieve clusters' center values
	/// </summary>
	/// <returns></returns>
	int getID() const;

	/// <summary>
	/// Function to retrieve clustering vector which include clusters' node
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	vector <Clustering> getCluster(void) const;
	/// <summary>
	/// Function to returns vector that holds nodes read from 20.txt and 40.txt files
	/// </summary>
	/// <returns></returns>
	vector<Node>& getNodePoints() ;
	
	/// <summary>
	/// Function to read data from 20.txt and 40.txt files and keeps these data in points vector.
	/// </summary>
	/// <param name="a"></param>
	void readingData(int a);
	/// <summary>
	/// Function to add a node to the points vector in the Clustering's object
	/// </summary>
	/// <param name="node"></param>
	void addPoint(Node node);
	/// <summary>
	/// Function to erase Node from the points vector according to the incoming "Point ID" value
	/// </summary>
	/// <param name="id_point"></param>
	/// <returns></returns>
	bool removePoint(int id_point);
	/// <summary>
	/// Function to print clusters vector
	/// </summary>
	void printClustring();

protected:
	
	/// <summary>
	/// Store the Clustering's objects
	/// </summary>
	vector<Clustering> clusters;
	/// <summary>
	/// Store Node objects that hold values read from file
	/// </summary>
	vector<Node> points;
	
private:
	/// <summary>
	/// Store size of points vector
	/// </summary>
	int total_points;
	/// <summary>
	/// // Store number of clusters
	/// </summary>
	int K;
	/// <summary>
	/// Store number of values(x,y olduðu için 2 x,y,z olsaydý =3 olurdu)
	/// </summary>
	int total_values;
	/// <summary>
	/// Store the Cluster ID
	/// </summary>
	int id_cluster;
	/// <summary>
	/// Store the central values
	/// </summary>
	vector<double> central_values;
	/// <summary>
	/// Store the values(x,y degerlerini)
	/// </summary>
	vector<double> values;
};

#endif