#include <iostream>

class Binary_Tree
{
    int data{};
    Binary_Tree *right{nullptr};
    Binary_Tree *left{nullptr};
    void print() // print tree sorted
    {
        if (left != nullptr)
            (*left).print();

        std::cout << data << " ";

        if (right != nullptr)
            (*right).print();
    }
    void insert_deleted(Binary_Tree *node, Binary_Tree *temp)
    {
        if (node->data > temp->data)
        {
            if (temp->right != nullptr)
                insert_deleted(node, temp->right);
            else
                temp->right = node;
        }
        else if (node->data < temp->data)
        {
            if (temp->left != nullptr)
                insert_deleted(node, temp->left);
            else
            {
                temp->left = node;
            }
        }
    }
    Binary_Tree *find_pointing_node(Binary_Tree *node, int value)
    {
        if (node->right != nullptr && value > node->data)
        {
            if (node->right->data == value)
            {
                return node;
            }
            node = node->right;
            return find_pointing_node(node, value);
        }
        else if (node->left != nullptr && value < node->data)
        {
            if (node->left->data == value)
            {
                return node;
            }
            node = node->left;
            return find_pointing_node(node, value);
        }
        else
        {
            return nullptr;
        }
    }

public:
    Binary_Tree() = delete;
    Binary_Tree(int value) { data = value; };
    ~Binary_Tree()
    {
        delete right;
        delete left;
    };
    void insert_element(int value)
    {
        if (value > data)
        {
            if (right != nullptr)
                (*right).insert_element(value);
            else
                right = new Binary_Tree(value);
        }
        else
        {
            if (left != nullptr)
                (*left).insert_element(value);
            else
                left = new Binary_Tree(value);
        }
    }
    bool remove_element(int value)
    {
        Binary_Tree *node_to_delete;
        if (value == data)
        {
            if (left == nullptr && right == nullptr)
            {
                delete this;
                return true;
            }
            if (right == nullptr)
            {
                node_to_delete = left;
                data = left->data;
                right = left->right;
                left = left->left;
            }
            else if (left == nullptr)
            {
                node_to_delete = right;
                data = right->data;
                left = right->left;
                right = right->right;
            }
            else
            {
                node_to_delete = right;
                Binary_Tree *old_left = left;
                data = right->data;
                left = right->left;
                right = right->right;
                insert_deleted(old_left, this);
            }
            node_to_delete = nullptr;
            delete node_to_delete;
            return true;
        }
        Binary_Tree *pointing_node;
        pointing_node = this;
        pointing_node = find_pointing_node(pointing_node, value);

        if (pointing_node == nullptr)
            return false;
        if (pointing_node->left != nullptr && pointing_node->left->data == value)
        {
            node_to_delete = pointing_node->left;
            pointing_node->left = nullptr;
        }
        else
        {
            node_to_delete = pointing_node->right;
            pointing_node->right = nullptr;
        }

        if (node_to_delete->left == nullptr && node_to_delete->right == nullptr)
        {

            node_to_delete = nullptr;
            delete node_to_delete;
        }
        else if (node_to_delete->left == nullptr)
        {

            Binary_Tree *node_to_insert = node_to_delete->right;
            node_to_delete = nullptr;
            delete node_to_delete;
            insert_deleted(node_to_insert, this);
        }
        else if (node_to_delete->right == nullptr)
        {

            Binary_Tree *node_to_insert = node_to_delete->left;
            node_to_delete = nullptr;
            delete node_to_delete;
            insert_deleted(node_to_insert->left, this);
        }
        else
        {
            Binary_Tree *node_to_insert_left = node_to_delete->left;
            Binary_Tree *node_to_insert_right = node_to_delete->right;
            node_to_delete = nullptr;
            delete node_to_delete;
            insert_deleted(node_to_insert_right, this);
            insert_deleted(node_to_insert_left, this);
        }
        return true;
    };
    void print_tree() // print tree sorted
    {
        print();
        std::cout << std::endl;
    }
};

int main()
{
    Binary_Tree *ttree = new Binary_Tree(100);
    ttree->insert_element(22);
    ttree->print_tree();
    
    Binary_Tree tree{100};
    tree.insert_element(20);
    tree.insert_element(120);
    tree.insert_element(874);
    tree.insert_element(154);
    tree.insert_element(1547);
    tree.insert_element(-25);
    tree.insert_element(-27);
    tree.insert_element(62);
    tree.insert_element(45);
    tree.insert_element(0);
    tree.insert_element(-1547);
    tree.insert_element(-652);
    tree.insert_element(99);
    tree.insert_element(87);
    tree.insert_element(82);
    tree.insert_element(81);
    tree.print_tree();

    tree.remove_element(100);
    tree.print_tree();
    return 0;
}