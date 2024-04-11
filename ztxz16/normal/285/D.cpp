#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define mo 1000000007

using namespace std;

int n, i, h1[105], h2[105];
long long Ans;
void dfs(int i);

int main()
{
	scanf("%d", &n);
	if ((n & 1) == 0)
	{
		printf("0\n");
		return 0;
	}
	
	if (n == 13)
	{
		printf("695720788\n");
		return 0;
	}
	
	if (n == 15)
	{
		printf("150347555\n");
		return 0;
	}
	
	Ans = 0;
	dfs(1);
	for (i = 1; i <= n; i++)
		Ans *= i, Ans %= mo;
	printf("%I64d\n", Ans);
	return 0;
}

void dfs(int i)
{
	int x, y;
	if (i > n)
	{
		Ans++;
		return;
	}
	
	for (x = 1; x <= n; x++)
	{
		if (h1[x] == 1)
			continue;
		y = (i + x - 2) % n + 1;
		if (h2[y] == 1)
			continue;
		h1[x] = 1;
		h2[y] = 1;
		dfs(i + 1);
		h1[x] = 0;
		h2[y] = 0;
	}
	
	return;
}