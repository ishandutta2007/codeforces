# include <cstdio>
# include <cstdlib>
int n;
const int MN = 6005;
const int MS = MN * (MN + 1) / 2;
bool prime[MS];
int arr[MN];
void solve(int a, int b, int c, int nr)
{
	if (a < 0 || b < 0 || c < 0)
		return;
	if (nr == 0)
	{
		for (int i = 1; i <= n; ++i)
			printf("%d ", arr[i]);
		printf("\n");
		exit(0);
	}
	arr[nr] = 1;
	solve(a - nr, b, c, nr - 1);
	arr[nr] = 2;
	solve(a, b - nr, c, nr - 1);
	arr[nr] = 3;
	solve(a, b, c - nr, nr - 1);
}
int main()
{
	for (int i = 2; i < MS; ++i)
		prime[i] = true;
	for (int p = 2; p < MS; ++p)
		if (prime[p])
			for (int x = p * 2; x < MS; x += p)
				prime[x] = false;
	scanf("%d", &n);
	if (n == 1)
	{
		printf("-1\n");
		return 0;
	}
	int aim = n * (n + 1) / 2;
	if (prime[aim])
	{
		for (int i = 0; i < n; ++i)
			printf("1 ");
		printf("\n");
		return 0;
	}
	for (int p = 2; p < aim; ++p)
		if (prime[p] && prime[aim - p])
			solve(p, aim - p, 0, n);
	for (int p = 2; p < MN; ++p)
		if (prime[p])
			for (int q = 3; p + q < aim; ++q)
				if (prime[q] && prime[aim - p - q])
					solve(p, q, aim - p - q, n);
}