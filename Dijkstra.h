#pragma once
#include <fstream>
#include <iostream>
#include "Map.h"
#include "Map.cpp"
#include "LinkedList.h"
#include <string>
using namespace std;

class Dijkstra;

struct adjacencyNode
{
	size_t city;
	size_t distance;
	LinkedList<adjacencyNode*> connections;

	friend Dijkstra;

	adjacencyNode()
	{
		city = 0;
		distance = 0;
	};
};

class Dijkstra
{
	LinkedList<adjacencyNode*> adjacencyList;

	Map<string, size_t> cities;

public:

	size_t Dijkstra_algorithm(string start_city_name, string final_city_name);

	void fill_adjacency_list(size_t paths_size);

	size_t read_file(string file_name);
	//size_t read_size();

	char* paths[100];

	~Dijkstra()
	{
		adjacencyList.clear();
		cities.~Map();
	};
};