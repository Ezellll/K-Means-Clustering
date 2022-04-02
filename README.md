# K-Means-Clustering
In this project, I implemented a class hierarchy to cluster Sydney city post offices. Since clustering data is an unsupervised machine learning task, I applied K-Means++ clustering approaches.

# Design

In my project I used five classes(Node, Clustering, KMeans, Edge, Graph) to cluster 
the post offices of the city of sydney.

## Node Class
This class stores the coordinates (x, y) of the data read from text files (20.txt and 
50.txt) with the help of a double type vector with their IDs. At the same time, it can 
add value to the vector created with member functions, print values and read values.

## Clustering Class(Base Class)
This class is the base class for clustering functions. There are member functions to 
read data from the file and print the clustering result to the terminal screen.

### Clustering::readingData() ->

Data is read from text files (20.txt and 50.txt) and objects from Node class are called 
by composition, values are assigned here with ID and these objects created are saved 
in the points vector of Node Class data type.
After this process is completed, the coordinates of the points vector (x,y) are stored 
with the help of Node objects. Total_values(x,y) and total_point(20 or 40) values are 
store with the help of set functions according to the number of data read from the 
file

### Clustering::printClustering() ->
With this member function, it allows us to print the result obtained after the KMeans++ clustering algorithm on the terminal screen


## KMeans Class(Derived Class)
This class inherits from the Clustering class and uses public member functions and 
protected data members to perform the tasks of running K-Means++ algorithms.

### KMeans::run() -> 

K-Means++ algorithm starts working with this member function.
First of all, when this function runs, our points vector where the Node objects are 
kept is taken from the Base Class, then the Nodes are randomly assigned to the 
clusters, and these operations are stored with the Clustering objects in the clusters 
vector created in the base class to save the clustering operations. In this way, we can 
start clustering operations.
KMeans++ initially chooses a random point and assigns it as the center of the first 
cluster to determine a more accurate center point. The findFarthestPoints() function 
is used to find the farthest points from this selected point, and the farthest points are 
assigned as the centers of other clusters. Node addition and subtraction operations 
are performed in the clusters according to these center points created later. The 
center point is recalculated each time. The process ends when the maximum number 
of iterations received by the user or when the Node transition from one cluster to 
another cluster is stopped.

## Edge Class
This class has been created in order to run Kruskal and Prim algorithms and member 
functions have their own inclusive distance of each point in the set and are saved in 
the vector to be used in Kruskal Prim algorithms. These vectors storing Edges objects 
are calculated in the KMeans Class. 

## Graph Class
The Graph class will be used to store the graph and this class will visualize the 
clustering result we created with the member functions using the opencv library.
### Graph::printGraph() ->
First, an image of size (600,600) is created to visualize our data.
The reason why the size of the image is 600,600 is because each point will be scaled 
by 100 and printed on the screen and the highest value of the points is 
57531.977457. 
With the help of the vector that comes after the visual arrangements are made on 
the image, the nodes are created with filled circles in different colors according to the 
clusters. This is done with the help of the MyFilledCircle member function. Center 
points are plotted in the same way.


# Implementation

The project was built using Visual Studio 2022.

Libraries: Opencv 4.2.0

#### Step-1
Our project is opened with the Visual Studio IDE by running the Project.sln file in the 
project file.

#### Step-2
The project is run with the Windows debugger.
![image](https://user-images.githubusercontent.com/83959816/161400077-81d58f3e-f1cc-43b8-ac78-c1576606a9df.png)

#### Step-3 
After the project is run, the desired file number is entered on the terminal screen. If 
an invalid file is entered, the user is again prompted to enter a valid file number.
![image](https://user-images.githubusercontent.com/83959816/161400095-8bcfdf6e-5d79-4af1-b3d9-299bf0b57b1a.png)

#### Step-4
The set information given from the user is requested. When the cluster is entered 
outside the valid range, it is assigned to the maximum number of clusters if it is high, 
and the minimum number of clusters if it is low, with exception handling and the 
program gives an error message but continues to run.

![image](https://user-images.githubusercontent.com/83959816/161400102-30fc29d6-e654-4b7a-9745-16a14e6015e2.png)

#### Step-5
Finally, the user is asked to enter the maximum number of iterations.

![image](https://user-images.githubusercontent.com/83959816/161400131-f9c1e1c8-0932-4db5-a10b-36bea6e5c244.png)

#### Step-6
Points first appear on the terminal screen, and then randomly assigned clusters. 
Cluster information is shown along with how many times the last iteration was 
broken.
![image](https://user-images.githubusercontent.com/83959816/161400140-ad95625d-3cb8-4790-9655-816d287d721a.png)


##### Step-7
Cluster data was visualized using version 4.2.0 of the OpenCV library. This will appear 
on the screen by opening a separate window.
![image](https://user-images.githubusercontent.com/83959816/161400147-912905bd-ca95-4627-ba82-47b2c7dee066.png)







