#include <iostream>
#include <vector>

template <typename T>
struct Node
{
    T value;
    Node *left{nullptr}, *right{nullptr}, *parent{nullptr};

    Node(T value) : value(value) {}

    Node(T value, Node<T> *left, Node<T> *right) : value(value), left(left), right(right) {
      left->parent = right->parent = this;
    }

    // traverse the node and its children preorder
    // and put all the results into `result`
    void preorder_traversal(std::vector<Node<T>*>& result)
    {
        preorder_traversal_impl(this, result);
    }

private:
    void preorder_traversal_impl(Node *current, std::vector<Node<T>*>& result) {
      result.push_back(current);
      if(current->left) preorder_traversal_impl(current->left, result);
      if(current->right) preorder_traversal_impl(current->right, result);
    }
};
