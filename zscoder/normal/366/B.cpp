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

//Codeforces Div.2 Contest 214 (A-E)

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <bool> vb;

//#define _CRT_SECURE_NO_DEPRECATE
#define forloopp(i, a, b) \
for(int i = int(a); i <= int(b); i++)
#define forloopm(i, a, b) \
for(int i = int(a); i >= int(b); i--)
#define INF 2000000000 //2 billion

//A
/*
int main()
{
	int n;
	
	cin >> n;
	
	bool already = false;
	
	int row = -1;
	int guard1 = 0, cost1 = 0, cost2 = 0;
	
	int guard2 = 0;
	int array[4][4];
	
	forloopp(i, 0, 3)
	{
		forloopp(j, 0, 3)
		{
			cin >> array[i][j];
		}
		if(!already)
		{
			if(array[i][0] + array[i][2] <= n)  
			{
				row = i + 1;
				guard1 = 0;
				guard2 = 2;
				already = true;
			}
			else if(array[i][1] + array[i][2] <= n)
			{
				row = i + 1;
				guard1 = 1;
				guard2 = 2;
				already = true;
			}
			else if(array[i][1] + array[i][3] <= n)
			{
				row = i + 1;
				guard1 = 1;
				guard2 = 3;
				already = true;
			}
			else if(array[i][0] + array[i][3] <= n)
			{
				row = i + 1;
				guard1 = 0;
				guard2 = 3;
				already = true;
			}
		}
	}
	
	cout << row << " ";
	
	//cout << guard1 << " " << guard2 << " " << endl;
	if(row != -1)
	{
		cost1 = array[row - 1][guard1];
		cost2 = array[row - 1][guard2];
		//cout << cost1 << " " << cost2 << " ";
		if(cost1 + cost2 < n)
		{
			cost2 += n - cost1 - cost2; //if less than n, we add until it's exactly n.
		}
		cout << cost1 << " " << cost2;
	}
	return 0;
}
*/

//B

int sum(int array[], int n, int k, int start)
{
	int sum = 0;
	for(int i = start; i < n; i += k)
	{
		sum += array[i];
	}
	return sum;
}

int main()
{
	//int test[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	
	//cout << sum(test, 12, 4, 2) << " ";
	int n, k;
	cin >> n >> k;
	
	int array[n];
	
	forloopp(i, 0, n - 1)
	{
		cin >> array[i];
	}
	
	//int m = n/k;
	
	int min = INF;
	int at = 1;
	int x;
	
	for(int i = 0; i < k; i++)
	{
		x = sum(array, n, k, i);
		//cout << "x at i = " << i << " equals to " << x << endl;
		if(x < min)
		{
			at = i + 1;
			min = x;
		}
	}
	
	cout << at << endl;
	return 0;
}
//*/

/*C
int main()
{
	
	return 0;
}
*/

/*D
int main()
{
	
	return 0;
}
*/

/*E
int main()
{
	
	return 0;
}
*/
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