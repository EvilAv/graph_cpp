#include "ArcGraph.h"

ArcGraph::ArcGraph(int size)
    : v_count(size) {
}

ArcGraph::ArcGraph(const IGraph& graph)
    : v_count(graph.VerticesCount()) {
    for (int from = 0; from < graph.VerticesCount(); from++) {

        for (int to : graph.GetNextVertices(from)) {
            std::pair<int, int> p(from, to);
            edges.push_back(p);
        }
    }
}

ArcGraph::~ArcGraph() {
}

void ArcGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < v_count);
    assert(0 <= to && to < v_count);
    std::pair<int, int> p(from, to);
    edges.push_back(p);
}

int ArcGraph::VerticesCount() const {
    return v_count;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < v_count);
    std::vector<int> res;
    for (int i = 0; i < edges.size(); i++) {
        if (edges[i].first == vertex) {
            res.push_back(edges[i].second);
        }
    }
    return res;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < v_count);
    std::vector<int> res;
    for (int i = 0; i < edges.size(); i++) {
        if (edges[i].second == vertex) {
            res.push_back(edges[i].first);
        }
    }
    return res;
}
