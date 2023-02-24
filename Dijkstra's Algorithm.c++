#include <climits>
#include <iostream>
#include <fstream>
using namespace std;



const int V = 9;
// Function to print shortest path from source to j
// using parent array
void printPath(int parent[], int j) {
    char str = 65 + j;
    // Base Case : If j is source
    if (parent[j] == -1) {
        cout << str << " ";
        return;
    }

    printPath(parent, parent[j]);

    // printf("%d ", j);
    cout << str << " ";
}

int miniDist(int distance[], bool Tset[]) // finding minimum distance
{
    int minimum = INT_MAX, ind;

    for (int k = 0; k < V; k++) {
        if (Tset[k] == false && distance[k] <= minimum) {
            minimum = distance[k];
            ind = k;
        }
    }
    return ind;
}

void DijkstraAlgo(int graph[V][V], int src, int goal) // adjacency matrix
{
    int distance[V]; // array to calculate the minimum distance for each node
    bool Tset[V];    // boolean array to mark visited and unvisited for each node
    int parent[V];   // Parent array to store shortest path tree
                   // Value of parent[v] for a vertex v stores parent vertex of v
                   // in shortest path tree.

    for (int k = 0; k < V; k++) {
        distance[k] = INT_MAX;
        Tset[k] = false;
    }
    parent[src] = -1;  // Parent of root (or source vertex) is -1.
    distance[src] = 0; // Source vertex distance is set 0

    for (int k = 0; k < V; k++) {
        int m = miniDist(distance, Tset);
        Tset[m] = true;
        for (int k = 0; k < V; k++) {
            // updating the distance of neighbouring vertex
            if (!Tset[k] && graph[m][k] && distance[m] != INT_MAX &&
                distance[m] + graph[m][k] < distance[k]) {
                distance[k] = distance[m] + graph[m][k];
                parent[k] = m;
            }
        }
    }
    cout << "Vertex\t\tDistance from source vertex\t\t Path" << endl;
        char str = 65 + goal;
        // cout<<str<<"\t\t\t"<<distance[k]<<endl;
        cout << str << "\t\t\t" << distance[goal] << "\t\t\t\t\t\t\t\t";
        printPath(parent, goal);
        cout << endl;
    
}

int main() {
    /*int graph[V][V]={
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}};*/
    /*    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},  {4, 0, 8, 0, 0, 0, 0, 11, 0},
                           {0, 8, 0, 7, 0, 4, 0, 0, 2},  {0, 0, 7, 0, 9, 14, 0, 0, 0},
                           {0, 0, 0, 9, 0, 10, 0, 0, 0}, {0, 0, 4, 0, 10, 0, 2, 0, 0},
                           {0, 0, 0, 14, 0, 2, 0, 1, 6}, {8, 11, 0, 0, 0, 0, 1, 0, 7},
                           {0, 0, 2, 0, 0, 0, 6, 7, 0} };
    */
         
   
    int graph[V][V];

    string fileName, node, Enode;

    char startnode;
    char endnode;


    cout << "Enter file name: ";
    cin >> fileName;

    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        cout << "Error opening File";
        return -1;
        exit;
    }

    for (int i = 0; i < V; i++) {
        for (int r = 0; r < V; r++) {
            inputFile >> graph[i][r];
        }
    }
   
    // Test the file was read correctly
    /*
    for (int i = 0; i < V; i++) {
        for (int r = 0; r < V; r++) {
            cout << graph[i][r] << "\t";
        }
    }
    */
    cout<<endl;
    cout << "Nodes: A, B, C, D, E, F, G, H, I \n";
    cout << "Enter starting node: ";
    cin >> startnode;
    cout << "Enter ending node: ";
    cin >> endnode;
    cout<<endl;
   

   
int endnodeInt=(int)endnode-65;
    //////////////////////
int startnodeInt=(int)startnode-65;


DijkstraAlgo(graph,startnodeInt,endnodeInt);


    return 0;
}
