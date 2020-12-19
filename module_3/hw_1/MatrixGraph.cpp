//
// Created by Andrew Kireev on 19.12.2020.
//

#include "MatrixGraph.h"


MatrixGraph::MatrixGraph(size_t verticesCount) :
graph_(verticesCount, std::vector<int>(verticesCount, 0)) { }

MatrixGraph::MatrixGraph(const IGraph& graph) : graph_(graph.VerticesCount(),
												   std::vector<int>(graph.VerticesCount(), 0)) {
	for (size_t i = 0; i != graph.VerticesCount(); ++i) {
		std::vector<int> verticals = graph.GetNextVertices(i);
		for (int elem : verticals) {
			graph_[i][elem] = 1;
		}
	}
}

void MatrixGraph::AddEdge(int from, int to) {
	graph_[from][to] = 1;
}


int MatrixGraph::VerticesCount() const {
	return graph_.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
	std::vector<int> result;

	for (size_t i = 0; i != graph_[vertex].size(); ++i) {
		if (graph_[vertex][i] == 1)
			result.push_back(i);
	}
	return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
	std::vector<int> result;

	for (size_t i = 0; i != graph_.size(); ++i) {
		if (graph_[i][vertex] == 1)
			result.push_back(i);
	}
	return result;
}
