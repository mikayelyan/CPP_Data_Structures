#include <iostream>
#include <vector>

class Adjacency_Matrix
{
    int **matrix;
    int vertices_count {0};
    int size {};

public:
    Adjacency_Matrix() = delete;
    Adjacency_Matrix(int size)
    {
        matrix = new int *[size];
        for (int i{}; i < size; ++i)
        {
            matrix[i] = new int[size];
        }
        size = size;
    }
    ~Adjacency_Matrix() {
        for(int i{}; i < size; ++i) {
            delete [] matrix[i];
        }
        delete [] matrix;
    }
    void add_vertex()
    {
        vertices_count++;
        for (int i{}; i < vertices_count; ++i)
        {
            matrix[i][vertices_count - 1] = 0;
            matrix[vertices_count - 1][i] = 0;
        }
    }
    void remove_vertex(int vertex)
    {
        if (vertex < vertices_count)
        {
            int current = vertex;
            while (current < vertices_count)
            {
                for (int i{}; i < vertices_count; ++i)
                {
                    matrix[current][i] = matrix[current + 1][i];
                }

                for (int i{}; i < vertices_count; ++i)
                {
                    matrix[i][current] = matrix[i][current + 1];
                }
                current++;
            }
            vertices_count--;
        }
    }
    void add_edge(int a, int b)
    {
        if (a != b && a < vertices_count && b < vertices_count)
        {

            matrix[a][b] = 1;
            matrix[b][a] = 1;
        }
    }
    void remove_edge(int a, int b)
    {
        if (a != b && a < vertices_count && b < vertices_count)
        {

            matrix[a][b] = 0;
            matrix[b][a] = 0;
        }
    }
    void print_graph()
    {
        for (int i{}; i < vertices_count; ++i)
        {
            std::cout << "[ ";
            for (int j{}; j < vertices_count; ++j)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << "]" << std::endl;
        }
    }
};

int main()
{
    Adjacency_Matrix graph {10};
    graph.add_vertex();
    graph.add_vertex();
    graph.add_vertex();
    graph.add_vertex();
    graph.add_vertex();
    graph.add_edge(2, 3);
    graph.add_edge(1, 2);
    graph.add_edge(2, 4);
    graph.add_edge(5, 6);
    graph.add_edge(2, 4);
    graph.print_graph();
    std::cout << " edges added " << std::endl;

    graph.remove_edge(1, 2);
    graph.print_graph();
    std::cout << " edge [1, 2] removed " << std::endl;

    graph.remove_vertex(3);
    graph.print_graph();
    std::cout << " vertex (3) removed " << std::endl;

}