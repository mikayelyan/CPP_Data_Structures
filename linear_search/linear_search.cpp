#include <iostream>

template <typename T>
int linear_search(T *, int, T);

int main()
{
    int size = 10;
    int arr[size]{-1, 20, 54, 54, 68, 7, 8};

    int index = linear_search(arr, size, 20);
    std::cout << "Index: " << index << std::endl;

    std::string arr2[size] {"Hello", "World", "!", "lorem", "ipsum", "15", "ccc"};
    index = linear_search(arr2, size, {"ipsum"});
    std::cout << "Index: " << index << std::endl;
    return 0;
}

template <typename T>
int linear_search(T *arr, int size, T element)
{
    for (int i{}; i < size; ++i)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
