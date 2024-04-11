#include <bits/stdc++.h>
using namespace std;

const int Maxn = 305;
int T, n, k;
bool a[Maxn][Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		if (!k)
		{
			puts("0");
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
					putchar('0');
				puts("");
			}
			continue;
		}
		int tmp_k = k;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				a[i][j] = 0;
		for (int i = 1; i <= n; i++)
		{
			int pos = i;
			for (int j = 1; j <= n; j++)
			{
				a[j][pos] = true, pos = pos % n + 1, tmp_k--;
				if (!tmp_k) goto A;
			}
		}
		A:if (k % n == 0) puts("0");
		else puts("2");
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				putchar(a[i][j] + '0');
			puts("");
		}
	}
	return 0;
}