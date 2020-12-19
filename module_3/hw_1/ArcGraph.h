//
// Created by Andrew Kireev on 19.12.2020.
//

#ifndef TP_ALGORITHMS_ARCGRAPH_H
#define TP_ALGORITHMS_ARCGRAPH_H

#include <IGraph.h>

class ArcGraph : public IGraph {
public:

	explicit ArcGraph(size_t verticesCount);

	explicit ArcGraph(const IGraph& graph);

	void AddEdge(int from, int to) override;


	int VerticesCount() const override;

	std::vector<int> GetNextVertices(int vertex) const  override;

	std::vector<int> GetPrevVertices(int vertex) const override;


private:
	std::vector<std::pair<int, int>> graph_;
};

#endif //TP_ALGORITHMS_ARCGRAPH_H
