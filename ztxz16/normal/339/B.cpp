#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long n, m, i, Now, x, Ans;

int main()
{
	scanf("%I64d %I64d", &n, &m);
	Now = 1;
	for (i = 1; i <= m; i++)
	{
		scanf("%I64d", &x);
		if (x >= Now)
			Ans += (x - Now);
		else
			Ans += (n - Now + x);
		Now = x;
	}
	
	printf("%I64d\n", Ans);
	return 0;
}