#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
	cout << 1998 << endl;
	for(int i = 2; i <= 1000; i++)
	{
		cout << i << " " << 1 << " " << i << " " << 2 << endl;
	}
	for(int i = 1000; i >= 2; i--)
	{
		cout << i << " " << 1 << " " << i << " " << 2 << endl;
	}
	return 0;
}