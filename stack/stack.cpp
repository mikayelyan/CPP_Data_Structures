#include <iostream>
#include <vector>

template <typename T>
class Stack
{
    std::vector<T> data;

public:
    Stack(){};
    Stack(T value) { data.push_back(value); };
    ~Stack(){};
    T get_element()
    {
        return data[data.size() - 1];
    };
    void remove_element() {
        data.pop_back();
    };
    void insert_element(T value) {
        data.push_back(value);
    }
};

int main()
{
    Stack<int> stack{10};
    stack.insert_element(20);
    stack.insert_element(10);
    stack.insert_element(340);
    int lastEl = stack.get_element();
    stack.remove_element();
    std::cout << lastEl << std::endl;
    lastEl = stack.get_element();
    std::cout << lastEl << std::endl;
}