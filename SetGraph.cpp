#include "SetGraph.h"

SetGraph::SetGraph(int size)
    : set_list(size) {
}

SetGraph::SetGraph(const IGraph& graph)
    : set_list(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); i++) {

        for (int cell : graph.GetNextVertices(i)) {
            set_list[i].insert(cell);
        }
    }
}

SetGraph::~SetGraph() {
}

void SetGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < set_list.size());
    assert(0 <= to && to < set_list.size());
    set_list[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return static_cast<int>(set_list.size());
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < set_list.size());
    std::vector<int> res;
    res.insert(res.end(), set_list[vertex].begin(), set_list[vertex].end());
    return res;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < set_list.size());
    std::vector<int> res;
    for (int i = 0; i < set_list.size(); i++) {

        if (set_list[i].find(vertex) != set_list[i].end()) {
            res.push_back(i);
        }
    }
    return res;
}
