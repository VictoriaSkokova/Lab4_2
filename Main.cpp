#include <fstream>
#include <iostream>
#include "Dijkstra.h"
using namespace std;

int main()
{
	Dijkstra distance;
	distance.fill_adjacency_list(distance.read_file("paths.txt"));
	cout << "Hello \n";
	cout << "It's the fourth laboratory work made by Victoria Skokova\n";
	string start_city = "Sevastopol", final_city = "SPb";

	cout << "We travel from " << start_city << " to " << final_city << "\n";
	cout << "And the minimal cost of our travelling is " << distance.Dijkstra_algorithm(start_city, final_city) << endl;

	distance.~Dijkstra();
	system("pause");
	return 0;
}