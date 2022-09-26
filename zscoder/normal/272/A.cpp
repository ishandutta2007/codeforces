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
int remain(int x, int y)
{
	if(x % y == 0)
	{
		return y;
	}
	else
	{
		return x % y;
	}
}

int main()
{
	int n;
	cin >> n;
	int array[n];
	int i;
	int sum = 0; 
	for(i = 0; i < n; i++)
	{
		cin >> array[i];
		sum += array[i];
	}
	//int counter = 1;
	int count = 0;
	for(i = 1; i <= 5; i++)
	{
		if((sum + i)%(n+1) != 1)
			count++;
	}
	cout << count;
	return 0;
}

//B
/*
int main()
{
	return 0;
}
*/

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