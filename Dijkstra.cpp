#pragma once
#include "Dijkstra.h"
#include <string>

//size_t Dijkstra::read_size()
//{
//	size_t size_file = 0;
//	char *str = new char[1024];
//	ifstream fin;
//	fin.open("paths.txt");
//
//	if (!fin.is_open())
//		return 0;
//	if (fin.peek() == EOF)
//		throw out_of_range("File is empty");
//	else
//	{
//		while (!fin.eof()) {
//			fin.getline(str, 1024, '\n');
//			size_file++;
//		}
//	}
//	delete str;
//	paths = new char[size_file];
//	return size_file;
//
//}

size_t Dijkstra::read_file(string file_name)
{

	ifstream fin;
	fin.open(file_name);

	if (!fin.is_open())
		return 0;
	if (fin.peek() == EOF)
		throw out_of_range("File is empty");
	else
	{
		size_t paths_size = 0;

		while (!fin.eof()) {
			char* buff = new char[50];
			fin.getline(buff, 50);
			if (buff[0] != '\0') {
				paths[paths_size] = buff;
				paths_size++;
			}
		}
		fin.close();
		return paths_size;
	}
}

void Dijkstra::fill_adjacency_list(size_t paths_size)
{

	for (size_t i = 0; i < paths_size; i++)
	{
		string cityName1 = "", cityName2 = "";
		string from1to2 = "", from2to1 = "";
		char* current_line = paths[i];

		size_t buff_index = 0;
		for (; current_line[buff_index] != ';'; buff_index++) //read first city
		{
			cityName1 += current_line[buff_index];
		}
		buff_index++;

		for (; current_line[buff_index] != ';'; buff_index++) //read second city
		{
			cityName2 += current_line[buff_index];
		}
		buff_index++;

		for (; current_line[buff_index] != ';'; buff_index++) 
		{
			from1to2 += current_line[buff_index];
		}
		buff_index++;

		for (; current_line[buff_index] != '\0'; buff_index++) 
		{
			from2to1 += current_line[buff_index];
		}


		if (cities.findNode(cityName1) == nullptr)
		{
			adjacencyNode* newCity = new adjacencyNode;
			newCity->city = adjacencyList.get_size() + 1; 
			adjacencyList.push_back(newCity);
			cities.insert(cityName1, newCity->city);
		}

		if (cities.findNode(cityName2) == nullptr)
		{
			adjacencyNode* newCity = new adjacencyNode;
			newCity->city = adjacencyList.get_size() + 1;
			adjacencyList.push_back(newCity);
			cities.insert(cityName2, newCity->city);
		}

		//adding connected cities
		if (from1to2 != "N/A")
		{
			adjacencyNode* connected = new adjacencyNode;
			connected->city = cities.findNode(cityName2)->value;
			connected->distance = stoi(from1to2);
			adjacencyList.at(cities.findNode(cityName1)->value - 1)->connections.push_back(connected);
		}

		if (from2to1 != "N/A")
		{
			adjacencyNode* connected = new adjacencyNode;
			connected->city = cities.findNode(cityName1)->value;
			connected->distance = stoi(from2to1);
			adjacencyList.at(cities.findNode(cityName2)->value - 1)->connections.push_back(connected);
		}
	}
}

size_t Dijkstra::Dijkstra_algorithm(string start_city_name, string final_city_name)
{
	size_t start_city = cities.findNode(start_city_name)->value;
	size_t final_city = cities.findNode(final_city_name)->value;


	size_t adjlist_size = adjacencyList.get_size();

	size_t* min_distances = new size_t[adjlist_size];
	bool* processed = new bool[adjlist_size];


	for (size_t i = 0; i < adjlist_size; i++)
	{
		if (i + 1 == start_city)
			min_distances[i] = 0; //start city
		else
			min_distances[i] = 1000000;
		processed[i] = false;
	}


	for (size_t i = 0; i < adjlist_size; i++)
	{
		size_t current_min_distance = 1000000, number_of_min_dist;

		for (size_t j = 0; j < adjlist_size; j++)
		{
			if (min_distances[j] <= current_min_distance && !processed[j]) 
			{
				current_min_distance = min_distances[j];
				number_of_min_dist = j;
			}
		}
		processed[number_of_min_dist] = true; 

		LinkedList<adjacencyNode*> connected = adjacencyList.at(number_of_min_dist)->connections; //записываем соседей минимального

		for (size_t j = 0; j < connected.get_size(); j++) 
		{
			adjacencyNode* current_city = connected.at(j);
			if (current_city->distance + min_distances[number_of_min_dist] < min_distances[current_city->city - 1])
				min_distances[current_city->city - 1] = current_city->distance + min_distances[number_of_min_dist];
		}
	}


	delete[] processed;

	size_t result = min_distances[final_city - 1];
	delete[] min_distances;

	return result;
}