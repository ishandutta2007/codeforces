#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define PQ priority_queue
#define OO 2147483647

using namespace std;

long long a, b;

long long dfs(long long a, long long b);

int main()
{
	cin >> a >> b;
	cout << dfs(a, b) << endl;
	return 0;
}

long long dfs(long long a, long long b)
{
	if (a == 0 || b == 0)
		return 0;
	if (a >= b)
		return a / b + dfs(a % b, b);
	else
		return b / a + dfs(b % a, a);
}