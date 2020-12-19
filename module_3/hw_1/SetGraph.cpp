//
// Created by Andrew Kireev on 19.12.2020.
//

#include "SetGraph.h"


SetGraph::SetGraph(size_t verticesCount) : graph_(verticesCount) { }

SetGraph::SetGraph(const IGraph& graph) {
	graph_.resize(graph.VerticesCount());
	for (size_t i = 0; i != graph.VerticesCount(); ++i) {
		std::vector<int> vertices = graph.GetNextVertices(i);
		graph_[i].insert(vertices.begin(), vertices.end());
	}
}

void SetGraph::AddEdge(int from, int to) {
	graph_[from].insert(to);
}


int SetGraph::VerticesCount() const {
	return graph_.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
	std::vector<int> result;

	for (int vertical : graph_[vertex])
		result.push_back(vertical);
	return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
	std::vector<int> result;
	for (size_t i = 0; i < graph_.size(); ++i) {
		for (int child : graph_[i]) {
			if (child == vertex) {
				result.push_back(i);
				break;
			}
		}
	}
	return result;
}