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
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <bool> vb;

#define forloopp(i, a, b) \
for(int i = int(a); i <= int(b); i++)
#define forloopm(i, a, b) \
for(int i = int(a); i >= int(b); i--)
#define INF INT_MAX

//Tip for reading input : scanf("%s%d", &s, &d);!

//A
/*
int main()
{
	int n; 
	cin >> n;
	int home[n];
	int away[n];
	int i;
	for(i = 0; i < n; i++)
	{
		cin >> home[i];
		cin >> away[i];
	}
	int j, count = 0;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(i != j)
			{
				if(home[i] == away[j])
				{
					//cout << i + 1 << " vs " << j + 1 << " : Same shirt encountered." << endl;
					count++;
				}
				if(away[i] == home[j])
				{
					//cout << j + 1 << " vs " << i + 1 << " : Same shirt encountered." << endl;
					count++;
				}
			}
		}
	}
	count /= 2;
	cout << count;
	return 0;
}*/

//B
int g(int n)
{
	if(n > 1)
	{
		return n - 1 + g(n - 1);
	}
	else
	{
		return 0; 
	}
}

int f(int n)
{
	if(n > 1)
		return n + g(n - 1) + f(n - 1);
	else
		return 1;
}

int main()
{
	int n;
	cin >> n;
	cout << f(n);
	return 0;
}


//C
/*
int main()
{
	return 0;
}
*/

//D
/*
int main()
{
	return 0;
}
*/

//E
/*
int main()
{
	return 0;
}
*/