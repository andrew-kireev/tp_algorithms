//
// Created by Andrew Kireev on 19.12.2020.
//

#ifndef TP_ALGORITHMS_MATRIXGRAPH_H
#define TP_ALGORITHMS_MATRIXGRAPH_H

#include "IGraph.h"

class MatrixGraph : public IGraph {
public:

	explicit MatrixGraph(size_t verticesCount);

	explicit MatrixGraph(const IGraph& graph);

	void AddEdge(int from, int to) override;


	int VerticesCount() const override;

	std::vector<int> GetNextVertices(int vertex) const  override;

	std::vector<int> GetPrevVertices(int vertex) const override;


private:
	std::vector<std::vector<int>> graph_;
};

#endif //TP_ALGORITHMS_MATRIXGRAPH_H
