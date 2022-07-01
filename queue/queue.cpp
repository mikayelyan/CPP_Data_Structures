#include <iostream>

template <typename T>
struct Node
{
    T data{};
    Node *next{nullptr};
    ~Node()
    {
        delete next;
    };
};

template <typename T>
class Queue
{
    Node<T> *root = new Node<T>();
    Node<T> *last = root;

public:
    Queue() { root->next = nullptr, root->data = {}; };
    Queue(T value)
    {
        root->data = value;
    };
    ~Queue()
    {
        delete root;
        last->next = nullptr;
        delete last;
    };
    void insert_element(T value) // insert element queue end
    {
        Node<T> *new_el = new Node<T>{};
        new_el->data = value;
        last->next = new_el;
        last = new_el;
    }
    void remove_element() // remove element from queue start
    {
        if (root != last)
        {
            Node<T> *temp = root;
            root=root->next;
            temp->next = nullptr;
            delete temp;
        } else {
            root->data = {};
        }
    };
    T get_element() // get next element in queue
    {
        return root->data;
    }
};

int main()
{
    Queue<int> q{547};
    q.insert_element(14);
    q.insert_element(12);
    int el = q.get_element();
    std::cout << el << std::endl;
    q.insert_element(11);
    q.remove_element();
    q.remove_element();
    el = q.get_element();
    std::cout << el << std::endl;
    q.remove_element();

    return 0;
}