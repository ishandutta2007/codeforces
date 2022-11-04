#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

unsigned int n, k, x1, x2, x3, x4, i, j, Ans, s, a[100005], b[100005], f[50];

int main()
{
	scanf("%u %u", &n, &k);
	for (i = 1; i <= n; i++)
	{
		scanf("%u.%u.%u.%u", &x1, &x2, &x3, &x4);
		a[i] = x4 + x3 * 256 + x2 * 65536 + x1 * 16777216;
	}
	
	Ans = 0;
	f[1] = 1;
	for (i = 2; i <= 32; i++)
		f[i] = f[i - 1] + f[i - 1];
	for (i = 32; i > 1; i--)
	{
		Ans += f[i];
		for (j = 1; j <= n; j++)
			b[j] = (a[j] & Ans);
		sort(b + 1, b + n + 1);
		s = 1;
		for (j = 2; j <= n; j++)
			if (b[j] != b[j - 1])
				s++;
		if (s == k)
		{
			printf("%u.%u.%u.%u\n", Ans / 16777216, (Ans % 16777216) / 65536, (Ans % 65536) / 256, Ans % 256);
			return 0;
		}
	}
	
	printf("-1\n");
	return 0;
}