# include <cstdio>
const int MN = 1e4 + 4;
bool issq[MN * MN * 2];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i)
		issq[i * i] = true;
	int res = 0;
	for (int a = 1; a <= n; ++a)
		for (int b = a + 1; b <= n; ++b)
			if (issq[a * a + b * b])
				res++;
	printf("%d\n", res);
}