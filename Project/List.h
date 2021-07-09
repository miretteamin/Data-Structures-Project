/*
* @author Mirette Amin Danial	20190570 S10
* @author Rana Ihab Ahmed Fahmy 20190207 S10
* Created on 9/7/2021
*/

#pragma once
#ifndef LIST_H
#define LIST_H

#include<iostream>
using namespace std;

class ListNode {
private:
	string username, name, email;
	ListNode* next;
	ListNode* previous;
public:
	ListNode();
	ListNode(string un, string n, string e);
	string getUsername();
	string getName();
	string getEmail();
	void setUsername(string un);
	void setName(string n);
	void setEmail(string e);
	ListNode* getNext();
	ListNode* getPrev();
	void setNext(ListNode* nxt);
	void setPrev(ListNode* prev);
};

class List {

private:
	ListNode* head, * tail, * dummyNode;
	int size;
public:
	List();
	//List(int init_size);
	~List();
	int getSize() const;
	//List& operator= (const List& another_list);

	//class iterator {
	//private:
	//	ListNode* node;
	//	iterator();
	//	iterator(ListNode* newNode);
	//public:
	//	friend class MyList;
	//	string operator*() const;
	//	void operator++();
	//	void operator++(int);
	//	void operator-- ();
	//	void operator-- (int);
	//	bool operator== (const iterator& itr);
	//	bool operator!= (const iterator& itr);
	//};

	/*iterator begin() const {
		return iterator(head);
	}

	iterator end() const {
		return iterator(dummyNode);
	}*/

	void insert(string username, string name, string email);

	void erase(string username);

	ListNode* search(string username) const;

};
#endif 
