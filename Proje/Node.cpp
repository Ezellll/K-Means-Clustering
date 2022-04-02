#include "Node.h" // include definition of class Node


/// <summary>
/// Constructor initializes id_node, total_values, values vector
/// </summary>
/// <param name="ID_node"></param>
/// <param name="Values"></param>
Node::Node(int ID_node, vector<double>& Values)
{
	id_node = ID_node;
	total_values = Values.size();
	for (int i = 0; i < total_values; i++) {
		values.push_back(Values[i]);
	}
}
Node::~Node()
{
}
/// <summary>
/// Function to set the id_cluster
/// </summary>
/// <param name="ID_cluster"></param>
void Node::setCluster(int ID_cluster)
{
	id_cluster = ID_cluster;
}
/// <summary>
/// Function to retrieve the id_node
/// </summary>
/// <returns>
/// id_node
/// </returns>
int Node::getID() const
{
	return id_node;
}
/// <summary>
/// Function to retrieve the Value of values vector
/// </summary>
/// <param name="index"></param>
/// <returns>
/// values[index]
/// </returns>
double Node::getValue(int index)
{
	return values[index];
}
/// <summary>
/// Function to retrieve the id_cluster
/// </summary>
/// <returns>
/// id_cluster
/// </returns>
int Node::getCluster() const
{
	return id_cluster;
}
/// <summary>
/// Function to retrieve the total values of vector(x,y)
/// </summary>
/// <returns>
/// total_values
/// </returns>
int Node::getTotalValues() const
{
	return total_values;
}
/// <summary>
/// Function to add double value to values vector
/// </summary>
/// <param name="value"></param>
void Node::addValue(double value)
{
	values.push_back(value);
}
/// <summary>
/// Function to print x and y coordinates of a post office
/// </summary>
void Node::printValue()
{
	cout << setprecision(12) << setw(7) <<left << "Point-" << getID() + 1 << "\t\t" <<setw(11)<<left << values[0] << "\t\t" <<setw(11) <<left << values[1] << endl;
}

