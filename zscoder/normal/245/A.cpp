#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <cstdio>
#include <stack>
#include <complex>
#include <climits>
#include <bitset>
#include <deque>
#include <set>
#include <list>
#include <valarray>
#include <functional>
#include <new>
#include <iterator>
#include <stdexcept>

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

using namespace std;

int main()
{
	int n, i;
	
	cin >> n;
	
	int array[n][3];
	
	int j;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < 3; j++)
		{
			cin >> array[i][j];
		}
	}
	
	//cout << array[n - 1][2] << endl;
	int a = 0, b = 0;
	int counta = 0, countb = 0;
	
	for(i = 0; i < n; i++)
	{
		if(array[i][0] == 1)
		{
			counta += 10;
			a += array[i][1];
		}
		else
		{
			countb += 10;
			b += array[i][1];
		}
	}
	
	//cout << counta << " " << countb << endl;
	if(a >= counta/2)
	{
		cout << "LIVE" << endl;
	}
	else
	{
		cout << "DEAD" << endl;
	}
	if(b >= countb/2)
	{
		cout << "LIVE" << endl;
	}
	else
	{
		cout << "DEAD" << endl;
	}
	return 0;
}