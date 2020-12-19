//
// Created by Andrew Kireev on 19.12.2020.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"



void dfs_aux(const IGraph& graph, int vertex, std::vector<bool>& visited,
			 std::function<void(int)>& callback) {
	visited[vertex] = true;
	callback(vertex);

	for (auto child : graph.GetNextVertices(vertex)) {
		if (!visited[child]) {
			dfs_aux(graph, child, visited, callback);
		}
	}
}

void dfs(const IGraph& graph, std::function<void(int)> callback) {
	std::vector<bool> visited;
	visited.resize(graph.VerticesCount(), false);

	for (int i = 0; i < graph.VerticesCount(); ++i) {
		if (!visited[i]) {
			dfs_aux(graph, i, visited, callback);
		}
	}
}

void bfs(const IGraph& graph, void (*callback)(int v)) {
	std::vector<bool> visited;
	std::queue<int> queue;
	visited.resize(graph.VerticesCount(), false);
	for (int i = 0; i < graph.VerticesCount(); ++i) {
		if (!visited[i]) {
			queue.push(i);
			visited[i] = true;
			while (!queue.empty()) {
				int vertex = queue.front();
				queue.pop();
				callback(vertex);
				for (auto child : graph.GetNextVertices(vertex)) {
					if (!visited[child]) {
						queue.push(child);
						visited[child] = true;
					}
				}
			}
		}
	}

}

int main() {
	ListGraph graph(6);

	graph.AddEdge(0, 1);
	graph.AddEdge(1, 2);
	graph.AddEdge(1, 5);
	graph.AddEdge(2, 3);
	graph.AddEdge(3, 4);
	graph.AddEdge(4, 2);


	auto callback = [](int v) {
		std::cout << v << " ";
	};

	std::cout << "------------------------" << std::endl;
	std::cout << "List Graph size = " <<  graph.VerticesCount() << std::endl;
	dfs(graph, callback);

	std::cout << std::endl << "------------------------" << std::endl;
	MatrixGraph matrix_graph(graph);
	std::cout << "Matrix graph  size = " <<  matrix_graph.VerticesCount() << std::endl;

	dfs(matrix_graph, callback);

	std::cout << std::endl << "------------------------" << std::endl;
	SetGraph set_graph(matrix_graph);
	std::cout << "Set graph  size = " <<  set_graph.VerticesCount() << std::endl;

	dfs(set_graph, callback);

	std::cout << std::endl << "------------------------" << std::endl;
	ArcGraph arc_graph(set_graph);
	std::cout << "Arc graph  size = " <<  arc_graph.VerticesCount() << std::endl;

	dfs(arc_graph, callback);

	return 0;
}

