# include <cstdio>
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
const int MN = 1111;
int a[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	int k = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		if (gcd(a[i], a[i + 1]) != 1)
			k++;
	}
	printf("%d\n", k);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
		if (i != n - 1 && gcd(a[i], a[i + 1]) != 1)
			printf("1 ");
	}
}