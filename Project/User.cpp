#include "User.h"
#include "TreapTree.h"

User::User(string un, string n, string e) : username(un), name(n), email(e) {
    friends = TreapTree();
}

string 
User::getUsername() {
	return username;
}

string 
User::getName() {
	return name;
}

string 
User::getEmail() {
	return email;
}

void 
User::setUsername(string un) {
	username = un;
}

void 
User::setName(string n) {
	name = n;
}

void 
User::setEmail(string e) {
	email = e;
}

TreapTree &User::getFriends() {
    return friends;
}

