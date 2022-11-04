#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define MAX 1000000

using namespace std;

int Hash[MAX + 5], s[MAX + 5], i, j, a, b, k, l, r, mid;

int Check(int l);

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	Hash[1] = 1;
	for (i = 2; i * i <= MAX; i++)
	{
		if (Hash[i])
			continue;
		for (j = i * i; j <= MAX; j += i)
			Hash[j] = 1;
	}
	
	for (i = 1; i <= MAX; i++)
		s[i] = s[i - 1] + 1 - Hash[i];
	scanf("%d %d %d", &a, &b, &k);
	l = 1, r = b - a + 1;
	while (l < r)
	{
		mid = ((l + r) >> 1);
		if (Check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	
	if (Check(l))
		printf("%d\n", l);
	else
		printf("-1\n");
	return 0;
}

int Check(int l)
{
	int i;
	for (i = a; i <= b - l + 1; i++)
		if (s[i + l - 1] - s[i - 1] < k)
			return 0;
	return 1;
}