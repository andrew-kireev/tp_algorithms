//
// Created by Andrew Kireev on 19.12.2020.
//

#ifndef TP_ALGORITHMS_SETGRAPH_H
#define TP_ALGORITHMS_SETGRAPH_H

#include <set>

#include "IGraph.h"

class SetGraph : public IGraph {
public:

	explicit SetGraph(size_t verticesCount);

	explicit SetGraph(const IGraph& graph);

	void AddEdge(int from, int to) override;


	int VerticesCount() const override;

	std::vector<int> GetNextVertices(int vertex) const override;

	std::vector<int> GetPrevVertices(int vertex) const override;


private:
	std::vector<std::set<int>> graph_;
};

#endif //TP_ALGORITHMS_SETGRAPH_H
