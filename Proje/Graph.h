#ifndef GRAPH_H
#define GRAPH_H
#include <opencv2/core.hpp> 
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <sstream> 
#include "Clustering.h"
#include "Node.h"
using namespace std;
class Graph
{
public:
	/// <summary>
	/// Constructor initializes K(Number of Cluster)
	/// </summary>
	/// <param name="k"></param>
	Graph(int k);
	~Graph();
	/// <summary>
	/// Function to set K
	/// </summary>
	/// <param name=""></param>
	void setK(int);
	/// <summary>
	/// Funtion to return K
	/// </summary>
	/// <returns></returns>
	int getK() const;
	/// <summary>
	/// Show nodes and clusters with opencv
	/// </summary>
	/// <param name="clusters"></param>
	void printGrap(vector <Clustering> clusters);
private:
	/// <summary>
	/// Function  to draw circles with opencv
	/// </summary>
	/// <param name="img"></param>
	/// <param name="center"></param>
	/// <param name=""></param>
	void MyFilledCircle(cv::Mat img, cv::Point center, int);
	/// <summary>
	/// Store Number of Cluster
	/// </summary>
	int K;
};

#endif