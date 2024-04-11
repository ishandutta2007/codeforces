# include <cstdio>
const int inf = 1 << 28;
int che(int a, int b)
{
	if (b == 0)
	{
		if (a == 1)
			return -1;
		else
			return inf;
	}
	return (a / b) + che(b, a % b);
}
int main()
{
	int n;
	scanf("%d", &n);
	int res = inf;
	for (int i = 1; i <= n; ++i)
	{
		int x = che (i, n);
		if (x < res)
			res = x;
	}
	printf("%d\n", res);
}