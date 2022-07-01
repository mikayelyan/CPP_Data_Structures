#include <iostream>

template <typename T, int N>
class Array
{
    int size{N};
    T *arr = (T *)malloc(sizeof(T) * N);

    friend std::ostream &operator<<(std::ostream &os, Array<T, N> &arr)
    {
        os << "[ ";
        for (int i{0}; i < N; ++i)
        {
            os << arr[i] << " ";
        }
        os << "]";
        return os;
    }

public:
    Array() = default;
    Array(T init_value)
    {
        for (int i{0}; i < N; ++i)
        {
            arr[i] = init_value;
        }
    }
    ~Array()
    {
        delete arr;
    };
    void fill_array(T value)
    {
        for (int i{0}; i < N; ++i)
        {
            arr[i] = value;
        }
    }
    int length() { return size; };
    T &operator[](int index)
    {
        return arr[index];
    }
};

int main()
{
    Array<int, 10> arr1;
    arr1[1] = 100;
    arr1[5] = 1000;

    std::cout << "Array 1: " << arr1 << std::endl;

    Array<std::string, 5> arr2 {"Hello"};
    arr2[3] = "World";
    std::cout << "Array 2: " << arr2 << std::endl;
    std::cout << "Array 2 Length: " << arr1.length() << std::endl;

    return 0;
}