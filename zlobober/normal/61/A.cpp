#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

#define HASFILES

#define TASK ""

int main(int argc, char **argv)
{
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++)
	{
		cout << ((a[i] == b[i]) ? 0 : 1);
	}
	
	
	return 0;
}