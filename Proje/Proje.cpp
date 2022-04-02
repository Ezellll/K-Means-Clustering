#include <iostream>
#include "Clustering.h" 
#include "KMeans.h"
#include "Node.h"
#include "Graph.h"
using namespace std;

int main(int argc, char** argv) {
	
	int s=0;
	int k = 2;
	int iteration = 5;
	cout << "Enter the file you want to select : " << endl << "1) 20.txt" << endl << "2) 50.txt" << endl;
	cin >> s;
	while (!((s == 1) || (s == 2))) {
		cout << "Please Enter valid number :" << endl << "1) 20.txt" << endl << "2) 50.txt" << endl;
		cin >> s;
	}
	cout << "Enter the number of cluster(K) (2-4) : " << endl;
	cin >> k;
	cout << "Enter the maximum iteration : " << endl;
	cin >> iteration;

 	KMeans k1(k,iteration);
	k1.readingData(s);
	k1.run(s);
	k1.printClustring();
	
	//Print The Graph
	Graph g1(k);
	g1.printGrap(k1.getCluster());

	return 0;

}