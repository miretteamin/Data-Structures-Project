/*
* @author Andrew Naseif          20190114   S28
* @author Mark Samir Fawzy       20190401   S10
* @author Kareem Mohamed Morsy   20190386   S9
* Created on 9/7/2021
*/
#include "TreapTree.h"
#include <cstdlib>
#include "User.h"

TreapTree::Node::Node(User* user) {
	this->user = user;
	priority = rand() % 1000;
	leftChild = nullptr;
	rightChild = nullptr;
}

TreapTree::Node* TreapTree::rightRotate(TreapTree::Node* parent) {
	Node* dummy = parent->leftChild;
	Node* temp = dummy->rightChild;
	dummy->rightChild = parent;
	parent->leftChild = temp;
	return dummy;
}

TreapTree::Node* TreapTree::leftRotate(TreapTree::Node* parent) {
	Node* temp = parent->rightChild;
	Node* temp2 = temp->leftChild;
	//Perform rotation
	temp->leftChild = parent;
	parent->rightChild = temp2;
	return temp;
}

void 
TreapTree::insert(User* val) {
	Node* n = insert(root, val);
	root = n;
}

TreapTree::Node* TreapTree::insert(TreapTree::Node* currentNode, User* val) {
	if (currentNode == nullptr)
		return (new Node(val));
	if (val->getUsername() < currentNode->user->getUsername()) {
		currentNode->leftChild = insert(currentNode->leftChild, val);
		if (currentNode->leftChild->priority > currentNode->priority)
			currentNode = rightRotate(currentNode);
	}
	else {
		currentNode->rightChild = insert(currentNode->rightChild, val);
		if (currentNode->rightChild->priority > currentNode->priority)
			currentNode = leftRotate(currentNode);
	}
	return currentNode;
}

void 
TreapTree::printInOrder() {
	printInOrder(root);
}

void 
TreapTree::printInOrder(TreapTree::Node* current) {
	if (current != nullptr) {
		printInOrder(current->leftChild);
		cout << current->user->getUsername() << ", " << current->user->getName() << "\n";
		printInOrder(current->rightChild);
	}
}


User*
TreapTree::search(string val) {
	return search(root, val);
}

User* 
TreapTree::search(TreapTree::Node* currentNode, string val) {
	if (currentNode == nullptr)
		return nullptr;
	else if (currentNode->user->getUsername() == val)
		return currentNode->user;
	// change *(currentNode->user) to currentNode->user->username
	else if (currentNode->user->getUsername() < val)
		return search(currentNode->rightChild, val);
	else
		return search(currentNode->leftChild, val);
}


void 
TreapTree::deleteUser(string val) {
	Node* n = deleteUser(root, val);
	root = n;
}

TreapTree::Node* 
TreapTree::deleteUser(TreapTree::Node* currentNode, string val) {
	if (currentNode == nullptr)
		return nullptr;

	if (val < currentNode->user->getUsername())
		currentNode->leftChild = deleteUser(currentNode->leftChild, val);
	else if (val > currentNode->user->getUsername())
		currentNode->rightChild = deleteUser(currentNode->rightChild, val);
	// If one child is null
	else if (currentNode->leftChild == nullptr) {
		Node* temp = currentNode->rightChild;
		delete currentNode;
		currentNode = temp;
	}
	else if (currentNode->rightChild == nullptr) {
		Node* temp = currentNode->leftChild;
		delete currentNode;
		currentNode = temp;
	}
	// If both children are not null
	else if (currentNode->leftChild->priority > currentNode->rightChild->priority) {
		currentNode = rightRotate(currentNode);
		currentNode->rightChild = deleteUser(root->rightChild, val);
	}
	else if (currentNode->leftChild->priority < currentNode->rightChild->priority) {
		currentNode = leftRotate(currentNode);
		currentNode->rightChild = deleteUser(root->leftChild, val);
	}

	return currentNode;
}


void 
TreapTree::print2DUtil(Node* root, int space)
{
	// Base case
	if (root == NULL)
		return;

	// Increase distance between levels
	space += 2;

	// Process right child first
	print2DUtil(root->rightChild, space);

	// Print current node after space
	// count
	cout << endl;
	for (int i = 2; i < space; i++)
		cout << " ";
	cout << root->user->getUsername() << "\n";

	// Process left child
	print2DUtil(root->leftChild, space);
}

// Wrapper over print2DUtil()
void 
TreapTree::print2D(Node* root)
{
	// Pass initial space count as 0
	print2DUtil(root, 0);
}

void 
TreapTree::print2D()
{
	print2D(root);
}
