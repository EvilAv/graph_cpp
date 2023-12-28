#include <iostream>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"
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


    std::cout << std::endl << "Origin ListGraph with " << l_graph.VerticesCount() << " vertices" << std::endl;
    mainBFS(l_graph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;
    mainDFS(l_graph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;

    ListGraph l_graph2(l_graph);
    std::cout << std::endl << "Copy ListGraph with " << l_graph2.VerticesCount() << " vertices" << std::endl;
    mainBFS(l_graph2, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;
    mainDFS(l_graph2, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;

    ArcGraph a_graph(l_graph2);
    std::cout << std::endl << "ArcGraphh with " << a_graph.VerticesCount() << " vertices" << std::endl;
    mainBFS(a_graph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;
    mainDFS(a_graph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;

    MatrixGraph m_graph(a_graph);
    std::cout << std::endl << "MatrixGraphh with " << m_graph.VerticesCount() << " vertices" << std::endl;
    mainBFS(m_graph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;
    mainDFS(m_graph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;

    SetGraph s_graph(m_graph);
    std::cout << std::endl << "SetGraphh with " << s_graph.VerticesCount() << " vertices" << std::endl;
    mainBFS(s_graph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;
    mainDFS(s_graph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;

    // ArcGraph arcGraph(listGraph);
    // Продемонстрировать, что число вершин не изменилось. Сделать BFS, DFS.
    // MatrixGraph matrixGraph(arcGraph); +
    // SetGraph setGraph(matrixGraph);
}
