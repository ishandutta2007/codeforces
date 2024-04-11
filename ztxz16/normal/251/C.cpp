#include <stdio.h>
#include <stdlib.h>
#define X 360360
#define ll long long

ll a, b, k, h, t, Now, i, j;
ll List[2000005], Step[2000005];
char hash[2000005];

void Check(ll xx);

int main()
{
	scanf("%I64d %I64d %I64d", &a, &b, &k);
	a -= (b - b % X);
	b %= X;
	List[1] = b;
	Step[b] = 0;
	for (h = t = 1; h <= t; h++)
	{
		Now = List[h];
		hash[Now] = 0;
		Check(Now + 1);
		for (i = 2; i <= k; i++)
			if ((Now % i) == 0)
				for (j = 1; j < i; j++)
					Check(Now + j);
	}
	
	if (a <= b + 4 * X)
		printf("%I64d\n", Step[a]);
	else
	{
		for (i = b + 1; i <= b + X; i++)
			if (a % X == i % X)
			{
				printf("%I64d\n", Step[i + X] + (a - i - X) / X * (Step[i + 2 * X] - Step[i + X]));
				return 0;
			}
	}
	
	/*for (i = b + 1; i <= b + X; i++)
		if (Step[i + 3 * X] - Step[i + 2 * X] != Step[i + 2 * X] - Step[i + X])
			printf("-1\n");*/
	
	return 0;
}

void Check(ll xx)
{
	if (xx > b + 4 * X)
		return;
	if (Step[xx] != 0 && Step[Now] + 1 >= Step[xx])
		return;
	Step[xx] = Step[Now] + 1;
	if (hash[xx] == 0)
		List[++t] = xx, hash[xx] = 1;
	return;
}