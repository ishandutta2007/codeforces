#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int k;

int main()
{
	scanf("%d", &k);

	if (k == 1)
	{
		printf("YES\n");
		printf("2 1\n");
		printf("1 2\n");
		return 0;
	}
	if (k % 2 == 0)
	{
		printf("NO\n");
		return 0;
	}

	int n = k + 2;
	int m = n * k;
	printf("YES\n");
	printf("%d %d\n", 2 * n, m);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			if (i == 1 && j == n) continue;
			if (j == i + 1 && (i & 1)) continue;
			printf("%d %d\n", i, j);
			printf("%d %d\n", n + i, n + j);
		}
	printf("1 %d\n", n + 1);

	return 0;
}