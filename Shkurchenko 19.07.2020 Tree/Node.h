#pragma once
#include <iostream>

using namespace std;
template <class T>
class Node
{
    T data;
    Node<T>* parent = nullptr;
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;
public:
    Node(T val);
    Node<T>* getParent()const;
    Node<T>* getLeft()const;
    Node<T>* getRight()const;
    T getData()const;
    void setData(T val);
    void setParent(Node<T>* val);
    void setLeft(Node<T>* val);
    void setRight(Node<T>* val);
};

template<class T>
Node<T>::Node(T val)
{
    data = val;
}
template<class T>
Node<T>* Node<T>::getParent() const
{
    return parent;
}
template<class T>
Node<T>* Node<T>::getLeft() const
{
    return left;
}
template<class T>
Node<T>* Node<T>::getRight() const
{
    return right;
}
template<class T>
T Node<T>::getData() const
{
    return data;
}
template<class T>
void Node<T>::setData(T val)
{
    data = val;
}
template<class T>
void Node<T>::setParent(Node<T>* val)
{
    parent = val;
}
template<class T>
void Node<T>::setLeft(Node<T>* val)
{
    left = val;
}
template<class T>
void Node<T>::setRight(Node<T>* val)
{
    right = val;
}
