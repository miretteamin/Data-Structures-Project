////
//// Created by andre on 11/7/2021.
////
#include "TreapTree.h"

TreapTree::node *TreapTree::node::newNode(string name) {
    node *currentNode = new node();
    currentNode->userName = name;
    currentNode->priority=0;
    currentNode->leftChild = nullptr;
    currentNode->rightChild = nullptr;
    return (currentNode);
}

TreapTree::node *TreapTree::rightRotate(TreapTree::node *parent) {
    node *dummy = parent->leftChild;
    node *temp = dummy->rightChild;
    dummy->rightChild = parent;
    parent->leftChild = temp;
    return dummy;
}
TreapTree::node *TreapTree::leftRotate(TreapTree::node *parent) {
    node *temp = parent->rightChild;
    node *temp2 = temp->leftChild;
    //Perform rotation
    temp->leftChild = parent;
    parent->rightChild = temp2;
    return temp;
}

TreapTree::node *TreapTree::insert(TreapTree::node *currentNode, string val) {
    if (currentNode == nullptr)
        return (newNode(val));
    if (val < currentNode->userName) {
        currentNode->leftChild = insert(currentNode->leftChild);
        if (currentNode->leftChild->priority > currentNode->priority)
            currentNode = rightRotate(currentNode);
    } else {
        currentNode->rightChild = insert(currentNode->rightChild);
        if (currentNode->rightChild->priority > currentNode->priority)
            currentNode = leftRotate(currentNode);
    }
    return currentNode;
}

void TreapTree::printInOrder(TreapTree::node *current) {
    if (current != nullptr) {
        printInOrder(current->leftChild);
        cout << current->userName << " ";
        printInOrder(current->rightChild);
    } else {
        return;
    }
}
//TreapTree::node *TreapTree::search(TreapTree::node *currentNode, string val) {
//    if (currentNode == nullptr || currentNode->userName == val)
//       return currentNode;
//    if (currentNode->userName < val)
//        return search(currentNode->rightChild, val);
//    return search(currentNode->leftChild, val);
//}



