#include "KMeans.h"
/// <summary>
/// KMeans class is derived from base class Clustering
/// </summary>
/// <param name="k"></param>
/// <param name="Max_iteration"></param>
KMeans::KMeans(int k, int Max_iteration)
	//explicitly call base-class constructer
	:Clustering(k)
{
	setMaxIteration(Max_iteration);
}
/// <summary>
/// Function to set the  max_iterations
/// </summary>
/// <param name="a"></param>
void KMeans::setMaxIteration(int a)
{
	max_iterations = a;
}
/// <summary>
/// Return ID of nearest center (uses euclidean distance)
/// </summary>
/// <param name="node"></param>
/// <returns>
/// node
/// </returns>
int KMeans::getIDNearestCenter(Node node)
{
	double sum = 0.0, min_dist;
	int id_cluster_center = 0;

	for (int i = 0; i < getTotalValues(); i++)
	{
		sum += pow(clusters[0].getCentralValue(i) - node.getValue(i), 2.0);
	}

	min_dist = sqrt(sum);

	for (int i = 1; i < getK(); i++)
	{
		double dist;
		sum = 0.0;

		for (int j = 0; j < getTotalValues(); j++)
		{
			sum += pow(clusters[i].getCentralValue(j) - node.getValue(j), 2.0);
		}

		dist = sqrt(sum);

		if (dist < min_dist)
		{
			min_dist = dist;
			id_cluster_center = i;
		}
	}

	return id_cluster_center;
}
/// <summary>
/// Function to run the machine learning approaches
/// </summary>
/// <param name="b"></param>
void KMeans::run(int b)
{
	if (getK() > getTotalPointss())
		return;
	// Set nodes in clusters randomly
	randomCluster(points,b);

	// KMeans++ more accurate center point determination at the beginning
	//Randomly select the first centroid from the data points.
	int a = rand() % 5;
	clusters[0].setNode(clusters[0].getPoint(a)); 
	// For each data point compute its distance from the nearest, previously chosen centroid.
	// The point having maximum distance from the nearest centroid is  to be selected next as a centroid
	for (int i = 1; i < getK(); i++)
	{
		clusters[i].setNode((findFarthestPoints(clusters[i - 1].getPoint(a) , points))[i-1]);
	}

	int iter = 1;
	while (true)
	{
		bool done = true;

		// Associates each point to the nearest center;
		for (int i = 0; i < getTotalPointss(); i++)
		{
			int id_old_cluster = points[i].getCluster();
			int id_nearest_center = getIDNearestCenter(points[i]);
			if (id_old_cluster != id_nearest_center)
			{
				if (id_old_cluster != -1)
					clusters[id_old_cluster].removePoint(points[i].getID());

				points[i].setCluster(id_nearest_center);
				clusters[id_nearest_center].addPoint(points[i]);
				done = false;
			}
		}


		// Recalculating the center of each clusters
		for (int i = 0; i < getK();i++)
		{
			for (int j = 0; j < getTotalValues(); j++)
			{
				int total_points_cluster = clusters[i].getTotalPoints();
				double sum = 0.0;

				if (total_points_cluster > 0)
				{
					for (int p = 0; p < total_points_cluster; p++)
						sum += clusters[i].getPoint(p).getValue(j);
					clusters[i].setCentralValue(j, sum / total_points_cluster);
				}
			}
		}

		if (done == true || iter >= max_iterations)
		{

			cout << "Break in iteration " << iter << "\n\n";
			break;
		}
		iter++;
	}
	// Store the nodes of the edge, an identity, and the edge's weight in edges vector
	for (int j = 0; j < getK(); j++) {
		for (int i = 0; i < clusters[j].getTotalPoints(); i++) {
			Edge edge(clusters,j,i);
			edges.push_back(edge);
		}
	}

}
/// <summary>
/// // Function to assign nodes to random clusters
/// </summary>
/// <param name="points"></param>
/// <param name="a"></param>
void KMeans::randomCluster(vector<Node>& points,int a)
{
	srand(time(0));
	//store clustersize vector
	vector<int> clustersize(getK());
	if (getK() == 2) {
		clustersize[0] = 10;
		clustersize[1] = 10;
		if (a == 2) {
			clustersize[0] = 25;
			clustersize[1] = 25;
		}
	}
	else if(getK() == 3) {
		clustersize[0] = 7;
		clustersize[1] = 7;
		clustersize[2] = 6;
		if (a == 2) {
			clustersize[0] = 15;
			clustersize[1] = 15;
			clustersize[2] = 20;
		}
	}
	else if (getK() == 4) {
		clustersize[0] = 5;
		clustersize[1] = 5;
		clustersize[2] = 5;
		clustersize[3] = 5;
		if (a == 2) {
			clustersize[0] = 12;
			clustersize[1] = 12;
			clustersize[2] = 12;
			clustersize[3] = 14;
		}
	}
	vector <int> prohibited_indexes;
	for (int i = 0; i < getK(); i++)
	{
		int p = 0;
		while (p < clustersize[i])
		{
			int index_point = rand() % getTotalPointss();
			//It is done so that the same number does not exist
			if (find(prohibited_indexes.begin(), prohibited_indexes.end(), index_point) == prohibited_indexes.end())
			{
				prohibited_indexes.push_back(index_point);
				points[index_point].setCluster(i);
				Clustering cluster(getK());
				clusters.push_back(cluster);
				clusters[i].setIDCluster(i);
				clusters[i].addPoint(points[index_point]);
				p++;
			}
		}
		cout << endl;
	}
	// Show the random clustering
	cout << "Show the random clustering " << endl;
	for (int i = 0; i < getK(); i++)
	{
		int total_points_cluster = clusters[i].getTotalPoints();

		cout << "Cluster " << clusters[i].getID() + 1 << endl;
		for (int j = 0; j < total_points_cluster; j++)
		{
			cout << "Point " << clusters[i].getPoint(j).getID() + 1 << ": ";
			for (int p = 0; p < getTotalValues(); p++)
				cout << clusters[i].getPoint(j).getValue(p) << " ";

			cout << endl;
		}
	}
	cout << endl << endl << endl;
}
/// <summary>
/// //Function to determine the farthest points in the initialization step
/// </summary>
/// <param name="node"></param>
/// <param name="points"></param>
/// <returns>
/// e
/// </returns>
vector<Node> KMeans::findFarthestPoints(Node node, vector<Node>& points)
{
	double d = 0.0;
	// Store distance
	vector <double> distance;
	for (int i = 0; i < getTotalPointss(); i++)
	{
		// Calculating distances from first center to other points
		d = sqrt(pow((node.getValue(0) - points[i].getValue(0)), 2) + pow((node.getValue(1) - points[i].getValue(1)), 2));
		distance.push_back(d);
	}
	vector <double > sorted_distance(distance.size());
	partial_sort_copy(distance.begin(), distance.end(), sorted_distance.begin(), sorted_distance.end());
	// second center 
	int a=find(distance.begin(), distance.end(), sorted_distance[sorted_distance.size() - 1])- distance.begin();
	// third center
	int b= find(distance.begin(), distance.end(), sorted_distance[sorted_distance.size() - 2]) - distance.begin();
	// fourth center
	int c = find(distance.begin(), distance.end(), sorted_distance[sorted_distance.size() - 3]) - distance.begin();
	// fifth center
	int f = find(distance.begin(), distance.end(), sorted_distance[sorted_distance.size() - 4]) - distance.begin();
	vector<Node> e;
	e.push_back(points[a]);
	e.push_back(points[b]);
	e.push_back(points[c]);
	e.push_back(points[f]);
	return e;
}
