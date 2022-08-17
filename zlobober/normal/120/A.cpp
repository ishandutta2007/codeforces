#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	int n;
	cin >> n;
	if (s == "front" && n == 1 || s == "back" && n == 2)
		cout << "L";
	else
		cout << "R";
}