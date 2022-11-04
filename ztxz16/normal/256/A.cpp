#include <stdio.h>
#include <stdlib.h>
#include <vector>

std::vector <int> x[1000005];
int tot[1000005];
int f[4005][4005];
int Ans, n, i, j, k, Now, a[4005], next[4005];

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		x[a[i]].push_back(i);
		tot[a[i]]++;
	}
	
	for (i = 1; i <= 1000000; i++)
		for (j = 0; j < tot[i] - 1; j++)
			next[x[i][j]] = x[i][j + 1];
	Ans = 1;
	for (i = n - 1; i >= 1; i --)
	{
		Now = next[i];
		for (j = i + 1; j <= n; j++)
		{
			if (Now == 0)
				f[i][j] = 2;
			else
			{
				while (Now <= j && Now != 0)
					Now = next[Now];
				if (Now == 0)
					f[i][j] = 2;
				else
					f[i][j] = f[j][Now] + 1;
			}
			
			if (f[i][j] > Ans)
				Ans = f[i][j];
		}
	}
	
	printf("%d\n", Ans);
	return 0;
}