//
// Created by andre on 11/7/2021.
//
#include <iostream>

#ifndef TREAP_TREAPTREE_H
#define TREAP_TREAPTREE_H
using namespace std;

class TreapTree{
private:
    class node {
    public:
        string userName;
        int priority;
        //Node* to user
        node *leftChild;
        node *rightChild;
        node *newNode(string name);
    };

public:
    node *root = nullptr;
    node *rightRotate(node *parent);
    node *leftRotate(node *parent);
    node *search(node *currentNode, string val);
    node *insert(node *currentNode, string val);
    void printInOrder(node *current);
};



#endif //TREAP_TREAPTREE_H
