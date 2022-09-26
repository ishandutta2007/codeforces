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
	int n;
	
	cin >> n;
	
	string array[n];
	
	int i,j;
	char a;
	bool x = true;
	
	for(i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	
	int k = array[0].length();
	
	int count = 0;
	
	for(i = 0; i < k; i++)
	{
		a = array[0].at(i);
		for(j = 1; j < n; j++)
		{
			if(array[j].at(i) != a)
			{
				x = false;
				break;
			}
		}
		
		if(x)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	
	cout << count;
	return 0;
}