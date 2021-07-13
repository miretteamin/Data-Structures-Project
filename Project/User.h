#pragma once
#include <iostream>
#include "TreapTree.h"
using namespace std;

class User
{
private:
	string username, name, email;
    TreapTree friends;
public:
	User(string un, string n, string e);
	string getUsername();
	string getName();
	string getEmail();
    TreapTree & getFriends();
	void setUsername(string un);
	void setName(string n);
	void setEmail(string e);
};

