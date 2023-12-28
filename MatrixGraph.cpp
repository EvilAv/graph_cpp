#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int size)
    : adjacencyLists(size) {
}

MatrixGraph::MatrixGraph(const IGraph& graph)
    : adjacencyLists(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); i++)
        adjacencyLists[i] = graph.GetNextVertices(i);
}

MatrixGraph::~MatrixGraph() {
}

void MatrixGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < adjacencyLists.size());
    assert(0 <= to && to < adjacencyLists.size());
    adjacencyLists[from].push_back(to);
}

int MatrixGraph::VerticesCount() const {
    return static_cast<int>(adjacencyLists.size());
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacencyLists.size());
    return adjacencyLists[vertex];
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacencyLists.size());
    std::vector<int> prevVertices;

    for (int from = 0; from < adjacencyLists.size(); from++) {
        for (int to : adjacencyLists[from]) {
            if (to == vertex)
                prevVertices.push_back(from);
        }
    }
    return prevVertices;
}
