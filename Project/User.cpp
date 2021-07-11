#include "User.h"

User::User(string un, string n, string e) : username(un), name(n), email(e) {}

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

