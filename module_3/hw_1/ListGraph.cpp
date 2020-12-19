//
// Created by Andrew Kireev on 19.12.2020.
//

#include "ListGraph.h"


ListGraph::ListGraph(size_t verticesCount) : graph_(verticesCount) {}

ListGraph::ListGraph(const IGraph& graph) {
	for (size_t i = 0; i != graph.VerticesCount(); ++i) {
		graph_[i] = graph.GetNextVertices(i);
	}
}

void ListGraph::AddEdge(int from, int to) {
	graph_[from].push_back(to);
}

int ListGraph::VerticesCount() const {
	return graph_.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
	return  graph_[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
	std::vector<int> result;
	for (size_t i = 0; i < graph_.size(); ++i) {
		for (auto child : graph_[i]) {
			if (child == vertex) {
				result.push_back(i);
				break;
			}
		}
	}
	return result;
}