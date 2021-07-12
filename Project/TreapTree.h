/*
* @author Andrew Naseif          20190114   S28
* @author Mark Samir Fawzy       20190401   S10
* @author Kareem Mohamed Morsy   20190386   S9
* Created on 9/7/2021
*/
#ifndef TREAP_TREAPTREE_H
#define TREAP_TREAPTREE_H
#include <iostream>

using namespace std;

// This line is to resolve the circular dependency problem
// https://pvigier.github.io/2018/02/09/dependency-graph.html
class User;

class TreapTree {
private:
	class Node {
	public:
		User* user;
		int priority;
		Node* leftChild;
		Node* rightChild;
		Node(User* user);
	};
	Node* rightRotate(Node* parent);
	Node* leftRotate(Node* parent);
	User* search(Node* currentNode, string val);
	Node* insert(Node* currentNode, User* val);
	Node* deleteUser(Node* currentNode, string val);
	void printInOrder(Node* current);
	void print2DUtil(Node* root, int space);
	void print2D(Node* root);

public:
	Node* root = nullptr;
	User* search(string val);
	void insert(User* val);
	void deleteUser(string val);
	void printInOrder();
	void print2D();
};

#endif //TREAP_TREAPTREE_H
