#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
    int **graph;
    int graphSize;
    int **distances;
    int *checkedNodes;
    vector<int> *pathList;

public:
    Graph() = delete;
    Graph(const int size)
    {
        graphSize = size;
        graph = new int *[size];
        distances = new int *[size] {};
        checkedNodes = new int[size]{0};
        pathList = new vector<int>[size];
        for (int i{0}; i < size; ++i)
        {
            graph[i] = new int[size];
            distances[i] = nullptr;
        }
    }
    ~Graph()
    {
        for (int i{0}; i < graphSize; ++i)
        {
            delete[] graph[i];
            delete[] distances[i];
        }
        delete[] graph;
        delete[] distances;
        delete[] checkedNodes;
        delete[] pathList;
    };
    int getNode(int i, int j)
    {
        return graph[i][j];
    }
    void createNode(int i, int j, int distance)
    {
        try
        {
            if (i > graphSize - 1 || j > graphSize - 1 || i < 0 || j < 0)
            {
                throw 1;
            }
            else if (!graph[i][j])
            {
                graph[i][j] = distance;
                graph[j][i] = distance;
            }
            else
            {
                throw 2;
            }
        }
        catch (int e)
        {
            if (e == 1)
            {
                cout << "Error: Wrong Position Input" << endl;
            }
            else if (e == 2)
            {
                cout << "Error: Node Already exists" << endl;
            }
        }
    }

    void getShortestPath(int index)
    {
        calcShortestPath(index);
        printResultAll(index);
    }
    void getShortestPath(int start, int end)
    {
        calcShortestPath(start);
        printResultSingle(start, end);
    }
    void calcShortestPath(int index)
    {
        for (int i{0}; i < graphSize; i++)
        {
            distances[i] = nullptr;
            checkedNodes[i] = 0;
        }
        distances[index] = new int(0);
        calcDijkstra(index);
    }
    void calcDijkstra(int index)
    {
        if (checkedNodes[index] == 0)
        {
            for (int i{0}; i < graphSize; ++i)
            {
                if (graph[index][i] != 0)
                {
                    if (distances[i] != nullptr)
                    {
                        if (*distances[i] > *distances[index] + graph[index][i])
                        {
                            *distances[i] = *distances[index] + graph[index][i];
                            pathList[i].pop_back();
                            pathList[i].push_back(index);
                        }
                    }
                    else
                    {
                        distances[i] = new int(*distances[index] + graph[index][i]);
                        pathList[i] = pathList[index];
                        pathList[i].push_back(i);
                    }
                }
            }
            checkedNodes[index] = 1;
            for (int i{0}; i < graphSize; ++i)
            {
                if (graph[index][i] != 0)
                {
                    calcDijkstra(i);
                }
            }
        }
    }
    void printResultAll(int index)
    {
        cout << "Shortest paths from node " << index << ":" << endl;
        for (int i{0}; i < graphSize; i++)
        {
            cout << i << ": " << *distances[i] << endl;
        }
    };
    void printResultSingle(int start, int end)
    {
        cout << "Shortest paths from node " << start << " to " << end << ": " << *distances[end] << endl;
        cout << start << " -> ";
        for (size_t j{0}; j < pathList[end].size(); j++)
        {
            if (j == (pathList[end].size() - 1))
            {
                cout << end;
            }
            else
            {
                cout << pathList[end][j] << " -> ";
            }
        }
        cout << endl;
    };
};

int main()
{
    Graph a{10};
    a.createNode(0, 1, 10);
    a.createNode(0, 2, 12);
    a.createNode(1, 3, 8);
    a.createNode(2, 3, 3);
    a.createNode(1, 4, 8);
    a.createNode(2, 5, 8);
    a.createNode(2, 6, 15);
    a.createNode(4, 6, 7);
    a.createNode(6, 7, 7);
    a.createNode(6, 9, 17);
    a.createNode(6, 8, 1);
    a.createNode(7, 8, 11);
    a.createNode(8, 9, 5);
    a.getShortestPath(3, 7);
    a.getShortestPath(3);
}