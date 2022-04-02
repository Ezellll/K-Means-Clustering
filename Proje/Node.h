//prevent multiple inclusions of header
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


class Node
{
public:
	/// <summary>
	/// Constructor initializes identity of Node and X,Y coordinates
	/// </summary>
	/// <param name=""></param>
	/// <param name=""></param>
	Node(int, vector<double>&);
	/// <summary>
	/// Function to set the id_cluster
	/// </summary>
	/// <param name=""></param>
	~Node();
	void setCluster(int);
	/// <summary>
	/// Function to retrieve the id_node
	/// </summary>
	/// <returns></returns>
	int getID() const;
	/// <summary>
	/// Function to retrieve the Value of values vector
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	double getValue(int);
	/// <summary>
	/// Function to retrieve the id_cluster
	/// </summary>
	/// <returns></returns>
	int getCluster() const;
	/// <summary>
	/// Function to retrieve the total values of vector(x,y)
	/// </summary>
	/// <returns></returns>
	int getTotalValues() const;
	/// <summary>
	/// Function to add double value to values vector
	/// </summary>
	/// <param name=""></param>
	void addValue(double);
	/// <summary>
	/// Function to print x and y coordinates of a post office
	/// </summary>
	void printValue();
private:
	
	/// <summary>
	/// Store Node ID 
	/// </summary>
	int id_node;
	
	/// <summary>
	/// Store Cluster ID 
	/// </summary>
	int id_cluster;
	
	/// <summary>
	/// Store x and y coordinates of a post office
	/// </summary>
	vector<double> values;

	/// <summary>
	/// Store size of vector
	/// </summary>
	int total_values;
};

#endif