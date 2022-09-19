# include <cstdio>
const int MN = 2012;
int cou1[MN], cou2[MN];
int main()
{
	int n;
	scanf("%d", &n);
	long long res = 0;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		int a = x + y, b = x - y + 1000;
		res += cou1[a] + cou2[b];
		cou1[a] ++;
		cou2[b] ++;
	}
	printf("%I64d\n", res);
}