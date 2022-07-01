#include <iostream>

template <typename T>
class Linked_List
{
    T data{};
    Linked_List *next = nullptr;

public:
    Linked_List() = default;
    Linked_List(T value) : data{value} {};
    ~Linked_List() { delete next; };
    void push_back(T data)
    {
        if (next == nullptr)
            next = new Linked_List(data);
        else
        {
            Linked_List *temp = next;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new Linked_List(data);
            temp = nullptr;
            delete temp;
        }
    }
    void push_front(T value)
    {
        Linked_List *temp = new Linked_List(value);
        temp->next = next;
        next = temp;
    }
    bool push_at_index(int index, T data)
    {
        if (index < 0)
            return false;
        Linked_List *tmp = this;

        for (int i{}; i < index; ++i)
        {
            if (tmp->next != nullptr)
                tmp = tmp->next;
            else
            {
                tmp = nullptr;
                delete tmp;
                return false;
            }
        }
        if (tmp->next == nullptr)
        {
            tmp = nullptr;
            delete tmp;
            return false;
        }
        else
        {
            Linked_List *newEl = new Linked_List(data);
            newEl->next = tmp->next;
            tmp->next = newEl;
        }
        tmp = nullptr;
        delete tmp;
        return true;
    }
    int find_element_index(T value)
    {
        if (next == nullptr)
            return -1;
        int index = 0;
        Linked_List *temp = next;
        bool found = false;
        while (temp->next != nullptr)
        {
            temp = temp->next;
            index++;
            if (temp->data == value)
            {
                found = true;
                break;
            }
        }
        temp = nullptr;
        delete temp;
        return found ? index : -1;
    }
    bool remove_element(int index)
    {
        if (index < 0)
            return false;
        Linked_List *tmp = this;

        for (int i{}; i < index; ++i)
        {
            if (tmp->next != nullptr)
                tmp = tmp->next;
            else
            {
                tmp = nullptr;
                delete tmp;
                return false;
            }
        }
        if (tmp->next == nullptr)
        {
            tmp = nullptr;
            delete tmp;
            return false;
        }
        else if (tmp->next->next == nullptr)
        {
            Linked_List *nextEl = tmp->next;
            tmp->next = nullptr;
            delete nextEl;
        }
        else
        {
            Linked_List *nextEl = tmp->next->next;
            tmp->next = nullptr;
            delete tmp->next;
            tmp->next = nextEl;
        }

        tmp = nullptr;
        delete tmp;
        return true;
    };

    void print_list()
    {
        Linked_List *temp = next;
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    // Test the implemented linked list
    Linked_List<int> list;
    list.push_back(1);
    list.push_back(3);
    list.push_back(5);
    list.push_back(7);
    list.push_front(-1);
    list.print_list();
    list.push_at_index(4, 10);
    list.print_list();
    int index = list.find_element_index(5);
    std::cout << "index: " << index << std::endl;
    list.remove_element(index);
    list.print_list();

    Linked_List<std::string> list3{"Hi"};
    list3.push_back("World");
    list3.push_back("!");
    list3.push_front("Hello");
    list3.print_list();
    list3.remove_element(1);
    list3.print_list();

    return 0;
}