#include "Graph.h"
/// <summary>
/// // Constructor initializes K(Number of Cluster)
/// </summary>
/// <param name="k"></param>
Graph::Graph(int k)
{
	setK(k);
}

Graph::~Graph()
{
}
/// <summary>
/// Function to set K
/// </summary>
/// <param name="a"></param>
void Graph::setK(int a)
{
	string message = "ERROR ! You entered the number of clusters out of range (2-4)";
	try
	{
		K = a;
		if (!(K == 2 || K == 3 || K == 4))
		{
			throw message;
		}

	}
	catch (string x)
	{

		cout << x << endl;
		cout << " K = 4  " << endl;
		K = 4;
	}
}
/// <summary>
/// Funtion to return K
/// </summary>
/// <returns>
/// K
/// </returns>
int Graph::getK() const
{
	return K;
}
/// <summary>
/// Show nodes and clusters with opencv
/// </summary>
/// <param name="clusters"></param>
void Graph::printGrap(vector <Clustering> clusters)
{	
	
	char atom_window[] = "CLUSTERING";
	cv::Mat atom_image = cv::Mat::zeros(600, 600, CV_8UC3);
	stringstream ss;
	// Background pure white
	for (int i = 0; i < atom_image.rows; i++) {
		for (int j = 0; j < atom_image.cols; j++) {
			line(atom_image, cv::Point(i, j), cv::Point(i, j), cv::Scalar(255, 255, 255), 1, 8);
		}
	}
	// Plotting the x y axes
	line(atom_image, cv::Point(0, 0), cv::Point(0, 600), cv::Scalar(0, 0, 0), 6, 8);
	line(atom_image, cv::Point(0, 600), cv::Point(600, 600), cv::Scalar(0, 0, 0), 6, 8);
	putText(atom_image, "Y(0,600)", cv::Point(20, 30), cv::FONT_HERSHEY_DUPLEX, 0.6, cv::Scalar(0, 0, 0), 1, false);
	putText(atom_image, "X(600,0)", cv::Point(500, 580), cv::FONT_HERSHEY_DUPLEX, 0.6, cv::Scalar(0, 0, 0), 1, false);
	circle(atom_image, cv::Point(480, 30), 5, cv::Scalar(255, 0, 0), cv::FILLED, cv::LINE_8);
	circle(atom_image, cv::Point(480, 40), 5, cv::Scalar(0, 255, 0), cv::FILLED, cv::LINE_8);
	circle(atom_image, cv::Point(480, 50), 5, cv::Scalar(0, 0, 255), cv::FILLED, cv::LINE_8);
	circle(atom_image, cv::Point(480, 60), 5, cv::Scalar(255, 0, 255), cv::FILLED, cv::LINE_8);
	circle(atom_image, cv::Point(480, 70), 5, cv::Scalar(255, 255, 0), cv::FILLED, cv::LINE_8);
	putText(atom_image, "Cluster-1", cv::Point(490, 32), cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(0, 0, 0), 1, false);
	putText(atom_image, "Cluster-2", cv::Point(490, 42), cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(0, 0, 0), 1, false);
	putText(atom_image, "Cluster-3", cv::Point(490, 52), cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(0, 0, 0), 1, false);
	putText(atom_image, "Cluster-4", cv::Point(490, 62), cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(0, 0, 0), 1, false);
	putText(atom_image, " Center", cv::Point(490, 72), cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(0, 0, 0), 1, false);
	vector<double> values;
	vector<double> center;
	// Plot the Nodes inside the clusters as a circle 
	// Plotting the center points as a circle
	for (int i = 0; i < getK(); i++)
	{
		int total_points_cluster = clusters[i].getTotalPoints();
		for (int j = 0; j < total_points_cluster; j++)
		{
			values.clear();
			stringstream ss;
			ss << clusters[i].getPoint(j).getID() + 1; //pointi veriyor
			for (int p = 0; p < 2; p++) {
				values.push_back(clusters[i].getPoint(j).getValue(p));
			}
			string s = "";
			ss >> s;
			MyFilledCircle(atom_image, cv::Point(values[0], values[1]),i);
			putText(atom_image, ("Point-" + s), cv::Point((values[0] / 100)-20, (600-(values[1] / 100)-5)), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(255, 0, 0), 1, false);

		}
		
		center.clear();
		for (int j = 0; j < 2; j++)
		{
			center.push_back(clusters[i].getCentralValue(j));
		}
		MyFilledCircle(atom_image, cv::Point(center[0], center[1]),5);
		putText(atom_image, "Center", cv::Point((center[0] / 100)-10, (600 - (center[1] / 100))), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(255, 0, 0), 1, false);
	}
	imshow(atom_window, atom_image);
	cv::waitKey(0);
}
/// <summary>
/// Show nodes and clusters with opencv
/// </summary>
/// <param name="img"></param>
/// <param name="center"></param>
/// <param name="i"></param>
void Graph::MyFilledCircle(cv::Mat img, cv::Point center, int i)
{
	center.y = 600-(center.y / 100);
	center.x = center.x / 100;
	if (i == 0) {
		circle(img, center, 5, cv::Scalar(255, 0, 0), cv::FILLED, cv::LINE_8);
	}
	else if (i == 1) {
		circle(img, center,5, cv::Scalar(0, 255, 0), cv::FILLED, cv::LINE_8);
	}
	else if (i == 2) {
		circle(img, center, 5, cv::Scalar(0, 0, 255), cv::FILLED, cv::LINE_8);
	}
	else if (i == 3) {
		circle(img, center, 5, cv::Scalar(255, 0, 255), cv::FILLED, cv::LINE_8);
	}
	else if (i == 4) {
		circle(img, center, 5, cv::Scalar(50, 50, 255), cv::FILLED, cv::LINE_8);
	}
	else if (i == 5) {
		circle(img, center, 5, cv::Scalar(255, 255, 0), cv::FILLED, cv::LINE_8);
	}
    
}