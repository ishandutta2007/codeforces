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
#include <cstddef>
#include <fstream>

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

using namespace std;
/* A
int main()
{
	int array[5][5];
	int count = 0;
	int x, y;
	
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			cin >> array[i][j];
			if(array[i][j] == 1)
			{
				x = i + 1;
				y = j + 1;
			}
		}
	}
	
	count = abs(3 - x) + abs(3 - y);
	cout << count;
	return 0;
}*/

int main()
{
	vector <int> vec;
	int n, k;
	cin >> n >> k;
	int x;
	
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		vec.push_back(x);
	}
	
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	
	if(k > n)
	{
		cout << -1;
	}
	else
	{
		cout << vec.at(k - 1) << " " << 0;
	}
	return 0;
}

/* Copy and paste if you want to avoid typing.
	
	int i; //for loops
	int count = 0; //for answers
	int array[m][n];

	for(i = ; i  ; i  )
	{

	}

	if()
	{

	}
	else
	{

	}

	if()
	{

	}
	else if()
	{

	}
	else
	{
	
	}
*/

/*	Algorithms
	sort(vec.begin(), vec.end());
	string.at();
*/