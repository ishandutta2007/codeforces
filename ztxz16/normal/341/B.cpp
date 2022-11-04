#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, i, x, f[100005], Ans;
int A[100005];

void Add(int a, int b);
int Ask(int a);

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		f[x] = Ask(x - 1) + 1;
		Add(x, f[x]);
		if (f[x] > Ans)
			Ans = f[x];
	}
	
	printf("%d\n", Ans);
	return 0;
}

void Add(int a, int b)
{
	int i;
	for (i = a; i <= n; i += (i & (0 - i)))
		if (b > A[i])
			A[i] = b;
	return;
}

int Ask(int a)
{
	int ret = 0, i;
	for (i = a; i > 0; i -= (i & (0 - i)))
		if (A[i] > ret)
			ret = A[i];
	return ret;
}