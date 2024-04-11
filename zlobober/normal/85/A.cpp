#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << "a\na\nb\nb\n";
		return 0;
	}
	if (n % 2)
	{
		cout << 'a';
		for (int i = 1; i < n; i++)
			cout << ((i % 4 == 1 || i % 4 == 2) ? 'b' : 'c');
		cout << endl;
		cout << 'a';
		for (int i = 1; i < n; i++)
			cout << ((i % 4 == 1 || i % 4 == 2) ? 'd' : 'e');
		cout << endl;
		for (int i = 0; i < n - 1; i++)
			cout << ((i % 4 == 0 || i % 4 == 1) ? 'f' : 'g');
		cout << "j" << endl;
		for (int i = 0; i < n - 1; i++)
			cout << ((i % 4 == 0 || i % 4 == 1) ? 'h' : 'i');
		cout << "j" << endl;
	}
	else
	{
		cout << 'a';
		for (int i = 1; i < n - 1; i++)
			cout << ((i % 4 == 1 || i % 4 == 2) ? 'b' : 'c');
		cout << "x";
		cout << endl;
		cout << 'a';
		for (int i = 1; i < n - 1; i++)
			cout << ((i % 4 == 1 || i % 4 == 2) ? 'd' : 'e');
		cout << 'x';
		cout << endl;
		
		for (int i = 0; i < n; i++)
			cout << ((i % 4 == 0 || i % 4 == 1) ? 'f' : 'g');
		cout << endl;
		for (int i = 0; i < n; i++)
			cout << ((i % 4 == 0 || i % 4 == 1) ? 'h' : 'i');
		cout << endl;
	}
}