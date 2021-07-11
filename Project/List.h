/*
* @author Mirette Amin Danial	20190570 S10
* @author Rana Ihab Ahmed Fahmy 20190207 S10
* Created on 9/7/2021
*/

#pragma once
#ifndef LIST_H
#define LIST_H

#include<iostream>
#include "User.h"
using namespace std;

class ListNode {
private:
	User* user;
	ListNode* next;
	ListNode* previous;
public:
	ListNode();
	ListNode(User* user);
	ListNode* getNext();
	ListNode* getPrev();
	User* getUser();
	void setNext(ListNode* nxt);
	void setPrev(ListNode* prev);
	void setUser(User* u);
};

class List {

private:
	ListNode* head, * tail, * dummyNode;
	int size;
public:
	List();
	~List();
	int getSize() const;
	void insert(User* user);
	void insert(string username, string name, string email);
	void erase(string username);
	User* search(string username) const;
};
#endif 
