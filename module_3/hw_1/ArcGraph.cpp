//
// Created by Andrew Kireev on 19.12.2020.
//

#include "ArcGraph.h"

ArcGraph::ArcGraph(size_t verticesCount) : graph_(verticesCount) { }

ArcGraph::ArcGraph(const IGraph& graph) {
	for (size_t i = 0; i != graph.VerticesCount(); ++i) {
		std::vector<int> vertices = graph.GetNextVertices(i);
		for (int elem : vertices) {
			graph_.emplace_back(std::make_pair(i, elem));
		}
	}
}

void ArcGraph::AddEdge(int from, int to) {
	graph_.emplace_back(std::make_pair(from, to));
}


int ArcGraph::VerticesCount() const {
	return graph_.size();
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
	std::vector<int> result;

	for (auto& edge : graph_) {
		if (edge.first == vertex)
			result.push_back(edge.second);
	}

	return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
	std::vector<int> result;

	for (auto& edge : graph_) {
		if (edge.second == vertex)
			result.push_back(edge.first);
	}

	return result;
}