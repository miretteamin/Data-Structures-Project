#include <iostream>
#include "TreapTree.h"
using namespace std;

int main()
{
	ios::sync_with_stdio(false), cin.tie(), cout.tie();
	string arr[100];
	for (int i = 0; i < 50; i++)
	{
		arr[i] = " ";
		arr[i][0] = (char)i + 48;
	}
	TreapTree t;
	for (int i = 0; i < 50; i++)
	{
		t.insert(arr + i);
	}

	t.print2D();
	cout << "====================================" << endl;
	t.deleteUser("@");
	t.print2D();


	return 0;
}