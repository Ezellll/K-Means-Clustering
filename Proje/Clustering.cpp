#include "Clustering.h" 
#include <iostream>
using namespace std;

/// <summary>
/// Constructor initializes K(Number of Cluster), Total Points, Total Values(x,y)
/// </summary>
/// <param name="k"></param>
Clustering::Clustering(int k)
{
	setTotalPoints(0);
	setTotalValues(2);
	setK(k);
}
Clustering::~Clustering()
{
}
/// <summary>
/// Function to set the Cluster Id
/// </summary>
/// <param name="Id_cluster"></param>
void Clustering::setIDCluster(int Id_cluster)
{
	id_cluster = Id_cluster;
}
/// <summary>
/// Function to set the Cluster Id
/// </summary>
/// <param name="node"></param>
void Clustering::setNode(Node node)
{
	int total_values = node.getTotalValues();
	for (int i = 0; i < total_values; i++) {
		central_values.push_back(node.getValue(i));
	}

}
/// <summary>
/// Function to set total_points
/// </summary>
/// <param name="a"></param>
void Clustering::setTotalPoints(int a)
{
	total_points = a;
}
/// <summary>
/// Function to set the total_values
/// </summary>
/// <param name="a"></param>
void Clustering::setTotalValues(int a)
{
	total_values = a;
}
/// <summary>
/// Function to set K
/// </summary>
/// <param name="a"></param>
void Clustering::setK(int a)
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
/// Changing center point based on incoming index and value
/// </summary>
/// <param name="index"></param>
/// <param name="value"></param>
void Clustering::setCentralValue(int index, double value)
{
	central_values[index] = value;
}
/// <summary>
/// Function to retrieve clusters' center values
/// </summary>
/// <returns>
/// id_cluster
/// </returns>
int Clustering::getID() const
{
	return id_cluster;
}
/// <summary>
/// Function to returns vector that holds nodes read from 20.txt and 40.txt files
/// </summary>
/// <returns>
/// points
/// </returns>
vector<Node>& Clustering::getNodePoints()
{
	return points;
}
/// <summary>
/// // Function to retrieve clustering vector which include clusters' node
/// </summary>
/// <param name=""></param>
/// <returns>
/// clusters
/// </returns>
vector <Clustering> Clustering::getCluster(void) const
{
	return clusters;
}
/// <summary>
/// Function to retrieve the Number of values read from 20.txt and 40.txt files
/// </summary>
/// <returns>
/// total_points
/// </returns>
int Clustering::getTotalPointss() const
{
	return total_points;
}
/// <summary>
/// Function to retrieve the  total values (x,y)
/// </summary>
/// <returns>
/// total_values
/// </returns>
int Clustering::getTotalValues() const
{
	return total_values;
}
/// <summary>
/// Function to retrieve the  K
/// </summary>
/// <returns>
/// K
/// </returns>
int Clustering::getK() const
{
	return K;
}
/// <summary>
/// // Function to retrieve the  Clusters' total point
/// </summary>
/// <returns>
/// points.size()
/// </returns>
int Clustering::getTotalPoints() const
{
	return points.size();
}
/// <summary>
/// Function to Return Node(x,y) from the points vector,  through incoming index
/// </summary>
/// <param name="index"></param>
/// <returns>
/// points[index]
/// </returns>
Node Clustering::getPoint(int index) const
{
	return points[index];

}
/// <summary>
/// Function to retrieve clusters' center values
/// </summary>
/// <param name="index"></param>
/// <returns>
/// central_values[index]
/// </returns>
double Clustering::getCentralValue(int index) const
{
	return central_values[index];
}
/// <summary>
/// Function to read data from 20.txt and 40.txt files and keeps these data in points vector.
/// </summary>
/// <param name="a"></param>
void Clustering::readingData(int a)
{
	total_points = 0;
	total_values = 2;
	srand(time(NULL));
	ifstream veriDosyasi;
	if (a == 1) {
		veriDosyasi.open("20.txt");
	}
	else if (a == 2) {
		veriDosyasi.open("50.txt");
	}
	for (int i=0; !veriDosyasi.eof();i++)
	{
		values.clear();
		for (int j = 0; j < total_values; j++)
		{
			double value;
			veriDosyasi >> value;
			values.push_back(value);
		}
		Node p(i, values);
		points.push_back(p);
		total_points++;
	}
	cout << "POINTS\t\t\t" << " X\t\t\t\t" << "Y" << endl;
	cout << "----------------------------------------------------" << endl;
 	for (int i = 0; i < total_points; i++)
	{
		points[i].printValue();
	}

}
/// <summary>
/// //Function to erase Node from the points vector according to the incoming "Point ID" value
/// </summary>
/// <param name="id_point"></param>
/// <returns>
/// True or False
/// </returns>
bool Clustering::removePoint(int id_point)
{
	int total_points = points.size();

	for (int i = 0; i < total_points; i++)
	{
		if (points[i].getID() == id_point)
		{
			points.erase(points.begin() + i);
			return true;
		}
	}
	return false;
}
/// <summary>
/// Function to add a node to the points vector in the Clustering's object
/// </summary>
/// <param name="node"></param>
void Clustering::addPoint(Node node)
{
	points.push_back(node);
}

/// <summary>
/// // Function to print clusters vector
/// </summary>
void Clustering::printClustring()
{
	cout << "POINTS\t\t\t    " << " X\t\t\t    " << "Y" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	for (int i = 0; i < K; i++)
	{
		cout << endl;
		int total_points_cluster = clusters[i].getTotalPoints();
		cout << "Cluster " << clusters[i].getID() + 1 << endl << endl;
		for (int j = 0; j < total_points_cluster; j++)
		{
			cout << setw(7) << left << "Point " << clusters[i].getPoint(j).getID() + 1 << ": ";
			for (int p = 0; p < total_values; p++)
				cout << "\t\t" << setw(11) << left<<clusters[i].getPoint(j).getValue(p) << " ";

			cout << endl;
		}

		cout << "\nCenter Point : ";
		for (int j = 0; j < total_values; j++)
			cout << "\t\t" << setw(11) << left<<clusters[i].getCentralValue(j) << " ";

		cout << "\n\n";
	}

}
