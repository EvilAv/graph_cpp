#include <iostream>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "Utils.h"

int main()
{
    ListGraph l_graph(7);
    l_graph.AddEdge(0, 1);
    l_graph.AddEdge(0, 5);
    l_graph.AddEdge(1, 2);
    l_graph.AddEdge(1, 3);
    l_graph.AddEdge(1, 5);
    l_graph.AddEdge(1, 6);
    l_graph.AddEdge(3, 2);
    l_graph.AddEdge(3, 4);
    l_graph.AddEdge(3, 6);
    l_graph.AddEdge(5, 4);
    l_graph.AddEdge(5, 6);
    l_graph.AddEdge(6, 4);


    std::cout << std::endl << "Origin ListGraph" << std::endl;
    mainBFS(l_graph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;
    mainDFS(l_graph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;

    ListGraph l_graph2(l_graph);
    std::cout << std::endl << "Copy ListGraph" << std::endl;
    mainBFS(l_graph2, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;
    mainDFS(l_graph2, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;

    MatrixGraph m_graph(l_graph);
    std::cout << std::endl << "MatrixGraph" << std::endl;
    mainBFS(m_graph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;
    mainDFS(m_graph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;

    // ArcGraph arcGraph(listGraph);
    // Продемонстрировать, что число вершин не изменилось. Сделать BFS, DFS.
    // MatrixGraph matrixGraph(arcGraph);
    // SetGraph setGraph(matrixGraph);
}
