#include "List.h"

ListNode::ListNode() {}

ListNode::ListNode(User* u) : user(u), next(nullptr), previous(nullptr) {}


ListNode* 
ListNode::getNext() {
	return next;
}

ListNode* 
ListNode::getPrev() {
	return previous;
}

User* 
ListNode::getUser() {
	return user;
}

void 
ListNode::setNext(ListNode* nxt) {
	next = nxt;
}

void 
ListNode::setPrev(ListNode* prev) {
	previous = prev;
}

void 
ListNode::setUser(User* u) {
	user = u;
}

List::List() : head(nullptr), tail(nullptr), dummyNode(nullptr), size(0) {}

List::~List() {
	for (int i = 0; i < size; i++) {
		ListNode* temp = head->getNext();
		delete head;
		head = temp;
	}
	size = 0;
}

int 
List::getSize() const {
	return size;
}

void 
List::insert(User* user) {
	ListNode* newNode = new ListNode(user);
	ListNode* temp = head;
	bool flag = false;
	while (temp != dummyNode) {
		if (newNode->getUser()->getUsername() == temp->getUser()->getUsername()) {
			flag = true;
			break;
		}
		temp = temp->getNext();
	}

	if (!flag) {
		if (size == 0) {
			head = newNode;
			tail = head;
			dummyNode = new ListNode();
			tail->setNext(dummyNode);
			dummyNode->setPrev(tail);
		}
		else {
			tail->setNext(newNode);
			newNode->setPrev(tail);
			tail = newNode;
			tail->setNext(dummyNode);
			dummyNode->setPrev(tail);
		}
		size++;
	}
	else
		cout << "This username is already taken.\n";
}

void 
List::insert(string username, string name, string email) {//Inserting at the end of the Linked List 
	User* user = new User(username, name, email);
	insert(user);
}

void 
List::erase(string username) {
	ListNode* temp = head;
	while (temp != dummyNode) {
		if (temp->getUser()->getUsername() == username) {
			if (temp == head) {
				head = temp->getNext();
				head->setPrev(nullptr);
			}
			else if (temp == tail) {
				tail = temp->getPrev();
				tail->setNext(dummyNode);
				dummyNode->setPrev(tail);
			}
			else {
				temp->getPrev()->setNext(temp->getNext());
				temp->getNext()->setPrev(temp->getPrev());
			}
			delete temp;
			size--;
		}
		temp = temp->getNext();
	}
}

User* 
List::search(string username) const {
	ListNode* temp = head;
	bool flag = false;
	while (temp != dummyNode) {
		if (temp->getUser()->getUsername() == username)
			return temp->getUser();
		temp = temp->getNext();
	}
	return nullptr;
}

User* List::operator[](int ind)
{
	if (ind >= size) {
		cout << "Array index out of bound, exiting";
		exit(0);
	}
	ListNode* temp = head;
	for (int i = 1; i <= ind; i++) {
		temp = temp->getNext();
	}
	return temp->getUser();
}