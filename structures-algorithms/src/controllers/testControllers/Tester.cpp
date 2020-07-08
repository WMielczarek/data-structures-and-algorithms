#include "stdafx.h"
#include "Tester.h"
#include "structures\utilities\disjoinSet\DisjoinSet.h"
#include "alghoritms\DjikstraAlghoritm\DjikstraAlghoritm.h"
#include "alghoritms\bfAlghoritm\bfAlghoritm.h"
#include "alghoritms\fordFulkersonAlghoritm\FordFulkersonAlghoritm.h"
#include "alghoritms\kruskalAlghoritm\KruskalAlghoiritm.h"
#include "alghoritms\primAlghoritm\PrimAlghoritm.h"

using namespace std;

void Tester::runAllTests()
{
	cout << "Shortest path problem started" << endl;
	sppTests();
	cout << "Shortest path problem ended" << endl;

	cout << "Minimal spining tree problem started" << endl;
	mstTests();
	cout << "Minimal spining tree problem ended" << endl;

	cout << "Maximum flow problem started" << endl;
	flowTests();
	cout << "Maximum flow problem ended" << endl;
}

void Tester::sppTests()
{
	cout << "Testing Djikstra alghoritm" << endl;
	djikstraTest();
	cout << "Testing Bellman-Ford alghoritm" << endl;
	bfTest();
}

void Tester::djikstraTest()
{
	MatrixGraph m;

	DjikstraAlghoritm djAlg;
	int vertexCountIndex = 0;
	
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;
	int totalTime = 0;
	
	cout << "Matrix testing" << endl;
	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;
		
		filename = "Djikstra-matrix-" + to_string(densityTable[densityIndex]) + "-" + ".csv";
		// Clearing the file
		std::ofstream ofs;
		ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
		ofs.close();

		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			totalTime = 0;
			
			for (int i = 0; i < 100; i++)
			{
				m.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, true);
				djAlg.prepare(&m);

				startTime = chrono::high_resolution_clock::now();
				djAlg.apply(&m);
				endTime = chrono::high_resolution_clock::now();

				totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

				cout << "Progress: " << i * 100 / 100 << "\r";
			}
			cout << endl;
			saveToFile(vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}

	cout << "List testing" << endl;
	ListGraph l;

	cout << "Matrix testing" << endl;
	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;

		filename = "Djikstra-list-" + to_string(densityTable[densityIndex]) + "-" + ".csv";

		// Clearing the file
		std::ofstream ofs;
		ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
		ofs.close();

		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			totalTime = 0;
			
			for (int i = 0; i < 100; i++)
			{
				l.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, true);
				djAlg.prepare(&l);

				startTime = chrono::high_resolution_clock::now();
				djAlg.apply(&l);
				endTime = chrono::high_resolution_clock::now();

				totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

				cout << "Progress: " << i * 100 / 100 << "\r";
			}
			cout << endl;
			saveToFile(vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}
}

void Tester::bfTest()
{
	MatrixGraph m;

	bfAlghoritm Alg;
	int vertexCountIndex = 0;

	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;
	int totalTime = 0;

	cout << "Matrix testing" << endl;
	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;

		filename = "BellmanFord-matrix-" + to_string(densityTable[densityIndex]) + "-" + ".csv";

		// Clearing the file
		std::ofstream ofs;
		ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
		ofs.close();

		
		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			totalTime = 0;

			for (int i = 0; i < 100; i++)
			{
				m.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, true);
				Alg.prepare(&m);

				startTime = chrono::high_resolution_clock::now();
				Alg.apply(&m);
				endTime = chrono::high_resolution_clock::now();

				totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

				cout << "Progress: " << i * 100 / 100 << "\r";
			}
			cout << endl;
			saveToFile(vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}

	cout << "List testing" << endl;
	ListGraph l;

	cout << "Matrix testing" << endl;
	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;

		filename = "BellmanFord-list-" + to_string(densityTable[densityIndex]) + ".csv";

		// Clearing the file
		std::ofstream ofs;
		ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
		ofs.close();

		
		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			totalTime = 0;

			for (int i = 0; i < 100; i++)
			{
				l.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, true);
				Alg.prepare(&l);

				startTime = chrono::high_resolution_clock::now();
				Alg.apply(&l);
				endTime = chrono::high_resolution_clock::now();

				totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

				cout << "Progress: " << i * 100 / 100 << "\r";
			}
			cout << endl;
			saveToFile(vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}
}

void Tester::mstTests()
{
	cout << "Testing Kruskal alghoritm" << endl;
	kruskalTest();
	cout << "Testing Prim alghoritm" << endl;
	primTest();
}

void Tester::kruskalTest()
{
	MatrixGraph m;

	KruskalAlghoiritm Alg;
	int vertexCountIndex = 0;

	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;
	int totalTime = 0;

	cout << "Matrix testing" << endl;
	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;

		filename = "Kruskal-matrix-" + to_string(densityTable[densityIndex]) + ".csv";

		// Clearing the file
		std::ofstream ofs;
		ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
		ofs.close();
		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			totalTime = 0;


			for (int i = 0; i < 100; i++)
			{
				m.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, true);
				Alg.prepare(&m);

				startTime = chrono::high_resolution_clock::now();
				Alg.apply(&m);
				endTime = chrono::high_resolution_clock::now();

				totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

				cout << "Progress: " << i * 100 / 100 << "\r";
			}
			cout << endl;
			saveToFile(vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}

	cout << "List testing" << endl;
	ListGraph l;

	cout << "Matrix testing" << endl;
	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;

		filename = "Kruskal-list-" + to_string(densityTable[densityIndex]) + ".csv";

		// Clearing the file
		std::ofstream ofs;
		ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
		ofs.close();
		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			totalTime = 0;


			for (int i = 0; i < 100; i++)
			{
				l.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, true);
				Alg.prepare(&l);

				startTime = chrono::high_resolution_clock::now();
				Alg.apply(&l);
				endTime = chrono::high_resolution_clock::now();

				totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

				cout << "Progress: " << i * 100 / 100 << "\r";
			}
			cout << endl;
			saveToFile(vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}
}

void Tester::primTest()
{
	MatrixGraph m;

	PrimAlghoritm Alg;
	int vertexCountIndex = 0;

	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;
	int totalTime = 0;

	cout << "Matrix testing" << endl;
	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;

		filename = "Prim-matrix-" + to_string(densityTable[densityIndex]) + ".csv";

		// Clearing the file
		std::ofstream ofs;
		ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
		ofs.close();
		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			totalTime = 0;


			for (int i = 0; i < 100; i++)
			{
				m.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, true);
				Alg.prepare(&m);

				startTime = chrono::high_resolution_clock::now();
				Alg.apply(&m);
				endTime = chrono::high_resolution_clock::now();

				totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

				cout << "Progress: " << i * 100 / 100 << "\r";
			}
			cout << endl;
			saveToFile(vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}

	cout << "List testing" << endl;
	ListGraph l;

	cout << "Matrix testing" << endl;
	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;

		filename = "Prim-list-" + to_string(densityTable[densityIndex]) + ".csv";

		// Clearing the file
		std::ofstream ofs;
		ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
		ofs.close();


		
		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			totalTime = 0;
			for (int i = 0; i < 100; i++)
			{
				l.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, true);
				Alg.prepare(&l);

				startTime = chrono::high_resolution_clock::now();
				Alg.apply(&l);
				endTime = chrono::high_resolution_clock::now();

				totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

				cout << "Progress: " << i * 100 / 100 << "\r";
			}
			cout << endl;
			saveToFile(vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}
}



void Tester::flowTests()
{
	cout << "Ford - Fulkerson alghoritm with BFS seach testing" << endl;
	ffBFSTest();
	cout << "Ford - Fulkerson alghoritm with DFS seach testing" << endl;
	ffDFSTest();
}

void Tester::ffDFSTest()
{
	MatrixGraph m;

	FordFulkersonAlghoritm Alg;
	Alg.setMode(true);
	int vertexCountIndex = 0;

	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;
	int totalTime = 0;

	cout << "Matrix testing" << endl;
	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;

		
		filename = "ff-DFS-matrix-" + to_string(densityTable[densityIndex]) + ".csv";

		// Clearing the file
		std::ofstream ofs;
		ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
		ofs.close();

		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			Alg.setParameters(0, vertexCountTable[vertexCountIndex] - 1);
			totalTime = 0;

			for (int i = 0; i < 100; i++)
			{
				m.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, true);
				Alg.prepare(&m);

				startTime = chrono::high_resolution_clock::now();
				Alg.apply(&m);
				endTime = chrono::high_resolution_clock::now();

				totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

				cout << "Progress: " << i * 100 / 100 << "\r";
			}
			cout << endl;
			saveToFile(vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}

	cout << "List testing" << endl;
	ListGraph l;

	cout << "Matrix testing" << endl;
	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;
		filename = "ff-DFS-list-" + to_string(densityTable[densityIndex]) + ".csv";

		// Clearing the file
		std::ofstream ofs;
		ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
		ofs.close();


		
		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			Alg.setParameters(0, vertexCountTable[vertexCountIndex] - 1);
			totalTime = 0;

			for (int i = 0; i < 100; i++)
			{
				l.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, true);
				Alg.prepare(&l);

				startTime = chrono::high_resolution_clock::now();
				Alg.apply(&l);
				endTime = chrono::high_resolution_clock::now();

				totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

				cout << "Progress: " << i * 100 / 100 << "\r";
			}
			cout << endl;
			saveToFile(vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}
}

void Tester::ffBFSTest()
{
	MatrixGraph m;

	FordFulkersonAlghoritm Alg;
	Alg.setMode(false);
	int vertexCountIndex = 0;

	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;
	int totalTime = 0;

	cout << "Matrix testing" << endl;
	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;



		filename = "Prim-matrix-" + to_string(densityTable[densityIndex]) + ".csv";

		// Clearing the file
		std::ofstream ofs;
		ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
		ofs.close();

		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			Alg.setParameters(0, vertexCountTable[vertexCountIndex] - 1);
			totalTime = 0;
			for (int i = 0; i < 100; i++)
			{
				m.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, true);
				Alg.prepare(&m);

				startTime = chrono::high_resolution_clock::now();
				Alg.apply(&m);
				endTime = chrono::high_resolution_clock::now();

				totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

				cout << "Progress: " << i * 100 / 100 << "\r";
			}
			cout << endl;
			saveToFile(vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}

	cout << "List testing" << endl;
	ListGraph l;

	cout << "Matrix testing" << endl;
	for (int densityIndex = 0; densityIndex < densityArraySize; densityIndex++)
	{
		cout << "Density: " << densityTable[densityIndex] << endl;

		
		filename = "Prim-list-" + to_string(densityTable[densityIndex]) + ".csv";

		// Clearing the file
		std::ofstream ofs;
		ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
		ofs.close();
		for (int vertexCountIndex = 0; vertexCountIndex < vertexArraySize; vertexCountIndex++)
		{
			cout << "Vertex count: " << vertexCountTable[vertexCountIndex] << endl;
			Alg.setParameters(0, vertexCountTable[vertexCountIndex] - 1);
			totalTime = 0;


			for (int i = 0; i < 100; i++)
			{
				l.generate(densityTable[densityIndex], vertexCountTable[vertexCountIndex], valueRange, valueBase, true);
				Alg.prepare(&l);

				startTime = chrono::high_resolution_clock::now();
				Alg.apply(&l);
				endTime = chrono::high_resolution_clock::now();

				totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

				cout << "Progress: " << i * 100 / 100 << "\r";
			}
			cout << endl;
			saveToFile(vertexCountTable[vertexCountIndex], totalTime / 100);
		}
	}
}

