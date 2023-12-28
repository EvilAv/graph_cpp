#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int size)
    : matrix(size, std::vector<bool>(size, false)) {
}

MatrixGraph::MatrixGraph(const IGraph& graph)
    : matrix(graph.VerticesCount(), std::vector<bool>(graph.VerticesCount(), false)) {
    for (int i = 0; i < graph.VerticesCount(); i++) {

        for (int cell : graph.GetNextVertices(i)) {
            matrix[i][cell] = true;
        }
    }
}

MatrixGraph::~MatrixGraph() {
}

void MatrixGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < matrix.size());
    assert(0 <= to && to < matrix.size());
    matrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return static_cast<int>(matrix.size());
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < matrix.size());
    std::vector<int> res;
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[vertex][i]) {
            res.push_back(i);
        }
    }
    return res;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < matrix.size());
    std::vector<int> res;
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][vertex]) {
            res.push_back(i);
        }
    }
    return res;
}
