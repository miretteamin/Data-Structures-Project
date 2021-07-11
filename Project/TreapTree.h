//
// Created by andre on 11/7/2021.
//
#include <iostream>

#ifndef TREAP_TREAPTREE_H
#define TREAP_TREAPTREE_H
using namespace std;

class TreapTree {
private:
	class Node {
	public:
		string* user;
		int priority;
		//Node* to user
		Node* leftChild;
		Node* rightChild;
		Node(string* name);
	};
	Node* rightRotate(Node* parent);
	Node* leftRotate(Node* parent);
	Node* insert(Node* currentNode, string* val);
	Node* deleteUser(Node* currentNode, string val);
	void printInOrder(Node* current);
	void print2DUtil(Node* root, int space);
	void print2D(Node* root);

public:
	Node* root = nullptr;
	string* search(Node* currentNode, string val);
	void insert(string* val);
	void deleteUser(string val);
	void printInOrder();
	void print2D();
};

#endif //TREAP_TREAPTREE_H
