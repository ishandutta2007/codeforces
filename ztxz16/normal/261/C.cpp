#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

long long n, t, i, j, tag = 0, x[65], Ans, f[65][65];

int main()
{
	scanf("%I64d %I64d", &n, &t);
	x[0] = 1;
	for (i = 1; i <= 60; i++)
		x[i] = x[i - 1] + x[i - 1];
	for (i = 0; i <= 60; i++)
		if (x[i] == t)
			tag = i + 1;
	if (tag == 0 || t == 0)
		printf("0\n");
	else
	{
		n += 2;
		for (i = 2; i <= 60; i++)
			for (j = 0; j < i; j++)
			{
				f[i][j] = f[i - 1][j];
				if (j <= 1)
					f[i][j]++;
				if (j != 0)
					f[i][j] += f[i - 1][j - 1];
			}
		for (i = 60; i >= 0; i--)
		{
			if (x[i] <= n)
			{
				Ans += f[i][tag - 1];
				n -= x[i];
				if (n >= 1 && tag == 1)
					Ans++;
				if (n >= 2 && tag == 2)
					Ans++;
				tag--;
				if (n <= 0 || tag == 0)
					break;
			}
		}
		
		printf("%I64d\n", Ans);
	}
	
	return 0;
}