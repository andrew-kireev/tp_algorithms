//
// Created by Andrew Kireev on 19.12.2020.
//

#ifndef TP_ALGORITHMS_LISTGRAPH_H
#define TP_ALGORITHMS_LISTGRAPH_H

#include "IGraph.h"

class ListGraph : public IGraph {
public:
	explicit ListGraph(size_t verticesCount);

	explicit ListGraph(const IGraph& graph);

	virtual ~ListGraph() = default;

	// Добавление ребра от from к to.
	void AddEdge(int from, int to);

	int VerticesCount() const override;

	std::vector<int> GetNextVertices(int vertex) const;

	std::vector<int> GetPrevVertices(int vertex) const override;

private:
	std::vector<std::vector<int> > graph_;
};

#endif //TP_ALGORITHMS_LISTGRAPH_H
