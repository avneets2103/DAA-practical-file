// travelling salesman problem
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define V 4 // Total no of cities

int TSP(int Adj_matrix[][V], int s)
{
	// Store all cities apart from the source city in a vector.
	vector<int> cities;
	for (int i = 0; i < V; i++)
	if (i != s)
	cities.push_back(i);

	int min_distance = INT32_MAX;
	do 
	{
		// Taking starting Path distance as zero
		int curr_distance = 0;

		// compute current path distance
		int k = s;
		for (int i = 0; i < cities.size(); i++)
       		{
		curr_distance += Adj_matrix[k][cities[i]];
		k = cities[i];
		}
		curr_distance += Adj_matrix[k][s];

		// update minimum
		min_distance = min(min_distance, curr_distance);

	}
	//using following permutation method of C++
   	while(next_permutation(cities.begin(), cities.end()));
	return min_distance;
}

int main()
{
	//The adjacent matrix of the graph given:
	int matrix[][V] = { { 0, 10, 15, 20 },{ 10, 0, 35, 25 },{ 15, 35, 0, 30 },{ 20, 25, 30, 0 } };
	int start = 0;
	cout <<"The minimum cost is: "<<TSP(matrix, start) << endl;
	return 0;
}