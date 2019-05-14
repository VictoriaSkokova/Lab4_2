#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include "../Laboratory4/Dijkstra.h"
#include "../Laboratory4/Dijkstra.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;


namespace DijkstraTests
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Dijkstra_straight)
		{
			Dijkstra dd;
			dd.paths[0] = "SPb;Paris;13;9";
			dd.paths[1] = "Sevastopol;Paris;25;N/A";
			dd.paths[2] = "Sevastopol;SPb;10;16";
			dd.paths[3] = "Praga;SPb;45;30";
			dd.paths[4] = "Praga;Paris;25;20";

			dd.fill_adjacency_list(5);

			Assert::IsTrue(dd.Dijkstra_algorithm("SPb", "Sevastopol") == 16);
		}

		TEST_METHOD(Dijkstra_connected)
		{
			Dijkstra dd;
			dd.paths[0] = "SPb;Paris;13;9";
			dd.paths[1] = "Sevastopol;Paris;25;N/A";
			dd.paths[2] = "Sevastopol;SPb;10;16";
			dd.paths[3] = "Praga;SPb;45;30";
			dd.paths[4] = "Praga;Paris;25;20";

			dd.fill_adjacency_list(5);

			Assert::IsTrue(dd.Dijkstra_algorithm("Praga", "SPb") == 34);
		}

		TEST_METHOD(Dijkstra_not_connected)
		{
			Dijkstra dd;
			dd.paths[0] = "SPb;Paris;13;9";
			dd.paths[1] = "Sevastopol;Paris;25;N/A";
			dd.paths[2] = "Sevastopol;SPb;10;16";
			dd.paths[3] = "Praga;SPb;45;30";
			dd.paths[4] = "Praga;Paris;25;20";

			dd.fill_adjacency_list(5);

			Assert::IsTrue(dd.Dijkstra_algorithm("Praga", "Sevastopol") == 50);
		}

		TEST_METHOD(Dijkstra_without_path)
		{
			Dijkstra dd;
			dd.paths[0] = "SPb;Paris;13;9";
			dd.paths[1] = "Sevastopol;Paris;25;N/A";
			dd.paths[2] = "Sevastopol;SPb;10;16";
			dd.paths[3] = "Praga;SPb;45;30";
			dd.paths[4] = "Praga;Paris;25;20";
			dd.paths[5] = "Munich;Praga;N/A;N/A";

			dd.fill_adjacency_list(6);

			Assert::IsTrue(dd.Dijkstra_algorithm("Munich", "Sevastopol") == 1000000); 
		}

		TEST_METHOD(Dijkstra_final_start_city)
		{
			Dijkstra dd;
			dd.paths[0] = "SPb;Paris;13;9";
			dd.paths[1] = "Sevastopol;Paris;25;N/A";
			dd.paths[2] = "Sevastopol;SPb;10;16";
			dd.paths[3] = "Praga;SPb;45;30";
			dd.paths[4] = "Praga;Paris;25;20";

			dd.fill_adjacency_list(5);

			Assert::IsTrue(dd.Dijkstra_algorithm("SPb", "SPb") == 0);
		}


		TEST_METHOD(Dijkstra_straight_numbers)
		{
			Dijkstra dd;
			dd.paths[0] = "1;2;13;9";
			dd.paths[1] = "3;2;25;N/A";
			dd.paths[2] = "3;1;10;16";
			dd.paths[3] = "4;1;45;30";
			dd.paths[4] = "4;2;25;20";

			dd.fill_adjacency_list(5);

			Assert::IsTrue(dd.Dijkstra_algorithm("1", "3") == 16);
		}

		TEST_METHOD(Dijkstra_connected_numbers)
		{
			Dijkstra dd;
			dd.paths[0] = "1;2;13;9";
			dd.paths[1] = "3;2;25;N/A";
			dd.paths[2] = "3;1;10;16";
			dd.paths[3] = "4;1;45;30";
			dd.paths[4] = "4;2;25;20";

			dd.fill_adjacency_list(5);

			Assert::IsTrue(dd.Dijkstra_algorithm("4", "1") == 34);
		}

		TEST_METHOD(Dijkstra_not_connected_cities_numbers)
		{
			Dijkstra dd;
			dd.paths[0] = "1;2;13;9";
			dd.paths[1] = "3;2;25;N/A";
			dd.paths[2] = "3;1;10;16";
			dd.paths[3] = "4;1;45;30";
			dd.paths[4] = "4;2;25;20";

			dd.fill_adjacency_list(5);

			Assert::IsTrue(dd.Dijkstra_algorithm("4", "3") == 50);
		}

		TEST_METHOD(Dijkstra_without_path_numbers)
		{
			Dijkstra dd;
			dd.paths[0] = "1;2;13;9";
			dd.paths[1] = "3;2;25;N/A";
			dd.paths[2] = "3;1;10;16";
			dd.paths[3] = "4;1;45;30";
			dd.paths[4] = "4;2;25;20";
			dd.paths[5] = "5;4;N/A;N/A";

			dd.fill_adjacency_list(6);

			Assert::IsTrue(dd.Dijkstra_algorithm("5", "3") == 1000000);
		}

		TEST_METHOD(Dijkstra_final_start_city_numbers)
		{
			Dijkstra dd;
			dd.paths[0] = "1;2;13;9";
			dd.paths[1] = "3;2;25;N/A";
			dd.paths[2] = "3;1;10;16";
			dd.paths[3] = "4;1;45;30";
			dd.paths[4] = "4;2;25;20";

			dd.fill_adjacency_list(5);

			Assert::IsTrue(dd.Dijkstra_algorithm("1", "1") == 0);
		}
	};
}