//
// Created by Andrew Kireev on 19.12.2020.
//

#ifndef TP_ALGORITHMS_IGRAPH_H
#define TP_ALGORITHMS_IGRAPH_H

#include <vector>

struct IGraph {
	virtual ~IGraph() {}

	// Добавление ребра от from к to.
	virtual void AddEdge(int from, int to) = 0;

	virtual int VerticesCount() const  = 0;

	virtual std::vector<int> GetNextVertices(int vertex) const = 0;
	virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

#endif //TP_ALGORITHMS_IGRAPH_H
