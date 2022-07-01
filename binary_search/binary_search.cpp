#include <iostream>
#include <vector>

template <typename T>
int binary_search(std::vector<T>, T, int, int);

int main()
{
    std::vector<int> vec{10, 20, 30, 40, 50, 60, 70, 80, 90};

    int index = binary_search(vec, 90, 0, vec.size());
    std::cout << "index: " << index << std::endl;

    return 0;
}

template <typename T>
int binary_search(std::vector<T> vec, T value, int start, int end)
{
    int index = (start + end) / 2;
    if (vec[index] == value)
        return index;
    else if (value > vec[index])
        return binary_search(vec, value, index + 1, end);
    else if (value < vec[index])
        return binary_search(vec, value, start, index - 1);
    return -1;
}
