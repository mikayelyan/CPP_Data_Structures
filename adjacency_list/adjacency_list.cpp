#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

class Adjacency_vector
{
    int size{};
    std::vector<std::vector<int>> graph;

public:
    void add_vertex()
    {
        std::vector<int> vertex;
        graph.push_back(vertex);
    }
    void remove_vertex(int vertex)
    {
        for (size_t i{}; i < graph.size(); ++i)
        {
            auto it = std::find(graph[i].begin(), graph[i].end(), vertex);
            graph[i].erase(it);
        }
        graph.erase(std::next(graph.begin(), vertex - 1), std::next(graph.begin(), vertex));
    }
    void print_vertex()
    {
        for (size_t i{}; i < graph.size(); ++i)
        {
            std::cout << "[ " << i << (graph[i].empty() ? " " : " -> ");

            for (auto edge : graph[i])
            {
                std::cout << edge << " ";
            }
            std::cout << "]" << std::endl;
        }
    }
    void add_edge(int a, int b)
    {
        if (a != b && a < static_cast<int>(graph.size()) && b < static_cast<int>(graph.size()))
        {
            auto it = std::find(graph[a].begin(), graph[a].end(), b);
            if (it == graph[a].end() || graph[a].empty())
            {
                graph[a].push_back(b);
            }
            auto it2 = std::find(graph[b].begin(), graph[b].end(), a);
            if (it2 == graph[b].end() || graph[b].empty())
            {
                graph[b].push_back(a);
            }
        }
    }
    void remove_edge(int a, int b)
    {
        if (a != b && a < static_cast<int>(graph.size()) && b < static_cast<int>(graph.size()))
        {
            auto it = std::find(graph[a].begin(), graph[a].end(), b);
            if (it != graph[a].end())
            {
                graph[a].erase(it);
            }
            auto it2 = std::find(graph[b].begin(), graph[b].end(), a);
            if (it2 != graph[b].end())
            {
                graph[b].erase(it2);
            }
        }
    };
};

int main()
{
    Adjacency_vector graph{};
    graph.add_vertex();
    graph.add_vertex();
    graph.add_vertex();
    graph.add_vertex();
    graph.add_vertex();
    graph.add_edge(1, 2);
    graph.add_edge(1, 4);
    graph.add_edge(1, 3);
    graph.remove_edge(1, 2);
    graph.print_vertex();
}