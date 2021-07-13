#pragma once
#include <iostream>
#include "TreapTree.h"
using namespace std;

class User
{
private:
	string username, name, email;
public:
    TreapTree friends;
	User(string un, string n, string e);
	string getUsername();
	string getName();
	string getEmail();
	void setUsername(string un);
	void setName(string n);
	void setEmail(string e);
};

