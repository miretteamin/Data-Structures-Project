#include <iostream>
#include "TreapTree.h"
#include "User.h"
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(), cout.tie();
	TreapTree t;
	for (int i = 0; i < 50; i++)
	{
		User* u = new User("", "", "");
		string s = " ";
		s[0] = (char)i + 48;
		u->setUsername(s);
		t.insert(u);
	}

	t.print2D();
	cout << "====================================" << endl;
	t.deleteUser("@");
	t.print2D();


	return 0;
}