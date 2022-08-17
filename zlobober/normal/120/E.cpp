#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	int n;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << !(n % 2) << endl;
	}
}