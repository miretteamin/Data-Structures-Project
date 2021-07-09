#include "List.h"

ListNode::ListNode() : username(""), name(""), email(""), next(nullptr), previous(nullptr) {}

ListNode::ListNode(string un, string n, string e) : username(un), name(n), email(e), next(nullptr), previous(nullptr) {}

string ListNode::getUsername() {
	return username;
}

string ListNode::getName() {
	return name;
}

string ListNode::getEmail() {
	return email;
}

void ListNode::setUsername(string un) {
	username = un;
}

void ListNode::setName(string n) {
	name = n;
}

void ListNode::setEmail(string e) {
	email = e;
}

ListNode* ListNode::getNext() {
	return next;
}

ListNode* ListNode::getPrev() {
	return previous;
}

void ListNode::setNext(ListNode* nxt) {
	next = nxt;
}

void ListNode::setPrev(ListNode* prev) {
	previous = prev;
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

int List::getSize() const {
	return size;
}

void List::insert(string username, string name, string email) //Inserting at the end of the Linked List
{
	ListNode* newNode = new ListNode(username, name, email);
	ListNode* temp = head;
	bool flag = false;
	while (temp != dummyNode) {
		if (newNode->getUsername() == temp->getUsername()) {
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

void List::erase(string username)
{
	ListNode* temp = head;
	while (temp != dummyNode) {
		if (temp->getUsername() == username) {
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

ListNode* List::search(string username) const
{
	ListNode* temp = head;
	bool flag = false;
	while (temp != dummyNode) {
		if (temp->getUsername() == username)
			return temp;
		temp = temp->getNext();
	}
	return new ListNode(); //Dummy node with username = ""
}

//string List::iterator::operator*() const {
//	return string();
//}
//
//void List::iterator::operator++() {
//}
//
//void List::iterator::operator++(int) {
//}
//
//void List::iterator::operator--() {
//}
//
//void List::iterator::operator--(int) {
//}
//
//bool List::iterator::operator==(const iterator& itr) {
//	return false;
//}
//
//bool List::iterator::operator!=(const iterator& itr) {
//	return false;
//}
