#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define mo 1000000007

using namespace std;

long long n, i, j, s1, s2, Now, p[2005], Hash[2005], a[2005];
long long f[2005][2005];

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%I64d", &n);
	s1 = n;
	s2 = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%I64d", &a[i]);
		if (a[i] != -1)
			p[a[i]] = i, s1--;
	}
	
	Hash[0] = 1;
	for (i = 1; i <= n; i++)
	{
		if (p[i] == 0)
			continue;
		if (Hash[i] == 1)
			continue;
		Hash[i] = 1;
		Now = p[i];
		while (Hash[Now] != 1)
			Hash[Now] = 1, Now = p[Now];
		if (Now == 0)
			s2++;
	}
	
	f[0][0] = 1;
	f[1][0] = 0;
	f[2][0] = 1;
	for (i = 3; i <= n; i++)
		f[i][0] = (f[i - 1][0] + f[i - 2][0]) * (i - 1) % mo;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= i; j++)
		{
			f[i][j] = f[i - 1][j - 1] * j % mo;
			f[i][j] += f[i - 1][j] * (i - j) % mo;
			f[i][j] %= mo;
		}
	printf("%I64d\n", f[s1][s2]);
	return 0;
}