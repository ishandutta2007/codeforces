#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long n, k, i, tot, now, Now, x;

int main()
{
	scanf("%I64d %I64d", &n, &k);
	tot = 0;
	now = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%I64d", &x);
		Now = now - tot * (n - i) * x;
		if (Now < k)
			cout << i << endl;
		else
			tot++, now += (x * (tot - 1));
	}
	
	return 0;
}