#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// A graph should be seen as a data structure having two components....set of vertices...and ordered pair of nodes called edges
// The edges may be weighted
// Two common representations of Graphs are Adjcency Matrix and Adjcency list

// 1. Adjacency Matrix: A matrix of V * V where V is no. of vertices and if any edge exists between (i,j) M[i][j]=1 else 0
int **Graph_Matrix()
{ // Function that will return an Adjancy matrix
	int v, m;
	cout << "Enter no. of vertices: ";
	cin >> v;
	cout << "Enter no. of edges: ";
	cin >> m;
	// Several ways to create a 2D array...Dynamic allocation because i want to return it form the function
	int **Adj_Matrix = new int *[v]; // Array of pointers
	for (int i = 0; i < v; i++)
	{
		Adj_Matrix[i] = new int[v]; // Each pointer points to an array
	}
	// Another way couled have been....new int[m*n]....m rows and n columns....access could be.... *(arr+i*n+j)= x here i is denoting row
	for (int i = 0; i < m; i++)
	{
		int p, q;
		cout << "Enter the ordered pair of edge: ";
		cin >> p >> q;
		Adj_Matrix[p][q] = 1;
	}
	return Adj_Matrix;
}

// Adjcency list: An array of lists is used.. where all the neighbour of 1 node is linked
// 0->1->4
// 1->0->4->2->3
void Add_Edge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Display_Graph(vector<int> adj[], int V)
{
	for (int i = 0; i < V; i++)
	{
		cout << "Adjcency list of vertex i is: " << i << "\n head: ";
		for (auto x : adj[i])
		{
			cout << "->" << x;
		}
		cout << endl;
	}
}

int main()
{
	int V;
	cout << "Enter no. of vertices: ";
	cin >> V;
	vector<int> adj[V]; // This defines an array of vectors...i.e adj[0],adj[1]....adj[V-1] all are vectors
	Add_Edge(adj, 0, 1);
	Add_Edge(adj, 0, 4);
	Add_Edge(adj, 1, 2);
	Add_Edge(adj, 1, 3);
	Add_Edge(adj, 1, 4);
	Add_Edge(adj, 2, 3);
	Add_Edge(adj, 3, 4);
	Display_Graph(adj, V);
	return 0;
}