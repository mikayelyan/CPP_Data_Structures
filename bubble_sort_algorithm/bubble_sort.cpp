#include <iostream>
#include <vector>

void bubble_sort(std::vector<int> &);
void print_vector(std::vector<int> &);

int main()
{
    std::vector<int> vec{14, 0, -5, 47, 6, 1, 2};
    print_vector(vec); // before sorting
    bubble_sort(vec);
    print_vector(vec);  // after sorting
    return 0;
}

void bubble_sort(std::vector<int> &vec)
{
    int temp{};
    for (size_t i{}; i < vec.size(); ++i)
    {
        for (size_t k{}; k < vec.size() - i - 1; ++k)
        {

            if (vec[k] > vec[k + 1])
            {
                temp = vec[k];
                vec[k] = vec[k + 1];
                vec[k + 1] = temp;
            }
        }
    }
}

void print_vector(std::vector<int> &vec)
{
    std::cout << "[ ";
    for (size_t i{}; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "]" << std::endl;
}