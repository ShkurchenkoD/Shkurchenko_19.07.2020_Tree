#pragma once

#include "Node.h"

template<class T>
class Tree
{
    Node<T>* root = nullptr;
public:
    Tree();

    void insert(T val);

    Node<T>* getRoot() const;

    void print(Node<T>* node) const;

    void print() const;

    Node<T>* find(T val) const;

    Node<T>* getMin(Node<T>* node) const;

    Node<T>* getNext(Node<T>* node) const;

    void erase(Node<T>* node);
};

template<class T>
void Tree<T>::erase(Node<T>* node)
{
    if (node == nullptr)
        return;

    Node<T>* tmp = nullptr;
    if (node->getLeft() && node->getRight())
        tmp = getNext(node);
    else
        tmp = node;

    Node<T>* son = nullptr;
    if (tmp->getLeft())
        son = tmp->getLeft();
    else
        son = tmp->getRight();

    auto parent = tmp->getParent();
    if (son)
        son->setParent(parent);

    if (parent == nullptr)
        root = son;
    else
    {
        if (tmp == parent->getLeft())
            parent->setLeft(son);
        else
            parent->setRight(son);
    }

    if (node != tmp)
        node->setData(tmp->getData());
    delete tmp;
}

/*
template<class T>
void Tree<T>::erase(Node<T> *node)
{
    if (node == nullptr)
        return;
    if (node->getLeft() == nullptr && node->getRight() == nullptr)
    {
        auto parent = node->getParent();
        if (node == root)
            root = nullptr;
        else
        {
            if(node==parent->getLeft())
                parent->setLeft(nullptr);
            else
                parent->setRight(nullptr);
        }
        delete node;
        return;
    }
    if(node->getLeft() == nullptr || node->getRight() == nullptr)
    {
        auto parent = node->getParent();
        Node<T>* son = nullptr;
        if(node->getLeft())
            son = node->getLeft();
        else
            son = node->getRight();

        son->setParent(parent);
        if(parent== nullptr)
            root = son;
        else
        {
            if(node==parent->getLeft())
                parent->setLeft(son);
            else
                parent->setRight(son);
        }
        delete node;
        return;
    }
    auto next = getNext(node);
    node->setData(next->getData());
    erase(next);
}
*/

template<class T>
Node<T>* Tree<T>::getNext(Node<T>* node) const
{
    if (node == nullptr)
        return nullptr;
    if (node->getRight())
        return getMin(node->getRight());
    auto parent = node->getParent();
    while (parent && node == parent->getRight())
    {
        node = parent;
        parent = parent->getParent();
    }
    return parent;
}

template<class T>
Node<T>* Tree<T>::getMin(Node<T>* node) const
{
    if (node == nullptr)
        return nullptr;
    while (node->getLeft())
        node = node->getLeft();
    return node;
}

template<class T>
Node<T>* Tree<T>::find(T val) const
{
    auto cur = root;
    while (cur)
    {
        if (val == cur->getData())
            return cur;
        if (val < cur->getData())
            cur = cur->getLeft();
        else
            cur = cur->getRight();
    }
    return nullptr;
}

template<class T>
void Tree<T>::print(Node<T>* node) const
{
    if (node == nullptr)
        return;

    print(node->getLeft());
    cout << node->getData() << " ";
    print(node->getRight());
}

template<class T>
Node<T>* Tree<T>::getRoot() const
{
    return root;
}

template<class T>
Tree<T>::Tree() = default;

template<class T>
void Tree<T>::insert(T val)
{
    auto tmp = new Node<T>(val);
    if (root == nullptr)
    {
        root = tmp;
        return;
    }
    auto cur = root, prev = root;
    while (cur)
    {
        prev = cur;
        if (val < cur->getData())
            cur = cur->getLeft();
        else
            cur = cur->getRight();
    }
    tmp->setParent(prev);
    if (val < prev->getData())
        prev->setLeft(tmp);
    else
        prev->setRight(tmp);

}

template<class T>
void Tree<T>::print() const
{
    print(root);
    cout << endl;
}
