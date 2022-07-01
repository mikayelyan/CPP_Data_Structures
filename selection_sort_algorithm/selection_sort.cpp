#include <iostream>

void selection_sort(int *, int);
void print_array(int *, int);

int main()
{
    int *arr = new int[10]{2, 5, -7, 99, 9, -236, 24, 3265, 10, 0};
    print_array(arr, 10); // before sort
    selection_sort(arr, 10);
    print_array(arr, 10); // after sort
    return 0;
}

void selection_sort(int *arr, int size)
{
    for (int i{}; i < size; ++i)
    {
        int min{arr[i]};
        int minIndex{i};
        for (int k{i}; k < size; k++)
        {
            if (arr[k] < min)
            {
                min = arr[k];
                minIndex = k;
            }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[minIndex] = temp;
    }
};

void print_array(int *arr, int size)
{
    std::cout << "[ ";
    for (int i{}; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
    ;
}
